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
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_NUMBER  100
#define MIN_NUMBER  1

void run();
int generate_number();
void flushstdin();


int main(int argc, char *argv[])
{
	int playing = 1;

	while(playing){
		run();
		printf("Do you wish to play again(y\\n)?\n");
		char reply[1];
		fscanf(stdin, "%s", reply);

		if(strcmp(reply, "y") == 0){
			printf("Playing again!\n");
			playing = 1;
		}

		else if(strcmp(reply, "n") == 0) {
			printf("Ok, thanks for playing!\n");
			playing = 0;
		}

		else {
			printf("You said something other than y or n. Stopping.\n");
			playing = 0;
		}
	}
}

void run()
{
	int guess, guesses;
	int number = generate_number();

	//Uncomment to see number.
	//printf("%d\n", number);

	while(guess != number){

		printf("Please guess a number:\n");
		scanf("%d", &guess);
		flushstdin();

		if(guess < number && guess > MIN_NUMBER) {
			printf("Your guess was lower than the number!\n");
			guesses++;

		}
		else if(guess > number && guess < MAX_NUMBER) {
			printf("Your guess was higher than the number!\n");
			guesses++;

		}
		else if(guess == number)
			printf("Correct!\nGuessed in %d guesses\n", guesses);

		else
			printf("Please enter a real number.\n");

	}

}

int generate_number()
{	
	//Seed
	srand(time(NULL));
	return rand()% MAX_NUMBER;
}

void flushstdin()
{
	char ch;
	while((ch = getchar()) != '\n');
}