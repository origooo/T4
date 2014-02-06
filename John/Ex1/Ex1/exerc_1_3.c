/* ==================================== 
File name: exerc_1_3.c (or cpp) 
Date: 2013‐01-21
Group Number: 3
Members that contributed: 
John Burchell
Demonstration code: [<Ass code 1‐4> <abc>]        Important , No code no bonus ! 
====================================== */ 
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

void flushstdin();

int main(int argc, char *argv[]) 
{
	char word[MAX];


	while(1) {

		printf("Please enter a word\n");
		fgets(word, MAX+1, stdin);

		if(feof(stdin)) break;
		if(strlen(word) >= MAX) flushstdin();

		int i = 0;
		for(i = 0; i < MAX -1; i++) {

			if(isgraph(word[i]) && toupper(word[i]) >= 'A' && toupper(word[i]) <= 'M')		word[i] += 13;
			else if(isgraph(word[i]) && toupper(word[i]) >= 'M' && toupper(word[i]) <= 'Z')	word[i] -= 13;

		}

		printf("Encoded: %s\n", word);
	}
}


void flushstdin()
{
	char ch;
	while((ch = getchar()) != '\n');
}