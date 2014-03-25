/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <stdio.h>
#include <math.h>
#include <unistd.h>

#include "core/io/ContainerConference.h"
#include "core/data/Container.h"
#include "core/data/Constants.h"
#include "core/data/control/VehicleControl.h"


// Data structures from msv-data library:
#include "SteeringData.h"
#include "SensorBoardData.h"
#include "UserButtonData.h"

#include "Driver.h"

namespace msv {

        using namespace std;
        using namespace core::base;
        using namespace core::data;
        using namespace core::data::control;
        using namespace core::data::environment;

        Driver::Driver(const int32_t &argc, char **argv) :
	        ConferenceClientModule(argc, argv, "Driver") {
        }

        Driver::~Driver() {}

        void Driver::setUp() {
	        // This method will be call automatically _before_ running body().
        }

        void Driver::tearDown() {
	        // This method will be call automatically _after_ return from body().
        }

        // This method will do the main data processing job.
        ModuleState::MODULE_EXITCODE Driver::body() {

	        while (getModuleState() == ModuleState::RUNNING) {
                // In the following, you find example for the various data sources that are available:

		        // 1. Get most recent vehicle data:
		        Container containerVehicleData = getKeyValueDataStore().get(Container::VEHICLEDATA);
		        VehicleData vd = containerVehicleData.getData<VehicleData> ();
		        cerr << "Most recent vehicle data: '" << vd.toString() << "'" << endl;

		        // 2. Get most recent sensor board data:
		        Container containerSensorBoardData = getKeyValueDataStore().get(Container::USER_DATA_0);
		        SensorBoardData sbd = containerSensorBoardData.getData<SensorBoardData> ();
		        cerr << "Most recent sensor board data: '" << sbd.toString() << "'" << endl;

		        // 3. Get most recent user button data:
		        Container containerUserButtonData = getKeyValueDataStore().get(Container::USER_BUTTON);
		        UserButtonData ubd = containerUserButtonData.getData<UserButtonData> ();
		        cerr << "Most recent user button data: '" << ubd.toString() << "'" << endl;

		        // 4. Get most recent steering data as fill from lanedetector for example:
		        Container containerSteeringData = getKeyValueDataStore().get(Container::USER_DATA_1);
		        SteeringData sd = containerSteeringData.getData<SteeringData> ();
		        cerr << "Most recent steering data: '" << sd.toString() << "'" << endl;


		        //Approach parking
		        //approachParking(vd);
		        findParkingSpot(vd);
                // Design your control algorithm here depending on the input data from above.
		        practiceParking(vd);
		        exit(0);
	        }

	        return ModuleState::OKAY;
        }

        void Driver::approachParking(VehicleData& vd) {

        	//31 - Distance to start turning.
        	std::cout << "Approaching" << std::endl;

        	while(true) {

        		VehicleControl vc;
        		vc.setSpeed(1);
                double desiredSteeringWheelAngle = 0; 

        		Container containerVehicleData = getKeyValueDataStore().get(Container::VEHICLEDATA);
		    	vd = containerVehicleData.getData<VehicleData> ();

		    	std::cout << "Abs Traveled path" << vd.getAbsTraveledPath() << std::endl;

		    	//Reached line.
		    	if(vd.getAbsTraveledPath() >= 46) {
		    		return;
		    	}

		    	//Reached corner
		        else if(vd.getAbsTraveledPath() > 42.5) {

		        	vc.setSpeed(1);
                	desiredSteeringWheelAngle = 0; 
                	//Dont know if setting the heading does anything.
		    		vd.setHeading(0.0);

		        }

		        //Not reached corner yet.
		        else if(vd.getAbsTraveledPath() > 31) {

		        	vc.setSpeed(1);
                	desiredSteeringWheelAngle = 20; 

		        }

		        vc.setSteeringWheelAngle(desiredSteeringWheelAngle * Constants::DEG2RAD);
		       	Container c(Container::VEHICLECONTROL, vc);
		        getConference().send(c);
        	}
        }

        void Driver::practiceParking(VehicleData& vd) {

        	std::cout << "Starting parking routine" << std::endl;

        	bool parking = true;
        	int count = 0;

        	Container containerVehicleData = getKeyValueDataStore().get(Container::VEHICLEDATA);
		    vd = containerVehicleData.getData<VehicleData> ();

        	//Used later
		    VehicleControl vc;
            double desiredSteeringWheelAngle = 0;

        	while(parking && count < 11) {

        		vc.setSpeed(0);
		    	sleep(2.5);

		    	//Go forwards a little to allow for parking
				if(count < 2) {
                	desiredSteeringWheelAngle = -10; 
                	vc.setSpeed(1);
			    }

			    //Reverse backwards with wheels right
			    else if(count < 6) {
                	desiredSteeringWheelAngle = 25; 
                	vc.setSpeed(-1);
			    }

			    //Go fowards a little to the right
			    else if(count < 8) {
                	desiredSteeringWheelAngle = 5;
		    		vc.setSpeed(1);
			    }

			    //Go Backwards directly
			    else if(count < 10) {
                	desiredSteeringWheelAngle = 5;
		    		vc.setSpeed(-1);
			    }

			    count++;

		        vc.setSteeringWheelAngle(desiredSteeringWheelAngle * Constants::DEG2RAD);
		        Container c(Container::VEHICLECONTROL, vc);
		        getConference().send(c);

			}

			std::cout << "Done parking!" << std::endl;

            desiredSteeringWheelAngle = 0;
	        vc.setSteeringWheelAngle(desiredSteeringWheelAngle * Constants::DEG2RAD);
		    vc.setSpeed(0);

	        Container c(Container::VEHICLECONTROL, vc);
	        getConference().send(c);
        }

        void Driver::findParkingSpot(VehicleData& vd) {

        	std::cout << "Attempting to find parking spot" << std::endl;
        	bool found = false;

		    VehicleControl vc;
        	Container containerVehicleData = getKeyValueDataStore().get(Container::VEHICLEDATA);
		    Container containerSensorBoardData = getKeyValueDataStore().get(Container::USER_DATA_0);
		    SensorBoardData sbd = containerSensorBoardData.getData<SensorBoardData> ();

		    //Move this out later on, should be its own method most likely.
		    //Keep going forwards to get a ir sensor reading, then continue
		    while(sbd.getDistance(0) <= 0) {
        		containerSensorBoardData = getKeyValueDataStore().get(Container::USER_DATA_0);
		   		sbd = containerSensorBoardData.getData<SensorBoardData> ();

		   		vc.setSteeringWheelAngle(0 * Constants::DEG2RAD);
		   		vc.setSpeed(2);
	        	Container c(Container::VEHICLECONTROL, vc);
	        	getConference().send(c);
		    }	


		    double totalPath = 0;

        	while(!found) {

        		containerSensorBoardData = getKeyValueDataStore().get(Container::USER_DATA_0);
		   		sbd = containerSensorBoardData.getData<SensorBoardData> ();
		   		containerVehicleData = getKeyValueDataStore().get(Container::VEHICLEDATA);
		   		vd = containerVehicleData.getData<VehicleData> ();

		   		//Right IR and right US can't see anything, means we're at the end.
        		if(sbd.getDistance(4) <= 0 && sbd.getDistance(0) <= 0) {
   					return;
        		}

        		//Drop the float, check if it's -1 or not.
        		int distance = sbd.getDistance(0);

        		//If gap, and the total path is 0, ie a start hasn't been found
		   		if(distance == -1 && totalPath <= 0) {
		   		 	totalPath = vd.getAbsTraveledPath();
		   		}

		   		//Another object deteceted, check gap size
		   		else if (distance > -1) {

		   			if(vd.getAbsTraveledPath() - totalPath >= 3 && totalPath > 0) {
		   				//Spot found - Stop here.
		   				found = true;
	   				}

	   				totalPath = 0;
		   		}


		   		vc.setSteeringWheelAngle(0 * Constants::DEG2RAD);
		   		vc.setSpeed(1);
	        	Container c(Container::VEHICLECONTROL, vc);
	        	getConference().send(c);

	    	}

		    vc.setSteeringWheelAngle(0 * Constants::DEG2RAD);
		   	vc.setSpeed(0);
	        Container c(Container::VEHICLECONTROL, vc);
	        getConference().send(c);
        	std::cout << "Parking spot found" << std::endl;

	        //Finished finding spot, sending control to parking practice
        }
} // msv


//0 = IR Right, 1 = IR Rear, 2 = IR Left, 
//3 = US FrontCenter, 4 = US FrontRight, 5 = US FrontLeft
