/*====================================
File name: exerc_1_4.c (or cpp) Date: 2014‐01‐22
Group Number: 3
Members that contributed:
	Patrik Bäckström
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESS 100
#define MIN_GUESS 1

void clearstdin(void) {
	char temp;
	while((temp=getchar())!='\n');
}

int main(int argc, char *args[]) {

	int guess = -1;

	srand(time(NULL));
	int correctGuess = rand() % 100 + 1;
	printf("\n%i\n", correctGuess);
	printf("Guess a number from 1 to 100: ");

	clearstdin();
	scanf("%d", &guess);

	if (isdigit(guess))
		printf("Guess: %i\n", guess);


	return 0;
}
