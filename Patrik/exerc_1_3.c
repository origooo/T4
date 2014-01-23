/*====================================
File name: exerc_1_3.c (or cpp) Date: 2014‐01‐22
Group Number: 3
Members that contributed:
	Patrik Bäckström
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#define passwordMaxLength 9 // Actuall pw length is 8 characters. Adding one index for '\n'
#define encryptStep 13

char password[passwordMaxLength] = {' '};


/*
Using this instead of fgets().
*/
void getString(void) {
	char c;
	int n;
	while (((c=getchar())!='\n') && n < passwordMaxLength-1) { // -1 leaves room for '\n'
		password[n] = c;
		n++;
	}
	password[n] = '\n';
}

void clearstdin(void) {
	char temp;
	while((temp=getchar())!='\n');
}

int main(int argc, char *argv[]) {

restart:
	printf("Password: ");
	getString();
	clearstdin();
	//fgets(password, passwordMaxLength, stdin);
	printf("Encrypted: ");
	for (int i = 0; i < sizeof(password) / sizeof(char); i++) {
		if ((int)password[i] >= (int)'a' && (int)password[i] <= (int)'m') {
			printf("%c", (int)password[i]+encryptStep);
		} else if ((int)password[i] >= (int)'n' && (int)password[i] <= (int)'z') {
			printf("%c", (int)password[i]-encryptStep);
		} else if ((int)password[i] >= (int)'A' && (int)password[i] <= (int)'M') {
			printf("%c", (int)password[i]+encryptStep);
		} else if ((int)password[i] >= (int)'N' && (int)password[i] <= (int)'Z') {
			printf("%c", (int)password[i]-encryptStep);
		}
	}

	printf("\n");
	goto restart;

	return 0;
}