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
#include <string.h>

#define TEXT_LENGTH 30

void without(char *str1);
void with(char *str1);

int main(int argc, char *argv[]) {

	char str1[TEXT_LENGTH];

	printf("\nInput string (max length: %i): ",TEXT_LENGTH);
	fgets(str1, TEXT_LENGTH, stdin);

	without(str1);

	printf("\nInput another string (max length: %i): ",TEXT_LENGTH);
	fgets(str1, TEXT_LENGTH, stdin);
	with(str1);

	return 0;
}

void without(char *str1) {

	char copy[TEXT_LENGTH];
	for (int i = 0; i < sizeof(str1); i++) {
		copy[i] = str1[i];
	}

	printf("Copying w/o strcpy():\n");
	printf("\tOriginal: %s", str1);
	printf("\tCopy: %s", copy);
}

void with(char *str1) {

	char copy[TEXT_LENGTH];
	strcpy(copy, str1);

	printf("Copying with strcpy():\n");
	printf("\tOriginal: %s", str1);
	printf("\tCopy: %s", copy);
}