
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

void create_random(int *number);
void count_frequency(int *number, int *number2);
void draw_histogram(int *number);
void make_x(int number);

int main(int argc, char *argv[])
{
	int table[MAX], n;
	//Needs to be initialized to 0 so i can add correctly.
	int frequency[MAXNUMBER] = {0};

	//set pointers to them. Not really needed as they are pointers already (technically)
	int *table_p = table;
	int *frequency_p = frequency;

	create_random(table_p);
	count_frequency(frequency_p, table_p);
	draw_histogram(frequency_p);


	return 0;
}

void count_frequency(int *freq, int *table)
{

	int i = 0;
	int j = 0;

	for(i = 0; i < MAXNUMBER; i++){
		*(freq + *(table+i)) +=1;
	}
	
}

void draw_histogram(int *number)
{

	int i = 0;

	for(i = 0; i < MAXNUMBER; i++){
		if(number[i] > 0){
			printf("Number %d: ", i);
			make_x(number[i]);
		}
	}
}


void make_x(int number)
{

	char x[number];
	int i = 0;
	for(i = 0; i < number; i++)
		x[i] = 'X';

	//Don't forget terminator, was getting weird results without!
	x[i] = '\0';
	printf("%s\n", x);

}

void create_random(int *number)
{

	srand(time(NULL));
	int i = 0;
	for(i = 0; i < MAX; i++){
		*(number+i) = rand() % MAXNUMBER;
	}
}