/* ==================================== 
File name: exerc_2_4.c (or cpp) 
Date: 2013‐01-23
Group Number: 03
Members that contributed: b
John Burchell
Patrik Backstrom
William Granli
Demonstration code: [<Ass code 1‐4> <abc>]        Important , No code no bonus ! 
====================================== */ 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>     
#include<ctype.h>

#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

int human_choice(int pile);
void write_winner( int player );
int play_again();
int computer_choice(int pile);
int toggle( int player );
void clear_stdin();

int main()
{
  int pile,			/* This is how many coins we have */
    player,			/* Who is playing? */
    n_coins;			/* Number of coins taken */
  
  srand( time(0) );		/* Setup random */

  printf("Welcome to NIM by John Burchell");
 
  
  pile = MAX_COINS;		/* Set start values (= init) */
  player = HUMAN;

  while( true ) {	

    printf("There are %d coins in the pile\n", pile );
    
    if( player == HUMAN ){
      n_coins = human_choice(pile);      
    }else{
      n_coins = computer_choice(pile);
      printf("- I took %d\n", n_coins);      
    }
    pile -= n_coins;
    player = toggle( player );
      
    if( pile <= 1 ){
  		write_winner( player );
  		if(play_again() == true){
  			printf("\nPlaying again!\n");
  			pile = MAX_COINS;		
  			player = HUMAN;
  		} else {
  			printf("\nQuitting..\n");
  			break;
  		}
    }
  }
  
  printf("\nFinished.\n");
  return 0;
}

void clear_stdin()
{
  while( getchar() != '\n' ){
    ;
  }
}

int human_choice(int pile)
{
	while(1) {
		printf("Please specify an amount of coints to take"
			" between 1-3\n");
		int output = 0;
		char input[1];
		fgets(input, 2, stdin);
		clear_stdin();
		output = input[0] - '0';

		if(output <= 3 && output >= 1 && output <= pile){
			return output; 
		} else {
			printf("Must take only between 1-3 coins or less "
				" than what remains in the pile.\n");
		}
	}
}

int computer_choice(int pile)
{
	if(pile <= 4){

		if(pile == 4){
			return 3;
		}
		else if(pile == 3){
			return 2;
		}
		else if(pile == 2){
			return 1;
		}
	}

	return rand() % 3 +1;
}

void write_winner(int player )
{
	player == 1 ? printf("Well done, you beat the computer!\n")
 		        : printf("Oh no, the computer won!\n");
}

int play_again()
{
	char answer;
	printf("Do you wish to play again? (Y/N):\n");
	scanf("%c", &answer);
	clear_stdin();
	return toupper(answer) == 'N' ? 0 : 1;
}

int toggle( int player )
{
	return player == 1 ? 0 : 1;
}
