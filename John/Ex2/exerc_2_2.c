/* ==================================== 
File name: exerc_2_2.c (or cpp) 
Date: 2013‐01-23
Group Number: 03
Members that contributed: 
John Burchell
Patrik Backstrom
William Granli
Demonstration code: [<Ass code 1‐4> <abc>]        Important , No code no bonus ! 
====================================== */ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main(int argc, char *argv[])
{
	int ints[MAX];
	srand(time(NULL));

	int i = 0;
	for(i = 0; i < MAX - 1; i++) {
		ints[i] = rand() % MAX;
	}

	printf("The address of the array is %p\n", &ints);
	printf("The first integer is: %d\n", ints[0]);
	printf("The integer at [5] is %lu bytes and the array itself is %lu bytes\n", sizeof(ints[5]), sizeof(ints));
	printf("The starting values are: \n");
	for(i = 0; i < MAX - 1; i++){
		printf("%d ", ints[i]);
	}
	printf("\nAnd the values after doubling them by pointers are: \n");

	//Point to the front of the ints array.
	int *cur_int = ints;
	for(i = 0; i < MAX - 1; i++){
		*(cur_int + i) *= 2;
		printf("%d ", *(cur_int + i));
	}

	printf("\n");
}

