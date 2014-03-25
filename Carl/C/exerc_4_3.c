/*====================================
File name: exerc_4_2.c (or cpp) Date: 2014‐02-14
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: 57030
======================================*/

#define IN_PORT 0x0400
#define OUT_PORT 0x0402
#define REG8(x) *((unsigned char *)(x))
#define BIT7 0x80

int main() {

	unsigned int step = 0;
	unsigned char output = 0x21;
	int delay;

	while (1) {
		if (REG8(IN_PORT) & BIT7) {
			for (delay = 0; delay < 100; delay++); // Added to delay...
			REG8(OUT_PORT) = (output << step) | (output >> 8 - step);
			7 == step ? step = 0 : step++;
		}else {
			REG8(OUT_PORT) = 0x00;
			step = 0;
		}
	}
	return 0;
}
