#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearstdin(void) {
	char temp;
	while((temp=getchar())!='\n');
}

int main() {

 	int num;
	srand(time(NULL));
	num = rand() % 100 + 1;
  	char input[3];
	int guess = 101;
	int correct = 0;

	printf("Press Enter to continue");
	
	while (correct == 0)
	{
		
		clearstdin();
  		printf("Enter a number between 0 and 100: \n");
		fgets(input, 3, stdin);

		guess = atoi(input);

		if (guess < num) {
			printf("You guessed %d! The correct number is higher\n", guess);
		}
		else if (guess > num) {
			printf("You guessed %d! The correct number is lower\n", guess);
		}
		else if (guess == num) {
			correct = 1;
		}
	}
	
	printf("You guessed correctly. The number was %d\n", guess);
	return 0;
}


