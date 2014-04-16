/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <iostream>
#include <math.h>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "core/base/KeyValueConfiguration.h"
#include "core/data/Container.h"
#include "core/data/Constants.h"
#include "core/data/image/SharedImage.h"
#include "core/data/control/VehicleControl.h"
#include "core/io/ContainerConference.h"
#include "core/wrapper/SharedMemoryFactory.h"

// Data structures from msv-data library:
#include "SteeringData.h"

#include "LaneDetector.h"

#define 	IMG_WIDTH 		640
#define 	IMG_HEIGHT 		480
#define 	IMG_MIDDLE_X	IMG_WIDTH / 2
#define 	ROI_WIDTH		320
#define 	ROI_HEIGHT 		160
#define		ROI_STOP_WIDTH	125
#define		ROI_STOP_HEIGHT	50	


/*
 Get x-value of the intersection of a line and y = (image_height - offset_from_bottom).
*/
int getXValue(int x1, int y1, int x2, int y2) {
	double m = ((y1 - y2) * 1.0) / (x1 - x2);
	double b = y1 - (m * x1);
	int x_val = ((IMG_HEIGHT - ROI_HEIGHT) - b) / m;

	return x_val;
}


/*
Calculating the x-coordinate of the 'midpoint' that lies between two lines.
*/
int getMidPoint(int left_x, int right_x) {
    
    int middle_x = ((right_x - left_x) / 2.0) + left_x;
    return middle_x;
}


/*
Calculating the angle from the position of the car to the 'midpoint'. 

The y-position of the car is the same as 'image_height'.
*/
double getAngle(int mid_x, int b, int car_x) {
    double a = abs(car_x - mid_x);

    double theta_radians = atan(a * 1.0 / b * 1.0);
    // int theta_degrees = (360.0 / (2 * CV_PI)) * theta_radians;
    
    if (car_x < mid_x) return -theta_radians;
    else return theta_radians;
}


namespace msv {

    using namespace std;
    using namespace cv;
    using namespace core::base;
    using namespace core::data;
    using namespace core::data::control;
    using namespace core::data::image;


	bool firstFrame = true;
	//int carSpeed = 1.5;
    double lastSteerAngle;

	Point stopROITopLeft = Point(IMG_MIDDLE_X - (ROI_STOP_WIDTH / 2), IMG_HEIGHT / 2 + 50);
    Point stopROITopRight = Point(IMG_MIDDLE_X + (ROI_STOP_WIDTH / 2), IMG_HEIGHT / 2 + 50);
    Point stopROIBottomLeft = Point(IMG_MIDDLE_X - (ROI_STOP_WIDTH / 2), IMG_HEIGHT / 2 + ROI_STOP_HEIGHT + 50);
    Point stopROIBottomRight = Point(IMG_MIDDLE_X + (ROI_STOP_WIDTH / 2), IMG_HEIGHT / 2 + ROI_STOP_HEIGHT + 50);



    LaneDetector::LaneDetector(const int32_t &argc, char **argv) : ConferenceClientModule(argc, argv, "lanedetector"),
    	left_x(0),
    	right_x(0),
    	center(0),
        m_hasAttachedToSharedImageMemory(false),
        m_sharedImageMemory(),
        m_image(NULL),
        m_cameraId(-1),
        m_debug(false) {}

    LaneDetector::~LaneDetector() {}

    int LaneDetector::getLeft_x() {
    	return left_x;
    }
    int LaneDetector::getRight_x() {
    	return right_x;
    }
    int LaneDetector::getCenter() {
    	return center;
    }

    void LaneDetector::setUp() {
	    // This method will be call automatically _before_ running body().
	    if (m_debug) {
		    // Create an OpenCV-window.
		    cvNamedWindow("WindowShowImage", CV_WINDOW_AUTOSIZE);
		    cvMoveWindow("WindowShowImage", 300, 100);
	    }
    }

    void LaneDetector::tearDown() {
	    // This method will be call automatically _after_ return from body().
	    if (m_image != NULL) {
		    cvReleaseImage(&m_image);
	    }

	    if (m_debug) {
		    cvDestroyWindow("WindowShowImage");
	    }
    }

    bool LaneDetector::readSharedImage(Container &c) {
	    bool retVal = false;

	    if (c.getDataType() == Container::SHARED_IMAGE) {
		    SharedImage si = c.getData<SharedImage> ();

		    // Check if we have already attached to the shared memory.
		    if (!m_hasAttachedToSharedImageMemory) {
			    m_sharedImageMemory
					    = core::wrapper::SharedMemoryFactory::attachToSharedMemory(
							    si.getName());
		    }

		    // Check if we could successfully attach to the shared memory.
		    if (m_sharedImageMemory->isValid()) {
			    // Lock the memory region to gain exclusive access. REMEMBER!!! DO NOT FAIL WITHIN lock() / unlock(), otherwise, the image producing process would fail.
			    m_sharedImageMemory->lock();
			    {
				    const uint32_t numberOfChannels = 3;
				    // For example, simply show the image.
				    if (m_image == NULL) {
					    m_image = cvCreateImage(cvSize(si.getWidth(), si.getHeight()), IPL_DEPTH_8U, numberOfChannels);
				    }

				    // Copying the image data is very expensive...
				    if (m_image != NULL) {
					    memcpy(m_image->imageData,
							   m_sharedImageMemory->getSharedMemory(),
							   si.getWidth() * si.getHeight() * numberOfChannels);
				    }
			    }

			    // Release the memory region so that the image produce (i.e. the camera for example) can provide the next raw image data.
			    m_sharedImageMemory->unlock();

			    // Mirror the image.
			    cvFlip(m_image, 0, -1);

			    retVal = true;
		    }
	    }
	    return retVal;
    }

    // You should start your work in this method.
    void LaneDetector::processImage() {

        // Example: Show the image.
        if (m_debug) {
            if (m_image != NULL) {
                // cvShowImage("WindowShowImage", m_image);
                // cvWaitKey(10);
            }
        }

        // 1. Do something with the image m_image here, for example: find lane marking features, optimize quality, ...
        
        Mat src, left_roi, right_roi, stop_roi, src_gray, threshold_output;

 		src = cvarrToMat(m_image, true);

        if(src.data == NULL) {
        	cerr << "ERROR!" << endl;
        	return;
        }
 
        
	    /// Detect edges using Threshold
	    // threshold( src_gray, threshold_output, 180, 255, THRESH_BINARY );

        /// Convert image to gray
    	cvtColor( src, src_gray, CV_BGR2GRAY );

    	/// Detect edges using Threshold
    	// !!This might not be a necessary step
    	threshold( src_gray, threshold_output, 180, 255, THRESH_BINARY );

	    /// Select Regions of Interest
	    left_roi = threshold_output(Rect(0, IMG_HEIGHT - ROI_HEIGHT, ROI_WIDTH, ROI_HEIGHT));
	    right_roi = threshold_output(Rect(IMG_WIDTH - ROI_WIDTH, IMG_HEIGHT - ROI_HEIGHT, ROI_WIDTH, ROI_HEIGHT));
	    stop_roi = threshold_output(Rect(stopROITopLeft.x, stopROITopLeft.y, ROI_STOP_WIDTH, ROI_STOP_HEIGHT));

	    /*
	    test values for stopline ROI size
	    
		line(src, stopROITopLeft, stopROITopRight, Scalar( 255, 0, 100 ), 2, 8);
		line(src, stopROITopRight, stopROIBottomRight, Scalar( 255, 0, 100 ), 2, 8);
		line(src, stopROIBottomRight, stopROIBottomLeft, Scalar( 255, 0, 100 ), 2, 8);
		line(src, stopROIBottomLeft, stopROITopLeft, Scalar( 255, 0, 100 ), 2, 8);

		*/



		// The output of HoughLinesP is stored in vectors of lines represented as two points(x1, y1; x2, y2).
		// We do Hough lines on each of the ROI

	    vector<Vec4i> left_lines;
	    HoughLinesP(left_roi, left_lines, 1, CV_PI/180, 20, 20, 100);

	    vector<Vec4i> right_lines;
	    HoughLinesP(right_roi, right_lines, 1, CV_PI/180, 20, 20, 100);

	    vector<Vec4i> stop_lines;
	    HoughLinesP(stop_roi, stop_lines, 1, CV_PI/180, 20, 20, 100);


	    // Try to detect the stop line before an intersections. 
	    // What we're looking for is a line which is horizontal( > 50 pixels on the y axis 
	    // and the height should not be greater than 10)

	    /*---------------------------------------------------------------*/
	    // Added by Patrik. Values is sent to SteeringData later on
	    bool stopLineDetected = false;
	    double leftLineAngle;
	    /*---------------------------------------------------------------*/
	    if (stop_lines.size() > 0) {
	    	if (abs(stop_lines[0][1] - stop_lines[0][3]) < 10 && abs(stop_lines[0][0] - stop_lines[0][2]) > 50)
	    		cout << "STOP!....." << stop_lines.size() << endl;
	    		/*-----------------------------------------------------------*/
	    		// Added by Patrik. bool is sent to SteeringData later on.
	    		stopLineDetected = true;
	    		/*-----------------------------------------------------------*/
	    		//carSpeed = 0.0;
	    }

	    // New value for setting the steering wheel angle.
		double steerAngle = 0.0;

		// Make sure the hough lines algorithms have detected something in both the left and right ROI's
		// if not we move straight forward.
		if(left_lines.size() > 1 && right_lines.size() > 1) {
		    
			// This next part finds the top lines in each ROI(left and right)
		    Point leftLaneTop = Point(left_lines[0][2], left_lines[0][3]);
		    Point leftLaneBottom = Point(left_lines[0][0], left_lines[0][1]);
		    Point rightLaneTop = Point(right_lines[0][2], right_lines[0][3]);
		    Point rightLaneBottom = Point(right_lines[0][0], right_lines[0][1]);
		    
		    for( size_t i = 0; i < left_lines.size(); i++ ) {
		      	if (left_lines[i][3] < leftLaneTop.y) { 
		            leftLaneTop = Point(left_lines[i][2], left_lines[i][3]);
		            leftLaneBottom = Point(left_lines[i][0], left_lines[i][1]);
		        }
		    }

		    for( size_t i = 0; i < right_lines.size(); i++ ) {
		      	if (right_lines[i][1] < rightLaneTop.y) { 
		            rightLaneTop = Point(right_lines[i][2], right_lines[i][3]);
		            rightLaneBottom = Point(right_lines[i][0], right_lines[i][1]);
		        }
		    }


		    // Make some calculations to get the center of the lane at y = IMG_HEIGHT - ROI_HEIGHT (top of the ROI)
		    int xOffset = IMG_WIDTH - ROI_WIDTH;
		    int yOffset = IMG_HEIGHT - ROI_HEIGHT;

		    left_x = getXValue( leftLaneTop.x, leftLaneTop.y + yOffset, 
		    						leftLaneBottom.x, leftLaneBottom.y + yOffset);

		    /*---------------------------------------------------------------*/
		    // Added by Patrik. Calculating the angle of the left line
		    leftLineAngle = (atan2((leftLaneTop.y-leftLaneBottom.y), (leftLaneTop.x - leftLaneBottom.x)) * (180 / CV_PI));
		    /*---------------------------------------------------------------*/

		    right_x = getXValue(rightLaneTop.x + xOffset, rightLaneTop.y + yOffset, 
		    						rightLaneBottom.x + xOffset, rightLaneBottom.y + yOffset);

		    center = getMidPoint(left_x, right_x);

		    steerAngle = getAngle(IMG_MIDDLE_X, IMG_HEIGHT - ROI_HEIGHT, center);


		    // In intersections houghlines will detect the lanes of the crossing road.
		    // In order to not steer towards those lines we compare the angle of the current line 
		    // with the angle of the last line(from last frame)
		    if(firstFrame) {
		    	lastSteerAngle = steerAngle;
		    	firstFrame = false;
		    }

		    if (steerAngle < lastSteerAngle - 8 * (CV_PI / 180) || steerAngle > lastSteerAngle + 8 * (CV_PI / 180) ) {
		    	steerAngle = lastSteerAngle;
		    }
		    lastSteerAngle = steerAngle;
		    

		    // Draw circles on left and right lane top  points as well as the center point.
			circle(src, Point(leftLaneTop.x, leftLaneTop.y + IMG_HEIGHT - ROI_HEIGHT - 5), 10, Scalar(0, 0, 255), 3);
		    circle(src, Point(IMG_WIDTH - ROI_WIDTH + rightLaneTop.x, IMG_HEIGHT - ROI_HEIGHT + rightLaneTop.y), 10, Scalar(255, 0, 0), 3);
			circle(src, Point(center, IMG_HEIGHT - ROI_HEIGHT), 10, Scalar(0, 255, 0), 3);

			// line(src, Point(leftLaneTop.x, IMG_HEIGHT - ROI_HEIGHT + leftLaneTop.y), Point(leftLaneBottom.x, IMG_HEIGHT - ROI_HEIGHT + leftLaneBottom.y), Scalar( 255, 0, 100 ), 2, 8);
		}

		/*---------------------------------------------------------------*/
		// Added by Patrik. This is the data sent to SteeringData, which in turn enables it in the Driver (and other) module. This is to prevent LaneDetector to take care of the driving and steering, which could give huge problems when intergrating all modules!

		cout << "--------------------------------------\nSteering angle: " << steerAngle << "\nLeft line distance: " << left_x << "\nLeft line angle: " << leftLineAngle << "\nStop line detected: " << stopLineDetected << endl;

        double 	left_x_to_double = left_x,
        		center_to_double = center;
        		//right_x_to_double = right_x;

        SteeringData sd;
        sd.setSteeringAngle(steerAngle);
        sd.setLeftLineDistance(left_x_to_double);
        sd.setCenterDistance(center_to_double);
        sd.setLeftLineAngle(leftLineAngle);
        sd.setStopLineDetected(stopLineDetected);
        Container c(Container::USER_DATA_1, sd);
        getConference().send(c);
        /*---------------------------------------------------------------*/
		
		// }
        	    /// Create Window
	    namedWindow("Lane Detect Window", CV_WINDOW_AUTOSIZE );
	    imshow("Lane Detect Window", src );

	    /*
	    namedWindow("asdf", CV_WINDOW_AUTOSIZE );
	    imshow("asdf", left_roi_threshold);
		
		namedWindow("asdf2", CV_WINDOW_AUTOSIZE );
	    imshow("asdf2", right_roi_threshold);
		*/

    	cvWaitKey(1);
    }

    // This method will do the main data processing job.
    // Therefore, it tries to open the real camera first. If that fails, the virtual camera images from camgen are used.
    ModuleState::MODULE_EXITCODE LaneDetector::body() {
	    // Get configuration data.
	    KeyValueConfiguration kv = getKeyValueConfiguration();
	    m_cameraId = kv.getValue<int32_t> ("lanedetector.camera_id");
	    m_debug = kv.getValue<int32_t> ("lanedetector.debug") == 1;

	    bool use_real_camera = true;

	    // Try to open the camera device.
	    CvCapture *capture = cvCaptureFromCAM(m_cameraId);
	    if (!capture) {
		    cerr << "Could not open real camera; falling back to SHARED_IMAGE." << endl;
		    use_real_camera = false;
	    }

	    while (getModuleState() == ModuleState::RUNNING) {
		    bool has_next_frame = false;

		    // Use the shared memory image.
		    if (!use_real_camera) {
			    // Get the most recent available container for a SHARED_IMAGE.
			    Container c = getKeyValueDataStore().get(Container::SHARED_IMAGE);

			    if (c.getDataType() == Container::SHARED_IMAGE) {
				    // Example for processing the received container.
				    has_next_frame = readSharedImage(c);
			    }
		    } else {
			    // Use the real camera.
			    if (cvGrabFrame(capture)) {
				    m_image = cvRetrieveFrame(capture);
				    has_next_frame = true;
			    }
		    }

		    // Process the read image.
		    if (true == has_next_frame) {
			    processImage();
		    }

		    if (use_real_camera) {
			    // Unset m_image only for the real camera to avoid memory leaks.
			    m_image = NULL;
		    }
	    }

	    if (capture != NULL) {
		    cvReleaseCapture(&capture);
	    }

	    return ModuleState::OKAY;
    }

} // msv

