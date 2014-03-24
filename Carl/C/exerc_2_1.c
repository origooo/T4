/*====================================
File name: exerc_2_1.c (or cpp) Date: 2014‐01‐24
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 56476
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_LENGTH 100

void without(char *str1);
void with(char *str1);

int main(int argc, char *argv[]) {

	char str1[TEXT_LENGTH], temp[TEXT_LENGTH];

	printf("\nInput string (max length: %i): \n",TEXT_LENGTH);
	fgets(str1, TEXT_LENGTH, stdin);
	without(str1);

	printf("\nInput string (max length: %i): \n",TEXT_LENGTH);
	fgets(str1, TEXT_LENGTH, stdin);
	with(str1);

	return 0;
}

void without(char *str1) {
	char *copy = malloc(sizeof(copy) * TEXT_LENGTH);
	int i=0;
	while (i < TEXT_LENGTH && str1[i] != '\n') {
		copy[i] = str1[i];
		i++;
	}
	copy[i+1] = '\0';
	printf("### Copying w/o strcpy().\n");
	printf("\tOriginal: %s", str1);
	printf("\tCopy: %s", copy);
	free(copy);
}

void with(char *str1) {

	char copy[TEXT_LENGTH];
	strcpy(copy, str1);
	printf("### Copying with strcpy().\n");
	printf("\tOriginal: %s", str1);
	printf("\tCopy: %s", copy);
}