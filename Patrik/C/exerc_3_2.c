/*====================================
File name: exerc_3_2.c (or cpp) Date: 2014‐01‐30
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>

int search_number(int, int[], int);
void sort(int, int[]);
void swap(int, int*, int);

int size;

int main(int argc, char *argv[]) {

	int array[] = {1,2,34,5,67,12,54,74,23,431,23,1,5,87,56,34,54,94};
	size = sizeof(array)/sizeof(*array);
	int lookForNum = 0;
	int numFoundAtIndex = 0;

	/* 
	* Exercise 3.2 a.
	* Search throug array[] for int lookForNum.
	* search_number() return index position of lookForNum, or
	* -1 if not found. Print result (int numFoundAtIndex).
	*/

	printf("\n\t# What number do you want to find?\n");
	printf("\t>>> ");
	scanf("%i", &lookForNum);

	numFoundAtIndex = search_number(lookForNum, array, size);
	
	-1 == numFoundAtIndex ? printf("\n\t%i was not found!\n\n", lookForNum) : printf("\n\t%i was found in index %i\n", lookForNum, numFoundAtIndex);

	/* 
	* Exercise 3.2 b.
	* Sort array[] with ascending order.
	* Print array[] before and after sorting.
	*/

	printf("\n\t# Array before sorting: ");
	for (int i = 0; i < size; i++) {
		printf("%i", array[i]);
		i == size - 1 ? printf("\n") : printf(", ");
	}

	sort(0, array);

	printf("\t# Array after sorting: \t");
	for (int i = 0; i < size; i++) {
		printf("%i", array[i]);
		i == size - 1 ? printf("\n") : printf(", ");
	}
	printf("\n");

	return 0;
}

int search_number(int number, int array[], int size) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		number == array[i] ? index = i : 0;
	}
	return index;
}

void sort(int startIndex, int array[]) {
	int minVal = array[startIndex], indexOfMinVal = startIndex;
	for (int i = startIndex; i < size; i++) {
		array[i] < minVal ? (minVal = array[i], indexOfMinVal = i) : 0;
	}
	swap(indexOfMinVal, array, startIndex);
	startIndex < size ? sort(startIndex+1, array) : 0;
}

void swap(int indexOfMinVal, int* array, int currentStart) {
	int temp = array[currentStart];
	array[currentStart] = array[indexOfMinVal];
	array[indexOfMinVal] = temp;
}