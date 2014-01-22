/*====================================
File name: exerc_1_3.c (or cpp) Date: 2014‐01‐22
Group Number: 3
Members that contributed:
	Patrik Bäckström
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#define passwordMaxLength 50
#define encryptStep 13

int main(int argc, char *argv[]) {

	char password[passwordMaxLength] = {' '};
restart:
	printf("Password: ");
	fgets(password, passwordMaxLength, stdin);

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