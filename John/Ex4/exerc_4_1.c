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

unsigned char encode_bits ();

int main(int argc, char **argv) {

	// //Storing all bits!
	unsigned char packed = 0;

	if(argc < 5) {
		printf("Please input more arguments, you only gave %i!\n", argc);
		return 1;
	}

	// Checking amount of arguments. 
	if (argc != 6) { printf("Not correct amount of arguments (5 needed). Exiting...\n"); 
		exit(0); 
	} 
	// Checking that no argument is larger than its max value 

	if (atoi(*(argv+1)) > 1 || atoi(*(argv+2)) > 4 || atoi(*(argv+3)) > 2 || 
		atoi(*(argv+4)) > 1 || atoi(*(argv+5)) > 1) {
		 printf("One or more arguments is too large (MAX 1/4/2/1/1)." 
		 	"Exiting...\n");
		exit(0); 
	} 

	// Checking that no argument is lesser than 0 

	for (int i = 0; i < argc; i++) {
		if (atoi(argv[i]) < 0) { 
			printf("One or more arguments is less than 0. Exiting...\n");
			exit(0);
		}
	}

	//Pack and shift based on their length. Is there a way to get it auto?
	packed = atoi(argv[1]);
	packed = (packed << 3) | atoi(argv[2]);
	packed = (packed << 2) | atoi(argv[3]);
	packed = (packed << 1) | atoi(argv[4]);
	packed = (packed << 1) | atoi(argv[5]);

	printf("Result is: %#X\n", packed);
}