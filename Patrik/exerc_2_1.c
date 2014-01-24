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

#define TEXT_LENGTH 100

void readFile();
void without(char *str1);
void with(char *str1);
void clearstdin(void);

int main(int argc, char *argv[]) {

	char str1[TEXT_LENGTH];

	if (argv[0] == NULL)
		printf("\nInput string (max length: %i): \n",TEXT_LENGTH);
	else {
		printf("\nArgument found...");
		printf("\nReading string from text file (max length: %i): \n", TEXT_LENGTH);
	}
	fgets(str1, TEXT_LENGTH, stdin);

	without(str1);

	if (argv[0] == NULL)
		printf("\nInput string (max length: %i): \n",TEXT_LENGTH);
	else {
		printf("\nArgument found...");
		printf("\nReading string from text file (max length: %i): \n", TEXT_LENGTH);
	}
	fgets(str1, TEXT_LENGTH, stdin);

	with(str1);
	//readFile(argv[0]);

	return 0;
}

void readFile(char *filename) {

	FILE *file;
	//char *filename = "/tmp/foo";
	file = fopen(filename, "r");
	char line[TEXT_LENGTH];
	if (file == NULL) {
		fprintf(stderr, "File %s could not be opened\n", filename);
		exit(1);
	}
	fgets(line, TEXT_LENGTH,file);
	fclose(file);
	printf("\nString from text file: %s\n\n",line);
}

void without(char *str1) {

	char copy[TEXT_LENGTH];
	int i;
	while (i < TEXT_LENGTH && str1[i] != '\n') {
		copy[i] = str1[i];
		i++;
	}
	//for (int i = 0; i < sizeof(str1); i++) {
	//	copy[i] = str1[i];
	//}

	printf("### Copying w/o strcpy().\n");
	printf("\tOriginal: %s", str1);
	printf("\tCopy: %s", copy);
}

void with(char *str1) {

	char copy[TEXT_LENGTH];
	strcpy(copy, str1);

	printf("### Copying with strcpy().\n");
	printf("\tOriginal: %s", str1);
	printf("\tCopy: %s", copy);
}

void clearstdin(void) {
	char temp;
	while((temp=getchar())!='\n');
}