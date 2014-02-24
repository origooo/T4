/*====================================
File name: exerc_2_6.c (or cpp) Date: 2014‐01‐28
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 51498
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_SIZE 5

int add(int queue[], int number);
void initQue(int array[]);
void printQueue(int *);
int getFirst(int *);

int main(int argc, char *argv[]) {

	int queue[QUEUE_SIZE];
	initQue(queue);
	srand(time(NULL));

	int addAmount = QUEUE_SIZE + 1; // Add this amount of entries
	while (addAmount) {				// Automated for testing purpose
		printQueue(queue);
		int input = rand() % 100; 	// or get from user input

		0 == add(queue,input) ? printf("\n\t\t# ERROR: Queue full. Cannot add %i.\n", input) : printf("\n\t# Added %i to queue!", input);
		addAmount--;
	}
	printQueue(queue);

	int removeAmount = QUEUE_SIZE; 	// Remove this amount of entries
	while (removeAmount) {			// Automated for testing purpose
		int nextNum = getFirst(queue);
		printf("\n\t# Removing first queue element: %i", nextNum);
		printQueue(queue);
		removeAmount--;
	}

	return 0;
}

void initQue(int *queue) {
	for (int i = 0; i < QUEUE_SIZE; i++) {
		*(queue + i) = -1;
	}
}

int add(int *queue, int num) {

	if (*(queue + QUEUE_SIZE - 1) == -1) { // Instantly checks if queue is full
		for (int i = 0; i < QUEUE_SIZE; i++) {
			if (*(queue + i) == -1) {
				*(queue + i) = num;
				break;
			}
		}
		return 1;
	} else {
		return 0;
	} 
}

int getFirst(int *queue) {

	int nextNum = *queue;
	for (int i = 1; i < QUEUE_SIZE; i++) {
		*(queue + i - 1) = *(queue + i);
		QUEUE_SIZE - 1 == i ? *(queue + i) = -1 : 0;
	}

	return nextNum;
}

void printQueue(int *queue) {
	printf("\n\t# Current queue: ");
	for (int i = 0; i < QUEUE_SIZE; i++) {
		printf("%d", *(queue + i));
		QUEUE_SIZE - 1 == i ? printf("\n") : printf(",");
	}
}