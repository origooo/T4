/*====================================
File name: exerc_2_5.c (or cpp) Date: 2014‐01‐26
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 50542
======================================*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NUMBER 10
#define MAX_ARRAY_SIZE 20

void create_random(int *);
void count_frequency(int *);
void draw_histogram(int *);

int table[MAX_ARRAY_SIZE], frequency[MAX_NUMBER];
char x[MAX_ARRAY_SIZE];
int *tptr = &table[0], *fptr = &frequency[0];

int main(int argc, char *argv[]) {

	/* Fill table[] with random numbers */
	srand(time(NULL));
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		create_random(tptr + i);
	
	/* Count frequency of each number in table[] */
	for (int i = 0; i < MAX_NUMBER; i++)
		count_frequency(&i);
	
	/* Fill upp char x with 'x' for the histogram */
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		x[i] = 'x';

	draw_histogram(fptr);
	
	return 0;
}

void draw_histogram(int *fptr) {
	for (int i = 0; i < MAX_NUMBER; i++)
		if (*(fptr + i) != 0)
			printf("%i \t%*.*s\n",i,0,*(fptr + i),x);
}

void count_frequency(int *number) {
	int occasions = 0;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		if (*number == *(tptr + i))
			occasions++;
	*(fptr + *number) = occasions;
}

void create_random(int *index) {
	*index = rand() % MAX_NUMBER;
}