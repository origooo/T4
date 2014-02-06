#include <stdio.h>

#define MAX 3

//int *compare (int *first[], int *second[]);


int compare (char first[], char second[]) {

	int i;
	for (i=0; i<MAX; i++) {
		if (first[i] != second[i]) {
			return 0;
		}
		else {
			return 1;
		}
	}
}

int main(int argc, char *argv[]) {
	
	if (argc == 3) {
		if (compare(argv[1], argv[2])) {
			printf("The strings are equal");
		}
		else {
  			printf("The strings are not equal");
		}
	}
	
	return 0;
}



