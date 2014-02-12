/* ==================================== 
File name: exerc_3_1.c (or cpp) 
Date: 2013‐01-23
Group Number: 03
Members that contributed: 
John Burchell
Patrik Backstrom
William Granli
Demonstration code: [25593]        Important , No code no bonus ! 
====================================== */ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum DIRECTION{N,E,S,W};

typedef struct {
	int xpos;
	int ypos;
	enum DIRECTION dir;
} ROBOT;

void move(ROBOT *bot);
void turn(ROBOT *bot);
void startpos(ROBOT *bot);
void location(ROBOT *bot);
void read_instructions(ROBOT *bot);
void clear_stdin();

#define MOVE_SPEED 5


int main(int argc, char *argv[])
{
	char instructions;

	//Alloc memory for robot
	ROBOT *bot = malloc(sizeof(ROBOT));
	while(1) {
		startpos(bot);
		location(bot);
		printf("Please give the robot some instructions\n"
			"t for turn, m for move +5 in current facing\n");
		read_instructions(bot);
		printf("Bot after moving\n");
		location(bot);
		//Check they want to play again	
		if(move_again()==1) break;
	}

	free(bot);

	return 0;
}

int move_again()
{
	printf("Q to stop or any other key to continue...\n");
	char temp;
	scanf("%c", &temp);
	//1 for quit, 0 for continue.
	return toupper(temp) == 'Q' ? 1 : 0;
}

void startpos(ROBOT *bot)
{
	char dir;
	printf("Please input the desired start co-ordinates\n");
	printf("X:");
	scanf("%i", &bot->xpos);
	clear_stdin();
	printf("Y:");
	scanf("%i", &bot->ypos);
	clear_stdin();
	printf("0 = North, 1 = East, 2 = South, 3 = West:\n");
	scanf("%c", &dir);
	bot->dir = dir  - '0';
}

void read_instructions(ROBOT *bot)
{
	char temp;
	clear_stdin();
	while((temp = getchar()) != '\n'){

		if(temp == 't'){
			turn(bot);
		}
		else if(temp == 'm') {

			move(bot);
		}else {
			;
		}
	}
}
void move(ROBOT *bot)
{

	if(bot->dir == N){
		bot->ypos += MOVE_SPEED;
	}
	else if(bot->dir == E){
		bot->xpos  += MOVE_SPEED;
	}
	else if(bot->dir == S){
		bot->ypos -= MOVE_SPEED;
	}else {
		bot->xpos -=MOVE_SPEED;
	}
}

void turn(ROBOT *bot)
{
	bot->dir = (++bot->dir) % 4;
}

void location(ROBOT *bot)
{
	//Just here for printing what the enums are.
	char enums[] = {'N', 'E', 'S', 'W'};
	printf("Robot at: \n\tX:%d\n\tY:%d\n\tFacing:%c\n",
		bot->xpos, bot->ypos, enums[bot->dir]);
}

void clear_stdin()
{
  while( getchar() != '\n' ){
    ;
  }
}