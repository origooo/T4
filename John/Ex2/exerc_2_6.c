/* ==================================== 
File name: exerc_2_4.c (or cpp) 
Date: 2013‐01-23
Group Number: 03
Members that contributed: 
John Burchell
Patrik Backstrom
William Granli
Demonstration code: [<Ass code 1‐4> <abc>]        Important , No code no bonus ! 
====================================== */ 

#include <stdio.h>

#define MAX 5

int input(int *list, int number);
void init_queue(int *list);
void print_queue(int *list);
void remove(int *list);
void queue_status(int *list);

int main(int argc, char *argv[])
{	
	int list[MAX];
	init_queue(list);
	printf("Queue from start:\n");
	print_queue(list);
	printf("Queue after adding 7,8,9 in turn\n");
	input(list, 7);
	input(list, 8);
	input(list, 9);
	print_queue(list);
	printf("Queue after adding 21\n");
	input(list, 21);
	print_queue(list);
	printf("Queue after removing 7\n");
	remove(list);
	print_queue(list);
	printf("Querying the queue\n");
	queue_status(list);
	printf("Filling the queue\n");
	input(list, 9);
	input(list, 9);
	print_queue(list);
	queue_status(list);
	printf("Attempting to add to queue, this is the returned int: %d \n", input(list, 200));
	print_queue(list);
	remove(list);
	printf("Removing and attempting again, this is the returned int: %d \n", input(list, 200));

}

void print_queue(int *list)
{
	int i = 0;
	for(i = 0; i < MAX; i++)
		printf("%d ", list[i]);
	printf("\n");
}

int input(int *list, int number)
{
	 int i = 0;
	 for(i = 0; i < MAX; i++){
	 	if(*(list + i) == -1){
	 		*(list + i) = number;
	 		return 1;
	 	}
	 }

	 return 0;
}

void remove(int *list)
{
	int i = 0;
	*(list + i) = -1;

	for(i = 1; i < MAX; i++){
		*(list + i - 1) = *(list + i);
	}

	*(list + MAX-1) = -1;
}

void queue_status(int *list)
{
	int i = 0;
	for(i = 0; i < MAX; i++){
		if(*(list + i) == -1){
			printf("Queue not full\n");
			break;
		}
	}
	if(i == MAX)
		printf("Queue full\n");
}

void init_queue(int *list)
{
	int i = 0;
	for(i = 0; i < MAX; i++)
		*(list + i) = -1;
}