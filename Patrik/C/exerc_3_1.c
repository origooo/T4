/*====================================
File name: exerc_3_1.c (or cpp) Date: 2014‐01‐30
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#include <ctype.h>

#define MAX_INSTRUCTIONS 10

void clearstdin(void);
int runAgain();
void enterToContinue();
void move();
void turn();

enum DIRECTION{N,E,S,W};

typedef struct {
	int xpos;
	int ypos;
	enum DIRECTION dir;
} ROBOT;

int main(int argc, char *argv[]) {

	ROBOT nao;
	char instructions[MAX_INSTRUCTIONS];
	char tempDir;
	char dirMap[] = {'N','E','S','W'};

	do {

		printf("\n\n\t# Supply starting coordinates.\n");
		printf("\tX >>> ");
		scanf("%i", &nao.xpos);
		printf("\tY >>> ");
		scanf("%i", &nao.ypos);
		printf("\t# Give starting direction (N/E/S/W).\n");
		printf("\t>>> ");
		clearstdin();
		scanf("%c", &tempDir);
		for (int i = 0; i < 4; i++) {
			if (tempDir == dirMap[i]) {
				nao.dir = i;
			}
		}
		printf("\n\t# Robot starts @ (%i,%i), facing %c.\n", nao.xpos, nao.ypos, tempDir);

		clearstdin();
		enterToContinue();

		printf("\t#############################################"
			"\n\t#                                           #"
			"\n\t#  Give one or more instructions (max %i)   #"
			"\n\t#-------------------------------------------#"
			"\n\t#                                           #"
			"\n\t# m = move one step in current direction,   #"
			"\n\t# t = turn 90 degrees clockwise,            #"
			"\n\t#                                           #"
			"\n\t# Example: mttmmtm (starting (0,0), facing  #"
			"\n\t# North), results in ROBOT moving to        #"
			"\n\t# (-1,-1), facing West.                     #"
			"\n\t#                                           #"
			"\n\t#############################################\n", MAX_INSTRUCTIONS);

		printf("\n\t>>> ");
		scanf("%s", &instructions[0]);

		for (int i = 0; i < MAX_INSTRUCTIONS; i++) {
			//printf("xpos: %i, ypox: %i, dir: %i\n", nao.ypos, nao.xpos, nao.dir);
			'm' == instructions[i] ? move(&nao) : 0;
			't' == instructions[i] ? turn(&nao, &tempDir) : 0;
		}

		printf("\n\t# Robot is now @ (%i,%i), facing %c.\n", nao.xpos, nao.ypos, tempDir);
		clearstdin();
	} while (runAgain());

	printf("\n\n\tNuke nuke...\n\n");

	return 0;
}

void move(ROBOT *nao) {
	switch(nao->dir) {
		case 0: nao->ypos++; break;
		case 1: nao->xpos++; break;
		case 2: nao->ypos--; break;
		case 3: nao->xpos--; break;
		default: break;
	}
}

void turn(ROBOT *nao, char *newDir) {
	switch(nao->dir) {
		case 0: nao->dir = (nao->dir+1) % 4; *newDir = 'E'; break; // n
		case 1: nao->dir = (nao->dir+1) % 4; *newDir = 'S'; break; // e
		case 2: nao->dir = (nao->dir+1) % 4; *newDir = 'W'; break; // s
		case 3: nao->dir = (nao->dir+1) % 4; *newDir = 'N'; break; // w
		default: break;
	}
}

int runAgain() {
	printf("\n\tRun again? (y/n)");
	printf("\n\t>>> ");
	return 'n' == tolower(getchar()) ? 0 : 1;
}

void enterToContinue() {
	printf("\n\t\t>>> Press ENTER to continue <<<\n");
	int enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
}

void clearstdin(void) {
	char temp;
	while((temp=getchar())!='\n');
}