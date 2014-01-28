/* ==================================== 
File name: exerc_2_1.c (or cpp) 
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

void without_copy(char *input, char *string_one);
void with_copy(char *input, char *string_two);
void readfile();


#define MAX 100

int main(int argc, char *argv[])
{
	char input[MAX], string_one[MAX], string_two[MAX];

	printf("First using input\nPlease input a string:\n");

	fgets(input, MAX+1, stdin);

	without_copy(input, string_one);
	with_copy(input, string_two);

	printf("Reading from a file:\n");
	readfile();
}


void without_copy(char *input, char *string_one)
{

	printf("Before copy: %s\n", string_one);

	int i = 0;
	for(i = 0; i < MAX - 1; i++) {
		string_one[i] = input[i];
	}

	printf("Copied using my copy: %s\n", string_one);
}
void with_copy(char *input, char *string_two)
{
	printf("Before copy: %s\n", string_two);

	strcpy(string_two, input);

	printf("Copied with library: %s\n", string_two);

}

void readfile()
{
	FILE *file;
	char filename[MAX], string1[MAX], string2[MAX];

	printf("Please input the filename:\n");
	scanf("%s", filename);

	char string[MAX];

	if((file = fopen(filename, "r")) == NULL) {
		printf("Error: Unable to open %s, please make sure the filename is correct\n", filename);
		return;
	}

	file = fopen(filename, "r");

	fgets(string, MAX, file);

	printf("This was read from the file:\n%s\n", string);

	with_copy(string, string1);
	without_copy(string, string2);

	fclose(file);
}
