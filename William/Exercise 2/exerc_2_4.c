#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

//credzz to gregzz

int main (int argc, char *argv[]) {

	char s1[MAX];
	char s2[MAX];

	strcpy(s1, argv[1]);
	strcpy(s2, argv[1]);
	
	int i;
	int j = 0;
	for (i=strlen(s1)-1; i>=0; i--) {
		 s2[j++] = s1[i];
	}
	
	if (strcmp(s1, s2)) {
		printf("True\n");
	} else {
		printf("False\n");
	}
}


