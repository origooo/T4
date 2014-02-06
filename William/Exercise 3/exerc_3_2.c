#include <stdio.h>

int size;

void print(int tab[], int size) {
	
 	printf("Sorted array:\n");
	int j=0;
	for(j=0; j<=size-1; j++) {
 		printf("%d, ", tab[j]);
	}
}


void sort(int n, int *tab) {

	int i = n;
	int min = tab[n];
	int pos;

	for (i; i<size; i++) {
		if (tab[i]<min) {
			min = tab[i];
			pos = i;
		}
	}

	if (min<tab[n]) {
		int temp = tab[pos];
		tab[pos] = tab[n];
		tab[n] = temp;
	}

	n++;
	if (n != size-1) {
		sort(n, tab);
	}
	else {
		print(tab, size);
	}
}

int search(int number, int tab[], int size) {
	int i = 0;
	while (i != size+1) {
		if (tab[i]==number) {
			printf("%d is in the array\n", number);
			break;
		} else if (tab[i]!=number && i==size) {
			printf("%d is not in the array\n", number);
		}
		i++;
	}
}

int main(void) {
	int tab[] = {1, 3, 2, 9, 5, 4, 6,
				20, 9,1, 3, 2, 4, 6, 5};
	int number = 4;
	size = sizeof(tab) / sizeof(int);
	
	printf("Initial array:\n");
	int j=0;
	for(j=0; j<=size-1; j++) {
 	printf("%d, ", tab[j]);
	}
	printf("\n");

	search(number, tab, size);
	
	sort(0, tab);
	
	return 0;
}
