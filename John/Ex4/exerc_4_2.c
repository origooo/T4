/*====================================
File name: exerc_4_1.c (or cpp) Date: 2014‐01‐30
Group Number: 3
Members that contributed:
        John Burchell,
        Patrik Bäckström,
        William Granli
Demonstration code:  [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned char engine : 1;
	unsigned char gear   : 3;
	unsigned char key    : 2;
	unsigned char brake1 : 1;
	unsigned char brake2 : 1;

} byte;


int main(int argc, char**argv) {

	byte bite;

	//Convert to Base 16 - Hex
	unsigned char input = strtol(argv[1], NULL, 16);

	if (argc < 2) {
		printf("Please enter more than zero arguments! \n");
		return 1;
	}
	else if(argc >= 3){
		printf("Please enter only one hex argument, try AB \n");
		return 1;
	}
	if(input < 0xAB || input > 0xAB){
		printf("Please enter AB, not greater than or below.\n");
		return 1;
	}

	//Input value.
	//printf("Input was: %lu\n", strtol(argv[1], NULL, 16));
	//1010-1011
	bite.brake2 = input & 1;
	//0101-0101
	input = input >> 1;
	bite.brake1 = input & 1;
	//0010-1010
	input = input >> 1;
	bite.key = input & 2;
	//0000-1010
	input = input >> 2;
	bite.gear = input & 3;
	//0000-0001
	input = input >> 3;
	bite.engine = input & 1;

	printf("The results are:\n\n"
		"Name\t    Value"
		"\n------------------"
		"\nengine_on\t%i"
		"\ngear_pos \t%i"
		"\nkey_pos  \t%i"
		"\nbrake1   \t%i"
		"\nbrake2   \t%i\n",

		bite.engine, bite.gear, bite.key, bite.brake1, bite.brake2);

	return 0;
}
