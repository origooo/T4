#include <stdio.h>

enum DIRECTION {N,E,S,W};

typedef struct {
	int xpos;
	int ypos;
	enum DIRECTION dir;
}ROBOT;

int main(void) {

	ROBOT ex;

	//declare start pos and dir
	ex.xpos = 0;
	ex.ypos = 0;
	ex.dir = 'N';

	printf("Starting position: X=%d, Y=%d, dir=%c \n----------------\n", ex.xpos, ex.ypos, ex.dir);
	
	printf("Enter M to move forward in %c direction. \nEnter N, E, S or W to change direction\n", ex.dir);
	
	
	while (1) {
	
	char in;
 	scanf("%c", &in);

		if (in=='M') {
			if (ex.dir=='N') {
				ex.ypos++;
			}
			else if (ex.dir=='E') {
				ex.xpos++;
			}
			else if (ex.dir=='S') {
				ex.ypos--;
			}
			else if (ex.dir='W') {
				ex.xpos--;
			}
		}
		else if (in=='T') {
	  		if (ex.dir=='N') {
				ex.dir='E';
			}
			else if (ex.dir=='E') {
				ex.dir='S';
			}
			else if (ex.dir=='S') {
				ex.dir='W';
			}
			else if (ex.dir='W') {
				ex.dir='N';
			}

		}

	printf("Position after moving: X=%d, Y=%d, dir=%c \n----------------\n",
	ex.xpos, ex.ypos, ex.dir);
		
  	int c;
	while ((c = getchar()) != '\n' && c != EOF);

}

	return 0;
}
