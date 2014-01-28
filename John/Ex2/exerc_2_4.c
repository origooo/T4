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
#include <ctype.h>
#include <string.h>

#define MAX 10

int is_palindrome(char *word);

int main(int argc, char *argv[])
{
	char word[MAX];
	printf("Please enter a potential pallindrome of up to %d letters\n", MAX);
	fgets(word, MAX+1, stdin);
	
	if(is_palindrome(word) == 0) {
		printf("Not a pallindrome\n");
	}

	else 
		printf("It is a pallindrome!\n");

}

int is_palindrome(char *word)
{
	char *start = word;
	char *end = &word[strlen(word) - 2];

	int i = 0;
	while(*(start+i) == *(end-i)) {
		i++;
	}
	return (*start == *end) ? 1 : 0;
}