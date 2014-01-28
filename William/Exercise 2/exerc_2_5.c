#include <stdlib.h>
#include <stdio.h>

#define MAX 50
#define MAX_NUMBER 20

int main(void) {
	
	int table[MAX];
	int frequency[MAX_NUMBER] = {0};
	
 	int num, i;
	srand(time(NULL));
	for (i=0; i<=MAX; i++) {
	num = rand() % MAX_NUMBER+1;
	table[i] = num;
	}
	
	for (i=0; i<=MAX; i++) {
		frequency[table[i]] += 1;
	}

	char x[] = {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', '\0'};

	int j;
	for (i=0; i<=MAX_NUMBER; i++) {
		printf("\n%d==", i);
		for (j=0; j<=frequency[i]; j++) {
			printf("%c ", x[frequency[i]]);
		}
	}
}

