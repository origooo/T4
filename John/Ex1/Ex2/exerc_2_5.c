
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

void create_random(int *number);
void count_frequency(int *number, int *number2);
void draw_histogram(int *number);

int main(int argc, char *argv[])
{
	int table[MAX], n;
	int frequency[MAXNUMBER];

	int *table_p = table;
	int *frequency_p = frequency;

	create_random(table_p);
	count_frequency(frequency_p, table_p);

	int i = 0;
	for(i = 0; i < MAXNUMBER; i++){
		printf("Number %d appears: %d times\n", i, *(table_p + i));
	}

	return 0;
}

void count_frequency(int *table, int *freq){

	int i = 0;
	int j = 0;
	for(i = 0; i < MAXNUMBER; i++){
		for(j = 0; j < MAX; j++){
			if(i == *(table + j))
				*(freq+i) += 1;
		}
	}
}

void draw_histogram(int *number){

}

void create_random(int *number){
	srand(time(NULL));
	int i = 0;
	for(i = 0; i < MAX-1; i++){
		*(number+i) = rand() % MAXNUMBER;
	}
}