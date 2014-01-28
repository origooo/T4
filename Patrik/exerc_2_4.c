/*====================================
File name: exerc_2_4.c (or cpp) Date: 2014‐01‐24
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: [<Ass code 1‐4> <abc>]
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
	if (palindrome(argv[1]))
		printf("\n\t# %s is a palindrome!\n\n", argv[1]);
	else
		printf("\n\t# %s is NOT a palindrome!\n\n", argv[1]);

	return 1337;
}

int palindrome(char *str) {

	int length = getLength(str), stepsize = 0, stepcount = 0;

	while (stepcount <= length / 2) {
		if (*(str + stepsize) != *(str + (sizeof(char) * length - sizeof(char)) - stepsize)) {
			return 0;
		}
		stepcount++;
		stepsize += sizeof(char);
	}
	return 1;
}

int getLength(char *str) {

	int i = 0, length = 0;
	while (*(str + i) != '\0') {
		i += sizeof(char);
		length++;
	}

	return length;
}