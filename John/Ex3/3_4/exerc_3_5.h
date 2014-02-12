#ifndef __exerc_3_5_
#define __exerc_3_5_


#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

#define FILENAME "test.bin"


typedef struct { 
        char firstName[20]; 
        char familyName[20]; 
        char pers_number[13]; 
}PERSON; 


void printfileAlabetic(void); //Search and print alphabetically
void sort_alpha(PERSON *list, int count, int number);
void printStruct(PERSON toPrint);

#endif