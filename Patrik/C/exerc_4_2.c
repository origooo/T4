/*====================================
File name: exerc_4_2.c (or cpp) Date: 2014‐02-14
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 56847
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	unsigned char engine : 1;
	unsigned char gear : 3;
	unsigned char key : 2;
	unsigned char br1 : 1;
	unsigned char br2 : 1;
} myByte;

int main(int argc, char* argv[]) {

	unsigned char arg;

	if (argc != 2) {	// Checking amount of arguments.
		printf("\tERROR! Not correct amount of arguments (1 needed). Exiting...\n");
		return 1;
	} else if (strlen(argv[1]) != 2) {	// Checking length of argument
		printf("\tERROR! Argument too long or short. Expected one byte written in HEX. Exiting...\n");
		return 1;
	} else if(toupper(argv[1][0]) <= 'F' && toupper(argv[1][1]) <= 'F') {
		// Added possibility to input any one byte HEX code.
		// To just allow AB as input is just silly (;

		int arg1Subtraction = 55;
		// int arg2Subtraction = 55;

		if (argv[1][0] < 'A') { arg1Subtraction = 48;}
		if (argv[1][1] < 'A') { arg1Subtraction = 48;}

		arg = toupper(argv[1][0] - arg1Subtraction) << 4;
		arg = arg | toupper(argv[1][1] - arg1Subtraction);
		
		myByte mb;
		mb.engine = arg >> 7;
		mb.gear = arg >> 4;
		mb.key = arg >> 2;
		mb.br1 = arg >> 1;
		mb.br2 = arg;

		printf("\n\t\033[0;36;40m Arg HEX: %#x, BIN: ", arg);
		for(int i = 7; i >= 0; i--) {
			printf("%i", (arg >> i) % 2 == 1 ? 1 : 0);
		}
		printf(" \033[00m\n\tNAME\tVALUE\n\t-------------\n\tEngine:\t%i\n\tGear:\t%i\n\tKey:\t%i\n\tBreak1:\t%i\n\tBreak2:\t%i\n\n",mb.engine,mb.gear,mb.key,mb.br1,mb.br2);
	} else {	// Checks failed -> outside range 0x00-0xFF
		printf("\tERROR! Argument outside span 00-FF. Exiting...\n");
		return 1;
	}

	return 0;
}