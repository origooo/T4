#include <stdio.h>

#define VECTOR_ADDRESS 0x3FF2
#define STATUS 0xB00
#define IRQ 0xB01

#define NO_IRQ_TYPE 0
#define SENSOR_A 8
#define SENSOR_B 4
#define DOOR_IS_CLOSED 2
#define DOOR_IS_OPEN 1
#define IS_OPENING 16
#define IS_CLOSING 32

#define TIME_OUT 10

#define REG8(x) *((unsigned char*) (x))
#define SET_IRQ_VECTOR(interrupt_handler, address) *((unsigned int *) address) = &(interrupt_handler)

extern void standby(void);
extern void timerSetup(void);
extern void setTimeout(int);
void setup(void);
__interrupt void ML13_interrupt(void);

int interruptType;

int main() { // line 25
	
	setup();
	timerSetup();
	
	while(1) {
		standby();
	}
	return 0;
}

void setup(void) {

	SET_IRQ_VECTOR(ML13_interrupt, VECTOR_ADDRESS);
	__asm("CLI");
	REG8(IRQ)= 0x00;
}

__interrupt void ML13_interrupt(void) {
	interruptType = REG8(IRQ);
	switch (interruptType) {
		case DOOR_IS_OPEN: 
			puts("Door is open");
			setTimeout(TIME_OUT);
			REG8(STATUS) = 0x02;
			break;
		case DOOR_IS_CLOSED:
			puts("Door is closed");
			break;
		case SENSOR_B:
			puts("SENSOR B (right) activated");
			REG8(STATUS) = 0x01;
			break;
		case SENSOR_A:
			puts("SENSOR A (left) activated");
			REG8(STATUS) = 0x01;
			break;
		case IS_OPENING:
			puts("Door is opening");
			break;
		case IS_CLOSING: 
			puts("Door is closing");
			break;
		default: 
			printf("\tInterruptType = %#X",interruptType<<0);
			break;
	}
	REG8(IRQ) = 0x00;
}

