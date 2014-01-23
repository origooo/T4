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
void readfile(FILE *name);

#define MAX 100

int main(int argc, char *argv[])
{
	char input[MAX], string_one[MAX], string_two[MAX];

	printf("First using input\nPlease input a string:\n");

	fgets(input, MAX+1, stdin);

	without_copy(input, string_one);
	with_copy(input, string_two);

	printf("Reading from a file:\n");
	FILE *file;
	readfile(file);
}


void without_copy(char *input, char *string_one)
{
	int i = 0;
	for(i = 0; i < MAX - 1; i++) {
		string_one[i] = input[i];
	}

	printf("Copied without: %s\n", string_one);
}
void with_copy(char *input, char *string_two)
{
	strcpy(string_two, input);

	printf("Copied with: %s\n", string_two);

}

void readfile(FILE *name)
{

	char filename[] = "test.txt";
	name = fopen(filename, "r");

	char string[MAX];

	if(name == NULL)
		printf("Error! Unable to open %s", filename);

	fgets(string, MAX, name);

	printf("This was read from the file:\n%s", string);

	fclose(name);
}
