#include <stdio.h>

#define MAX 4

void pop(int *list) {
	int i;
	for (i=0; i<=sizeof(list); i++) {
		list[i] = list[i+1];
	}
	list[MAX] = -1;
}

int input(int *list, int number) {
	int i;
	
	if (list[MAX] != -1) {
		printf("Queue is full\n");
	}
	else {
		for (i=0; i<=sizeof(list); i++) {
			if (list[i] == -1) {
				list[i] = number;
				break;
			}
		}
	}
}

void init(int *list) {
	int i;
	
	for (i=0; i<=sizeof(list); i++) {
		*(list+i) = -1;
	}
}

int main(void) {
	
	int q[MAX];

	init(q);
	input(q, 1);
	input(q, 2);
	input(q, 3);
	input(q, 4);
	input(q, 5);
	pop(q);
	pop(q);
	input(q, 6);
	input(q, 7);

	int i;
	for (i=0; i<=MAX; i++) {
		printf("%d, ", q[i]);
	}
	
	return 0;
}
