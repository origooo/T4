/* ==================================== 
File name: exerc_2_3.c (or cpp) 
Date: 2013‐01-23
Group Number: 03
Members that contributed: 
John Burchell
Patrik Backstrom
William Granli
Demonstration code: [<Ass code 1‐4> <abc>]        Important , No code no bonus ! 
====================================== */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_string(char *string1, char *string2);
int compare_library(char *string1, char *string2);

#define MAX 100

int main(int argc, char *argv[])
{

	if(argc < 3) {
		printf("please enter more than two arguments\n");
		exit(1);
	}

	char *string1 = argv[1];
	char *string2 = argv[2];

	printf("String 1: %s\nString 2: %s\n", string1, string2);

	printf("Comparing via self-written method\n");
	
	if(compare_string(string1, string2))
		printf("String 1 and 2 are the same\n");
	else 
		printf("String 1 and 2 are not the same\n");

	printf("Comparing via string.h method\n");
	
	//strcmp returns 0 if both are the same.
	if(strcmp(string1, string2) == 0)
		printf("String 1 and 2 are the same\n");
	else
		printf("String 1 and 2 are not the same\n");
}


int compare_string(char *string1, char *string2)
{
	int i = 0;

	if(strlen(string1) == strlen(string2)) {

		while(strlen(string1) >= i) {

			if(*(string1 + i) == *(string2 + i))
				i++;
			else
				//Not the same
				return 0;
		}

		if(strlen(string1) == i)
			//The same
			return 1;
	}

	else
		//Not the same length
		return 0;

}

