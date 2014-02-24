/*====================================
File name: exerc_1_4.c (or cpp) Date: 2014‐01‐23
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
#define MAX_NUMBER_OF_GUESSES 5

void clearstdin(void);

int main(int argc, char *args[]) {

	int guess, guesses, success=0;

playAgain:

	srand(time(NULL));
	int correctGuess = rand() % 100 + 1;
	guesses = 0;
	//printf("\n%i\n", correctGuess);
	printf("Guess a number from 1 to 100: ");

	do {
		scanf("%d", &guess);
		clearstdin();
		if (guess >= MIN_GUESS && guess <= MAX_GUESS) {
			if (guess == correctGuess) {
				success = 1;
				goto breakGameLoop;
			} else if (guess != correctGuess && guesses == MAX_NUMBER_OF_GUESSES-1)
				goto breakGameLoop;
			else if (guess < correctGuess)
				printf("%i is to low! Guess again: ", guess);
			else if (guess > correctGuess)
				printf("%i is to high! Guess again: ", guess);
		} else {
			printf("That's not a proper guess... Guess again: ");
		}
		guesses++;

	} while (guess != correctGuess);

breakGameLoop:
	if (success==1)
		printf("\n%i is correct, and you guessed %i/%d times! Congradulations, MF!\n\n", guess, guesses, MAX_NUMBER_OF_GUESSES);
	else
		printf("\nYou're out of guesses!\n\n");

	printf("Play again (y/n): ");
	if (getchar() == 'y')
		goto playAgain;

	return 0;
}

void clearstdin(void) {
	char temp;
	while((temp=getchar())!='\n');
}