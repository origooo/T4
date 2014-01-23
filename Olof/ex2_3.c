#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define MAX 5

int isInteger(char str[]) {
	int i;
	for (i = 0; i < strlen(str); i++) {
		if(isalpha(str[i])) return 0;
	}
	return 1;
}

int stringsAreEqual(char str1[], char str2[]) {
	if (strlen(str1) != strlen(str2)) return 0;

	int i;
	for (i = 0; i < strlen(str1); i++) {
		if (str1[i] != str2[i]) return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	if (argc == 3) {
		if (!(isInteger(argv[1]) || isInteger(argv[2]))) {
			if (stringsAreEqual(argv[1], argv[2]))
				printf("Without strcmp: The strings are the same.\n");
			else
				printf("Without strcmp: The strings are not the same.\n");
		} else 
			printf("ERROR");
		if (!strcmp(argv[1], argv[2])) 
			printf("With strcmp: The strings are the same.\n");
		else
			printf("With strcmp: The strings are not the same.\n");
	} else
		printf("Please provide 2 arguments.");
	return 0;
}
