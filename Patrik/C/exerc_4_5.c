/*====================================
File name: exerc_4_5.c (or cpp) Date: 2014-02-18
Group Number: 3
Members that contributed:
        John Burchell,
        Patrik Bäckström,
        William Granli
Demonstration code: 53070
======================================*/

#include <stdio.h>
 
#define BIT7 0x80
#define OUT 0x09C0 //Rows
#define IN 0x09C1  //Cols
#define REG8(x) *((unsigned char *)(x))


int main( void) {

while(1){

	int i,j,val;
	for(i = 0; i < 4; i++){
		REG8(OUT) = 0x01 << i;
		for(j = 0; j < 4; j++){
		if(!((REG8(IN)) & (0x01 << j))){
			val = 15 - (3-i + j*4);
			
			if(val > 0x09) {
				putchar(val + 55);
			} else {
				putchar(val + 48);
			}
		}
	}
	}
	
}
return(0);
}

