/*====================================
File name: exerc_2_7.c (or cpp) Date: 2014‐01‐28
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 56006
======================================*/

#include <stdio.h>

#define PN_LENGTH 11 // To allow 10 digits and '\0'

void readPersnr(char*);
int controlDigit(const char*);

int main(int argc, char *argv[]) {

	char pn[PN_LENGTH];

	do {
		readPersnr(pn);
		if ('q' == pn[0]) {
			printf("\nExiting...\n\n");
			break;
		} else {
			1 == controlDigit(pn) ? printf("\n\t# Personal number %10s is valid!\n", pn) : printf("\n\t# Invalid personal number!\n");
		}
	} while (1);

	return 0;
}

int controlDigit(const char *persnr) {

	int year, month, day, cDigit;
	year = (*persnr - 48) * 10 + (*(persnr + 1) - 48);
	month = (*(persnr + 2) - 48) * 10 + (*(persnr + 3) - 48);
	day = (*(persnr + 4) - 48) * 10 + (*(persnr + 5) - 48);
	cDigit = (*(persnr + 9) - 48);

	int checksum = 0;
	if (month > 0 && month < 13) {
		if (day > 0 && day < 32) {
			for (int i = 0; i < PN_LENGTH - 2; i++) {
				0 == (i % 2) ? 
					(checksum += ((*(persnr + i) - 48) * 2 / 10 + (*(persnr + i) - 48) * 2 % 10) ) :
					 (checksum += (*(persnr + i) - 48));
			}
		}
	}
	return ((10 - (checksum % 10)) % 10) == cDigit ? 1 : 0;
}

void readPersnr(char *person) {
	printf("\n\t# Input personal number: ");
	int i = 0;
	char c;
	while ((c = getchar()) != '\n' && i < PN_LENGTH-1) {
		*(person + i) = c;
		i++;
	}
	*(person + PN_LENGTH - 1) = '\0';
}