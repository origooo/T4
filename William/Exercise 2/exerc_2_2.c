#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 15

void main (void) {
	
	char int_array[MAX];
	
	int num;
	int i;
	srand(time(NULL));
	for (i=0; i<=MAX; i++) {
		num = rand() % 10 + 1;
		int_array[i] = num;
	}
	
	printf("The value (address) of the array is %p\n", &int_array[MAX]);
	printf("The initial values are:\n");
	for (i=0; i<=MAX; i++) {
		printf("%d ", int_array[i]);
	}
	printf("\nThe size of an int is %lu\n", sizeof(int_array[0]));
	printf("The size of the array is %lu\n", sizeof(int_array));
	printf("The values after doubling them are:\n");
	for (i=0; i<=MAX; i++) {
		*(int_array + i) *= 2;
		printf("%d ", *(int_array + i));
	}
}
