/*====================================
File name: exerc_1_2.c (or cpp) Date: 2014‐01‐22
Group Number: 3
Members that contributed:
	Patrik Bäckström
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#include <ctype.h>
#define MAX 10

int main() {
	
	char sentenceArray[MAX+1]; // Adding one index to compensate for end of string cut-off.
	int numOfWords = 0;
	printf("\t# Write a sentence (max length %i characters): ", MAX);
	fgets(sentenceArray, MAX, stdin);

	for (int i = 0; i < sizeof(sentenceArray); i++) {
		if (i > 0 && isspace(sentenceArray[i]) && isalnum(sentenceArray[i-1])) {
			numOfWords++;
		}
		if (i == sizeof(sentenceArray)-1 && isalnum(sentenceArray[i-1])) {
			numOfWords++;
		}
	}

	printf("\n\t# You wrote: %s\n\t# Number of words: %i\n\n", sentenceArray, numOfWords);

	return 0;
}