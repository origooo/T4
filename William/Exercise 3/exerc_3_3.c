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
	int nr = 0;
	REGTYP *akt_post, *head=NULL;
	srand(time(0)); // Random seed
	head = randomize();
	akt_post = head;
	
	while(akt_post!=NULL) {
		printf("\n Post nr %d : %d", nr++, akt_post ->number);
		akt_post=akt_post ->next;
	}
	
	while((akt_post=head)!=NULL) {
		head = akt_post->next;
		free(akt_post);
	}

	system("PAUSE");
	return 0;
}


REGTYP* randomize(void) {
	int nr, i=0;
	REGTYP *top, *old, *item;

	return(top);
}


REGTYP* add_first(REGTYP* temp, int data){
	// Adds a record first i list and set the field tal to data

}
