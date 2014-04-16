/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <stdio.h>
#include <math.h>

#include "core/io/ContainerConference.h"
#include "core/data/Container.h"
#include "core/data/Constants.h"
#include "core/data/control/VehicleControl.h"
#include "core/data/environment/VehicleData.h"

// Data structures from msv-data library:
#include "SteeringData.h"
#include "SensorBoardData.h"
#include "UserButtonData.h"

#include "Driver.h"


#define SAFE_LEFT_LINE_DISTANCE 50
#define SAFE_LEFT_LINE_ANGLE 40

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

        	bool 	right2left = false,
        			checkRightSide = false,
        			isOvertaking = false,
        			followLane = true,
        			targetAccuired = false,
        			//left2rightStraight = false;
        			left2right = false;
        	double 	USFront = 0,
        			IRRight = 0,
        			speed = 1,
        			steeringAngle = 0, // NOTE: Is revieced in radians!
        			leftLineDistance = 0;
        			//centerDistance = 0,
        			//leftLineAngle = 0;
        			//stopLineDetected = false;

	        while (getModuleState() == ModuleState::RUNNING) {

		        // 1. Get most recent vehicle data:
		        Container containerVehicleData = getKeyValueDataStore().get(Container::VEHICLEDATA);
		        VehicleData vd = containerVehicleData.getData<VehicleData> ();
		        //cerr << "Most recent vehicle data: '" << vd.toString() << "'" << endl;

		        // 2. Get most recent sensor board data:
		        Container containerSensorBoardData = getKeyValueDataStore().get(Container::USER_DATA_0);
		        SensorBoardData sbd = containerSensorBoardData.getData<SensorBoardData> ();
		        //cerr << "Most recent sensor board data: '" << sbd.toString() << "'" << endl;

		        // 3. Get most recent user button data:
		        Container containerUserButtonData = getKeyValueDataStore().get(Container::USER_BUTTON);
		        UserButtonData ubd = containerUserButtonData.getData<UserButtonData> ();
		        //cerr << "Most recent user button data: '" << ubd.toString() << "'" << endl;

		        // 4. Get most recent steering data as fill from lanedetector for example:
		        Container containerSteeringData = getKeyValueDataStore().get(Container::USER_DATA_1);
		        SteeringData sd = containerSteeringData.getData<SteeringData> ();
		        //cerr << "Steering steeringAngle: '" << sd.getSteeringAngle() << "'" << endl;
				
		        VehicleControl vc;
				vc.setSpeed(speed);

		        USFront = sbd.getDistance(3);
		        IRRight = sbd.getDistance(0);
		        true == followLane ? steeringAngle = (sd.getSteeringAngle() * Constants::RAD2DEG) : 0; // SteeringAngle re-calced to DEG
		        //centerDistance = sd.getCenterDistance();
		        leftLineDistance = sd.getLeftLineDistance();
		        //leftLineAngle = sd.getLeftLineAngle();
		        //stopLineDetected = sd.getStopLineDetected();
				
				cout << "--------------------------------------\nLeft line angle: " << leftLineAngle<< endl;
		        //cout << "--------------------------------------\nFollowing lane: " << followLane << "\nSteering angle: " << steeringAngle << "\nLeft line distance: " << leftLineDistance << "\nCenter distance: " << centerDistance << "\nLeft line angle: " << leftLineAngle << "\nStop line detected: " << stopLineDetected << endl;

		        if (USFront < (10 + speed*2 ) && USFront > (9 + speed*2) && !isOvertaking) {
	        		cout << "\n\t\tOVERTAKING!\n" << endl;
		        	isOvertaking = true;
		        	right2left = true;
		        	followLane = false;
		        }
		        if (right2left) {
		        	if (USFront > 0) {
		        		vc.setSteeringWheelAngle(--steeringAngle * Constants::DEG2RAD);
		        	} else if (USFront < 0) {
	        			cout << "\n\t\tFRONT US CLEAR!\n" << endl;
		        		steeringAngle = 0;
		        		vc.setSteeringWheelAngle(steeringAngle * Constants::DEG2RAD);
		        		right2left = false;
		        		checkRightSide = true;
		        	}
				}
				if (checkRightSide) {
        			//cout << "\n\t\tChecking right side!\n" << endl;
        			if (targetAccuired && leftLineDistance > 200) {
        				vc.setSteeringWheelAngle(++steeringAngle * Constants::DEG2RAD);
        			} else if (targetAccuired && leftLineDistance < 200) {
						vc.setSteeringWheelAngle(((--steeringAngle) * 2) * Constants::DEG2RAD);
        			}
					if (IRRight > 0 && !targetAccuired) {
		        		cout << "\n\t\tTarget accuired\n" << endl;
			        	targetAccuired = true;
			        }
		        	if (targetAccuired && IRRight < 0) {
		        		cout << "\n\t\tTarget passed\n" << endl;
		        		steeringAngle=10;
		        		vc.setSteeringWheelAngle(steeringAngle * Constants::DEG2RAD);
		        		left2right = true;
		        		checkRightSide = false;
			        	targetAccuired = false;
		        		//followLane = true;
			        	//left2rightStraight = false;
		        		//isOvertaking = false;
		        	}
				}
				if (left2right) {
					if (leftLineDistance < 200 && leftLineDistance > 0) {
						vc.setSteeringWheelAngle(++steeringAngle * Constants::DEG2RAD);
					} else if(leftLineDistance > 400) {
						steeringAngle = 0;
						vc.setSteeringWheelAngle(steeringAngle * Constants::DEG2RAD);
						left2right = false;
		        		isOvertaking = false;
						followLane = true;
					} else {
						vc.setSteeringWheelAngle(--steeringAngle * Constants::DEG2RAD);
					}
				}
		    //    if (right2left) {
					// if (steeringAngle >= -30 + (5 * speed)) {
		   //      		vc.setSteeringWheelAngle(--steeringAngle * Constants::DEG2RAD);
		   //      	} else {
		   //      		vc.setSteeringWheelAngle(0 * Constants::DEG2RAD);
		   //      	}
		   //      	if (leftLineAngle > -30 && leftLineAngle < -1 && leftLineDistance > 300 && leftLineDistance < centerDistance) {
		   //      		cout << "\t\tBREAK LEFT2RIGHT\n\n\t\tSTRAIGHTENING OUT VEHICLE" << endl;
		   //      		right2left = false;
			  //       	checkRightSide = true;
		   //      		//left2rightStraight = true;
		   //      		steeringAngle = 0;
	    //     			vc.setSteeringWheelAngle(steeringAngle * Constants::DEG2RAD);
		   //      	}
		   //     }
		   //      if (left2rightStraight) {
		   //      	if (leftLineAngle > -50) {
		   //      		vc.setSteeringWheelAngle(++steeringAngle * Constants::DEG2RAD);
		   //      	} else {
		   //      		steeringAngle=0;
		   //      		vc.setSteeringWheelAngle(steeringAngle * Constants::DEG2RAD);
			  //       	checkRightSide = true;
		   //      	}
		   //      }
		   //      if (checkRightSide) {
		   //      	if (leftLineDistance > 350) {
		   //      		vc.setSteeringWheelAngle(++steeringAngle * Constants::DEG2RAD);
		   //      	} else if (leftLineDistance < 350 && leftLineDistance > 0) {
		   //      		vc.setSteeringWheelAngle(--steeringAngle * Constants::DEG2RAD);
		   //      	} else {
		   //      		vc.setSteeringWheelAngle(0 * Constants::DEG2RAD);
		   //      	}
					// if (IRRight > 0 && !targetAccuired) {
		   //      		cout << "\n\t\tTarget accuired\n" << endl;
			  //       	targetAccuired = true;
			  //       }
		   //      	if (targetAccuired && IRRight < 0) {
		   //      		cout << "\n\t\tTarget passed\n" << endl;
		   //      		steeringAngle=0;
		   //      		vc.setSteeringWheelAngle(0 * Constants::DEG2RAD);
		   //      		// left2right = true;
		   //      		checkRightSide = false;
			  //       	targetAccuired = false;
		   //      		followLane = true;
			  //       	left2rightStraight = false;
		   //      		isOvertaking = false;
		   //      	}
		   //      }
		        // if (left2right) {
		        // 	if (left2rightCounter < 13) {
		        // 		vc.setSteeringWheelAngle(+steeringAngle * Constants::DEG2RAD);
		        // 	} else if (left2rightCounter < 26) {
		        // 		vc.setSteeringWheelAngle(-steeringAngle * Constants::DEG2RAD);
		        // 	}
		        // 	if (left2rightCounter >= 26) {
		        // 		left2right = false;
		        // 		left2rightCounter = 0;
		        // 		vc.setSteeringWheelAngle(0 * Constants::DEG2RAD);
		        // 		isOvertaking = false;
		        // 		//speed = 0; // NOT PART OF OVERTAKING MANEUVER!
		        // 	} else {
		        // 		left2rightCounter++;
		        // 	}
		        // }

		        vc.setSteeringWheelAngle(steeringAngle * Constants::DEG2RAD);
                vc.setBrakeLights(false);
                vc.setLeftFlashingLights(false);
                vc.setRightFlashingLights(true);

		        Container c(Container::VEHICLECONTROL, vc);
		        getConference().send(c);
	        }

	        return ModuleState::OKAY;
        }
} // msv

