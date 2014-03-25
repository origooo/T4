/*====================================
File name: exerc_2_4.c (or cpp) Date: 2014‐01‐24
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 54363
======================================*/

#include <stdio.h>
#include <string.h>

int getLength(char*);
int palindrome(char*);

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("\n\t# Not correct amount of arguments...\n\tExactly one (1) is required!\n\n\tExiting...\n\n");
		return 0;
	}
	1 == palindrome(*(argv + 1)) ? printf("\n\t# %s is a palindrome!\n\n", argv[1]) : printf("\n\t# %s is NOT a palindrome!\n\n", argv[1]);

	return 0;
}

int palindrome(char *str) {

	int length = getLength(str), i = 0;

	while (i <= length / 2) {
		if (*(str + i) != *(str + (length - 1) - i))
			return 0;
		i++;
	}
	return 1;
}

int getLength(char *str) {

	int length = 0;
	while (*(str + length) != '\0')
		length++;

	return length;
}