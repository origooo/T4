/*====================================
File name: exerc_2_1.c (or cpp) Date: 2014‐01‐23
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#include <stdlib.h>

#define TEXT_LENGTH 30

int main(int argc, char *argv[]) {

	char temp, str1[TEXT_LENGTH];//, str2[TEXT_LENGTH];

	printf("Write something, fool: ");
	fgets(str1, TEXT_LENGTH, stdin);

	for (int i = 0; i < sizeof(str1); i++) {
		str2[i] = str1[i];
	}

	return 0;
}