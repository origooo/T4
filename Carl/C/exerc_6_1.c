#include <stdio.h>

#define STATUS 0xB00

#define DOOR_IS_CLOSING 0x70
#define DOOR_NEARLY_CLOSED 0x10
#define DOOR_IS_CLOSED 0x20

#define DOOR_IS_OPENING 0x80
#define DOOR_NEARLY_OPEN 0x04
#define DOOR_IS_OPEN 0x08

#define BUTTON_A 0x01
#define BUTTON_B 0x02

#define REG8(x) *((unsigned char*) (x))

int main() {
	int i = 0;
	
	while(1) {
		if(REG8(STATUS) & DOOR_IS_CLOSED) {
			puts("Door is closed.");
		}
		
		// Person approaching from outside
		if((REG8(STATUS) & BUTTON_A) || (REG8(STATUS) & BUTTON_B)) {
			puts("\tMotion detected...");
			REG8(STATUS) = 0x01;
			for(i = 0; i < 50; i++);
			
		} // Close if nothing is approaching
		else if ((REG8(STATUS) & DOOR_IS_OPEN)){// || REG8(STATUS) == 0x02) {
			puts("\t\tDoor is fully open. Closing...");
			REG8(STATUS) = 0x02;
			for(i = 0; i < 200; i++);
		}
		
		//if(REG8(STATUS) == DOOR_NEARLY_OPEN) {
		//	puts("Door is nearly fully open.");
		//}
		//else if(REG8(STATUS) == DOOR_NEARLY_CLOSED) {
		//	puts("Door is nearly fully closed.");
		//}
	}
	return 0;
}
