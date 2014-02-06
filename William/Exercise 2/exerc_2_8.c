//didnt bother to polish this to 100 %
//it's stupid

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;
int play = 1;

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

  srand(time(0));		/* Setup random */

  printf("Welcome to NIM ...\n");

  pile = MAX_COINS;		/* Set start values (= init) */
  player = HUMAN;

  while(play == 1) {

    printf("Det ligger %d  mynt i boeghoegen\n", pile);

    if (player == HUMAN) {
      n_coins = human_choice(pile);
    }
	else {
      n_coins = computer_choice(pile);
	  printf("- Jag tog %d\n", n_coins);
    }
    pile -= n_coins;
    player = toggle(player);

    if(pile<=1){
    	write_winner(player);
		play_again();
    }
  }



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
	clear_stdin();
	printf("Enter 1-3\n");
	scanf("%d", &pile);
	return pile;
}

int computer_choice(int pile)
{

	pile = (rand() % 3) + 1;
	return pile;

}

void write_winner(int player )
{
	if (player==1) {
		printf("HUMAN HAS WON!!!!!!!!!!");
	}
	else {
		printf("COMPUTER HAS WON!!!!!!!!!!");
	}
}

int play_again()
{
	char yesno;
	printf("Do you want to play again? Y/N");
	scanf("%c", &yesno);
	
	if (yesno=='N') {
		play = 0;
	}
}

int toggle( int player )
{
	if (player == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
