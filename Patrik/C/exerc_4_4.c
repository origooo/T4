/*====================================
File name: exerc_4_2.c (or cpp) Date: 2014‐02-14
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 52215
4:5 53070
======================================*/

#include <stdio.h>

#define KBD_DATA 0x09C0
#define KBD_STATUS 0x09C1
#define REG8(x) *((unsigned char*) (x))
#define BIT7 0x80

int main() {
	while (1) {
		unsigned char input = REG8(KBD_DATA);
		if (!(input & BIT7)) { // If key is pressed!
			if (input > 0x09) { // is letter
				putchar(input+55); // Add 55 for ASCI capital letter A-F
			} else {
				putchar(input+48); // Add 48 for ASCI digits
			}
		}
	}
	return 0;
}
