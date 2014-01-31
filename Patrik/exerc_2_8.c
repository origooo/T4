/*====================================
File name: exerc_2_8.c (or cpp) Date: 2014‐01‐29
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 54917
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 

#define MAX_COINS 13
#define MIN_CHOICE 1
#define MAX_CHOICE 3

const int HUMAN = 0;
const int COMPUTER = 1;

int human_choice(int pile);
void write_winner(int player);
int play_again();
int computer_choice(int pile);
int toggle( int player );
void clear_stdin();

int main() {

	srand(time(0));

	do {
		int pile = MAX_COINS, player = HUMAN, n_coins;
		printf("\n\t# Welcome to NIM!\n");

		while(1) {	

			printf("\n\t# The stack has %d coins. Pick 1-3 coins!\n", pile);

			if(player == HUMAN){
				n_coins = human_choice(pile);      
			} else {
				n_coins = computer_choice(pile);
				printf("\t>>> Computer picked %d\n", n_coins);      
			}
			pile -= n_coins;
			player = toggle(player);
			
			if(pile <= 1){
				printf("\n\t# Oops! Just %i coin left!\n", pile);
				break;
			}
		}
		write_winner(player);
		clear_stdin();  
	} while (play_again());

	printf("\nExiting...\n\n");

	return 0;
}

void clear_stdin() {
	while(getchar() != '\n');
}

int human_choice(int pile) {
	printf("\t>>> Pick 1-3 coins: ");
	int choice = 0;
	scanf("%i", &choice);
	while (!(choice >= MIN_CHOICE && choice <= MAX_CHOICE && choice <= pile)) {
		printf("\t>>> Try again: ");
		scanf("%i", &choice);
	}
	return choice;
}

int computer_choice(int pile) {
	int choice = 0;
	pile <= MAX_CHOICE ? (choice = pile - 1) : (choice = rand() % 3 + 1);
	return choice;
}

void write_winner(int player) {
	0 == player ? printf("\t*** COMPUTER won!\n") : printf("\t*** YOU won!\n");
}

int play_again() {
	printf("\nPlay again? (y/n): ");
	return 'n' == tolower(getchar()) ? 0 : 1;
}

int toggle(int player) {
	return 1 == player ? 0 : 1;
}