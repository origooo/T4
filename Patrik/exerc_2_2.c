/*====================================
File name: exerc_2_2.c (or cpp) Date: 2014‐01‐24
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 50511
======================================*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100
#define ARRAY_SIZE 10

int main(int argc, char *argv[]) {

	int numbers[ARRAY_SIZE];
	int *ptr = numbers;
	srand(time(NULL));
	for (int i = 0; i < ARRAY_SIZE; i++) {
		numbers[i] = rand() % MAX + 1;
	}

	printf("\n\t* Memmory address of 'numbers' array: %p\n", &numbers);
	printf("\t* Integer value of numbers[0]: %i\n", numbers[0]);
	printf("\t* Size of an integer: %zu bytes, size of 'numbers' array: %zu\n", sizeof(int), sizeof(numbers));

	printf("\n\t* Doubling values of 'numbers':\n\t\tIndex\tBefore\tAfter");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		int num = *(ptr + i);
		printf("\n\t\t%i\t%i\t%i", i+1, numbers[i], num*2);
	}
	printf("\n\n");

	return 0;
}