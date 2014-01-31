/*====================================
File name: exerc_2_3.c (or cpp) Date: 2014‐01‐24
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 58925
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int cmpWithout(char *, char *);

int main(int argc, char *argv[]) {

	if (argc != 3)
		printf("\n\t# Not correct amount of arguments...\n\tExactly two (2) is required!\n\n\tExiting...\n\n");
	else {
		printf("\n\t# Comparing arguments WITHOUT strcmp(): ");
		if (cmpWithout(argv[1],argv[2]))
			printf("\tStrings are equal\n");
		else
			printf("\tStrings are NOT equal\n");

		printf("\t# Comparing arguments WITH strcmp(): ");
		if (!strcmp(argv[1],argv[2]))
			printf("\t\tStrings are equal\n");
		else
			printf("\t\tStrings are NOT equal\n");
		printf("\n");
	}

	return 0;
}

int cmpWithout(char *str1, char *str2) {

	if (strlen(str1) != strlen(str2))
		return 0;

	int i = 0;
	while (*(str1 + i) != '\0') {
		if (*(str1 + i) == *(str2 + i)) {
			i += sizeof(char);
			continue;
		} else 
			return 0;
	}
	return 1;
}