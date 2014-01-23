/*====================================
File name: exerc_1_1.c (or cpp) Date: 2014‐01‐21
Group Number: 3
Members that contributed:
	Patrik Bäckström
Demonstration code: [<Ass code 1‐4> <abc>] <--- ????????
======================================*/

#include <stdio.h>

int main() {

	int selected;

	printf("Give a number from 1 to 10: ");
	scanf("%i", &selected);

	switch (selected) {
		case 0:	printf("You gave number %i. Exiting...\n", selected); break;
		case 1: printf("You gave number %d\n", selected); break;
		case 2: printf("You gave number %d\n", selected); break;
		case 3: printf("You gave number %d\n", selected); break;
		case 4: printf("You gave number %d\n", selected); break;
		case 5: printf("You gave number %d\n", selected); break;
		case 6: printf("You gave number %d\n", selected); break;
		case 7: printf("You gave number %d\n", selected); break;
		case 8: printf("You gave number %d\n", selected); break;
		case 9: printf("You gave number %d\n", selected); break;
		case 10: printf("You gave number %d\n", selected); break;
		default: printf("Nothing selected. Exiting... \n");
	}

	return 0;
}