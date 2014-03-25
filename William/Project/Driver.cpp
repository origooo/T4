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




namespace msv {

        using namespace std;
        using namespace core::base;
        using namespace core::data;
        using namespace core::data::control;
        using namespace core::data::environment;



        Driver::Driver(const int32_t &argc, char **argv) :
	        ConferenceClientModule(argc, argv, "Driver"),
	        TimeCounter (0),
			TimeSlice (0),
			OvertakingDetected (false),
			MadeTurn(false),
			PassedCar (false) 
			{
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

        	int Counter = 0;

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

				// Create vehicle control data.
		        VehicleControl vc;

		        //0 = IR FrontRight, 1 = IR Rear, 2 = IR FrontLeft, 
		        //3 = US FrontCenter, 4 = US FrontRight, 5 = US FrontLeft


		        

		        
                // Design your control algorithm here depending on the input data from above.
                int UltraSonicFrontCenter = sbd.getDistance(3);
              	//int UltraSonicFrontRight = sbd.getDistance(4);
				//int InfraRedFrontRight = sbd.getDistance(0); 

				vc.setSpeed(0.4);

				if (UltraSonicFrontCenter < 9) {
					OvertakingDetected = true;
				}

            	if (OvertakingDetected) {

            		//Turn left
            		if (Counter <= 35) {
		        		vc.setSteeringWheelAngle(-15 * Constants::DEG2RAD);
		        		MadeTurn = true;
		        	}
					
					//Turn right
		        	else if (MadeTurn && Counter <= 70) { //InfraRedFrontRight != -1 && 
		        		vc.setSteeringWheelAngle(15 * Constants::DEG2RAD);
		        		PassedCar = true;
		        	}
		        	//Finished 
		        	else if (PassedCar) { //InfraRedFrontRight == -1 && 
	        			vc.setSteeringWheelAngle(0);
	        			MadeTurn = false;
	        			vc.setSpeed(0);
	        			OvertakingDetected = false;
	        		}			        	
	        		Counter++;
            	}

           

                // With setSpeed you can set a desired speed for the vehicle in the range of -2.0  
                // backwards) .. 0 (stop) .. +2.0 (forwards)
		        
                // With setSteeringWheelAngle, you can steer in the range of -26 (left) .. 0
                // (straight) .. +25 (right)
                
                //double desiredSteeringWheelAngle = 4; // 4 degree but SteeringWheelAngle expects the angle in radians!
		        //vc.setSteeringWheelAngle(desiredSteeringWheelAngle * Constants::DEG2RAD);


		        // Create container for finally sending the data.
		        Container c(Container::VEHICLECONTROL, vc);
		        // Send container.
		        getConference().send(c);
	        }

	        return ModuleState::OKAY;
        }
} // msv

