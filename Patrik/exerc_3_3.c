/*====================================
File name: exerc_3_3.c (or cpp) Date: 2014‐01‐30
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct q {
	int number;
	struct q *next;
	struct q *prev;
} REGTYPE;

REGTYPE* randomize(void);
REGTYPE* add_first(REGTYPE* temp, int data);

int main(int argc, char *argv[]) {
	
	int nr = 0;
	REGTYPE *currentPos, *head = NULL;
	
	srand(time(0)); // Random seed
	head = randomize();
	currentPos = head;
 
	while(currentPos != NULL) {
		printf("\nZip Code %d: %d", nr++, currentPos->number);
		currentPos=currentPos->next;
	}
 
	while((currentPos = head) != NULL) {
		head = currentPos->next;
		free(currentPos);
	}

	system("PAUSE");
	return 0;
}


REGTYPE* randomize(void) {
	int nr, i = 0;
	REGTYPE *top, *old, *item;

	return top;
}


REGTYPE* add_first(REGTYPE* temp, int data) {
	// Adds a record first i list and set the field tal to data
}