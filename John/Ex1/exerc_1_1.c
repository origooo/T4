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
	//Const to imply that i don't want them to be changed ever.
	//Not really needed for this but a good habit none the less
	const char *strings[] = {"One", "Two", "Three", "Four", "Five", "Six",
				  "Seven", "Eight", "Nine"};

	printf("Please enter a number between 1 and 10, enter 0 to exit.\n");

	int num;
	scanf("%d", &num);

	num == 0 ? printf("Exiting..") : printf("Number entered: %s \n", strings[num]);	

	return 0;
}	