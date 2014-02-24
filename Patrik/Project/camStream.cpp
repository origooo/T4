#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <math.h>
 
using namespace std;
using namespace cv;

int main() {
    
    /**************************************
    Always needed
    **************************************/
    char key;
    cvNamedWindow("Camera_Output", 1);
    CvCapture* capture = cvCaptureFromCAM(CV_CAP_ANY);

    /**************************************
    Needed for Houghlines
    **************************************/
    IplImage* img;
    IplImage* dst;
    IplImage* color_dst;
    CvMemStorage* storage;
    CvSeq* lines;

    /**************************************
    Needed for Grayscale to Threshold
    **************************************/
    // IplImage* img;
    // IplImage* grayImg;
    // IplImage* thresholdedImg;
    // int binThreshold = 127;

    while(1) {

        /**************************************
        Always needed
        **************************************/

        img = cvQueryFrame(capture);
        
        /**************************************
        Needed for Houghlines
        **************************************/
        int i;
        storage = cvCreateMemStorage(0);
        lines = 0;
        dst = cvCreateImage(cvGetSize(img), 8, 1);
        color_dst = cvCreateImage(cvGetSize(img), 8, 3);

        cvCanny(img, dst, 50, 200, 3);
        cvCvtColor(dst, color_dst, CV_GRAY2BGR);

        #if 0
            lines = cvHoughLines2( dst, storage, CV_HOUGH_STANDARD, 1, CV_PI/180, 100, 0, 0 );

            for( i = 0; i < MIN(lines->total,100); i++ ) {
                float* line = (float*)cvGetSeqElem(lines,i);
                float rho = line[0];
                float theta = line[1];
                CvPoint pt1, pt2;
                double a = cos(theta), b = sin(theta);
                double x0 = a*rho, y0 = b*rho;
                pt1.x = cvRound(x0 + 1000*(-b));
                pt1.y = cvRound(y0 + 1000*(a));
                pt2.x = cvRound(x0 - 1000*(-b));
                pt2.y = cvRound(y0 - 1000*(a));
                cvLine( color_dst, pt1, pt2, CV_RGB(255,0,0), 3, CV_AA, 0 );
            }
        #else
            lines = cvHoughLines2( dst, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI/180, 50, 50, 10 );
            for( i = 0; i < lines->total; i++ ) {
                CvPoint* line = (CvPoint*)cvGetSeqElem(lines,i);
                cvLine( color_dst, line[0], line[1], CV_RGB(255,0,0), 3, CV_AA, 0 );
            }
        #endif

        cvShowImage("Camera_Output", color_dst);

        /**************************************
        Needed for Grayscale to Threshold
        **************************************/

        // thresholdedImg = cvCreateImage(cvSize(img->width,img->height), img->depth, 1);
        // thresholdedImg->origin = img->origin;

        // grayImg = cvCreateImage(cvSize(img->width,img->height), img->depth, 1);
        // grayImg->origin = img->origin;

        // if (img->nChannels > 1){
        //     cvCvtColor(img, grayImg, CV_BGR2GRAY);
        // } else {
        //     grayImg = img;
        // }

        // cvThreshold(grayImg, thresholdedImg, binThreshold, 255,CV_THRESH_BINARY);

        // cvShowImage("Camera_Output", thresholdedImg);

        /**************************************
        Always needed
        **************************************/

        key = cvWaitKey(10);
        for (int i = 0; i < 100; i++);
        if (char(key) == 27){
            break;
        }
    }
    cvReleaseCapture(&capture);
    cvDestroyWindow("Camera_Output");
    return 0;
}