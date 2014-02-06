#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct q{
	int number;
	struct q *next;
	struct q *prev;
} REGTYP;

// ##### Funcion declarations #####
REGTYP* randomize(void);
REGTYP* add_first(REGTYP* temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{

	//create structs
	REGTYP *current, *head=NULL;

	srand(time(0)); 
	head = randomize();
	current = head;
	
 	int nr = 0;
	while(current!=NULL) {
		printf("\n Post nr %d : %d", nr++, current ->number);
		current = current->next;
	}
	
	head = add_first(head, rand()%10);
	current = head;
	
	while((current=head)!=NULL) {
		head = current->next;
		free(current);
	}

	printf("\n\n");
	system("PAUSE");
	return 0;
}


REGTYP* randomize(void) {
	
 	int nr, i = 0;
 	REGTYP *top=NULL, *old=NULL, *item=NULL;
	
	    for (i=0; i<=MAX; i++) {
	    	nr = rand() %10;
			item = (REGTYP*)malloc(sizeof(REGTYP));
			item -> number = nr;
			item -> next = top;
			top = item;
	}
	
	return(top);
}


REGTYP* add_first(REGTYP* temp, int data){
	
	REGTYP *first = malloc(sizeof(REGTYP));
	
	first -> number = data;
	first -> next = temp;
	
	return first;
}
