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

int main(int argc, char *argv[])
{
	printf("Please enter a number between 1 and 10\n");
	int num;
	//Uses standard input, a string which expects a digit and a reference to the
	//Variable which will store the given inputs.
	fscanf(stdin, "%d", &num);

	printf("Number entered: %d \n", num);	

	if(num == 1)
		printf("Sentence one\n");
	else if(num == 2)
		printf("Sentence Two\n");
	else if(num == 3)
		printf("Sentence Three\n");
	else if(num == 4)
		printf("Sentence Four\n");
	else if(num == 5)
		printf("Sentence Five\n");
	else if(num == 6)
		printf("Sentence Six\n");
	else if(num == 7)
		printf("Sentence Seven\n");
	else if(num == 8)
		printf("Sentence Eight\n");
	else if(num == 9)
		printf("Sentence Nine\n");
	else if(num == 10)
		printf("Sentence Ten\n");
	else if(num == 0)
		printf("Quitting");
	else 
		printf("Not a number between 0 and 10");

	return 0;
}	