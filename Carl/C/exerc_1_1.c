/*====================================
File name: exerc_1_1.c (or cpp) Date: 2014‐01‐21
Group Number: 3
Members that contributed:
	Patrik Bäckström
Demonstration code: [<Ass code 1‐4> <abc>] <--- ????????
======================================*/

#include <stdio.h>

int main() {

	char *words[] = {"one","two","three","four","five","six","seven","eight","nine","ten"};
	int selected;

	printf("\t# Give a number from 1 to 10: ");
	0 == scanf("%i", &selected) ? printf("\t# No valid input. Exiting...\n") : printf("\t# %s\n",words[selected-1]);

	return 0;
}