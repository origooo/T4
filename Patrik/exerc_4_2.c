/*====================================
File name: exerc_4_2.c (or cpp) Date: 2014‐02-12
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned char engine;
	unsigned char gear;
	unsigned char key;
	unsigned char br1;
	unsigned char br2;
} myByte;

int main(int argc, char* argv[]) {

	unsigned char arg = strtol(argv[1],NULL,16);
	// Checking amount of arguments.
	if (argc != 2) {
		printf("Not correct amount of arguments (1 needed). Exiting...\n");
		return 1;
	}
	if (arg < 0x00 && arg > 0xFF) {
		printf("ERROR! Argument outside span 00-FF. Exiting...\n");
		return 1;
	}

	myByte mb;
	mb.engine = arg;

	printf("%c\n", arg);

	return 0;
}