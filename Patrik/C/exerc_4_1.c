/*====================================
File name: exerc_4_1.c (or cpp) Date: 2014‐02-12
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 53909
======================================*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	unsigned char packedByte = 0x00;

	// Checking amount of arguments.
	if (argc != 6) {
		printf("Not correct amount of arguments (5 needed). Exiting...\n");
		return 1;
	}
	// Checking that no argument is larger than its max value
	if (atoi(*(argv+1)) > 1 || atoi(*(argv+2)) > 4 || atoi(*(argv+3)) > 2 || atoi(*(argv+4)) > 1 || atoi(*(argv+5)) > 1) {
		printf("One or more arguments is too large (MAX 1/4/2/1/1). Exiting...\n");
		return 1;
	}
	// Checking that no argument is lesser than 0
	for (int i = 0; i < argc; i++) {
		if (atoi(argv[i]) < 0) {
			printf("One or more arguments is less than 0. Exiting...\n");
			return 1;
		}
	}

	packedByte = atoi(*(argv+1));
	packedByte = packedByte << 3 | atoi(*(argv+2));
	packedByte = packedByte << 2 | atoi(*(argv+3));
	packedByte = packedByte << 1 | atoi(*(argv+4));
	packedByte = packedByte << 1 | atoi(*(argv+5));

	printf("Arguments packed\nBinary: ");
	for(int i = 7; i >= 0; i--) {
		printf("%i", (packedByte >> i) % 2 == 1 ? 1 : 0);
	}
	printf(", Decimal: %i, Hex: %#x\n", packedByte, packedByte);

	return 0;
}