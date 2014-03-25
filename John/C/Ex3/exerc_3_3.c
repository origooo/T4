/*====================================
File name: exerc_3_3.c (or cpp) Date: 2014‐01‐30
Group Number: 3
Members that contributed:
        John Burchell,
        Patrik Bäckström,
        William Granli
Demonstration code: 46504 [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct q {
        int number;
        struct q *next;
        //struct q *prev;
} REGTYPE;

REGTYPE* randomise(void);
REGTYPE* add_first(REGTYPE* temp, int data);
int random_num();

int main() {
        
        int nr = 0;
        REGTYPE *currentPos, *head = NULL;
        
        srand(5); // Random seed
        head = randomise();
        currentPos = head;

        while(currentPos != NULL) {
                printf("\n\tZip Code %d: %d\n", nr++, currentPos->number);
                currentPos=currentPos->next;
        }

       	//Assign to the current pos the new pointer to the front of the list.
 	    head = add_first(head, random_num());
 	    //Re-assign currentpos to be the head.
 	    currentPos = head;
 	    nr = 0;
 	    while(currentPos != NULL){
            printf("\n\tZip Code %d: %d\n", nr++, currentPos->number);
 	    	currentPos=currentPos->next;
 	    }

 	    while((currentPos = head) != NULL) {
            head = currentPos->next;
            free(currentPos);
        }

        return 0;
}


REGTYPE* randomise(void) {
        int i = 0;
        REGTYPE *top, *item;

        //Currently no links, so old and top are empty
        top = NULL;

        printf("Making %d nodes:\n", MAX);
        for(i = 0; i < MAX; i++){
        	//Re-allocate more space for another item.
        	item = malloc(sizeof(REGTYPE));
        	item->number = random_num();
        	item->next = top;
        	top = item;
        }

        return top;
}


REGTYPE* add_first(REGTYPE* temp, int data) {
        
    // Adds a record first i list and set the field tal to data
	REGTYPE *newNode = malloc(sizeof(REGTYPE));
	//Means it's the head.
	newNode->number = data;
	newNode->next = temp;

    printf("\nAdding %d to the front:\n", newNode->number);

	return newNode;
}

int random_num(){

	return rand() % 100 + 1;
}