/* ==================================== 
File name: exerc_x_y.c (or cpp) 
Date: 2013‐mm‐dd 
Group Number: 
Members that contributed: 
xxxxxxx xxxxxxxx 
yyyyyyy yyyyy 
zzzzz  zzzzzz 
Demonstration code: [<Ass code 1‐4> <abc>]        Important , No code no bonus ! 
====================================== */ 

#include <stdio.h>
#include <ctype.h>

#define MAX 10

int main(int argc, char *argv[]) 
{

	char input[MAX];
	printf("Please enter up to %d characters\n", MAX);
	fgets(input, sizeof(input), stdin);

	int i = 0;
	int count = 0;

	for(i = 1; i < MAX+1; i++) {

		if(isspace(input[i]) && isalnum(input[i-1]))
			count++;
		if(i == MAX-1 && !isspace(input[i]))
			count++;
	}

	printf("You entered: %d words with a limit of %d characters\n", count, MAX);

	
}