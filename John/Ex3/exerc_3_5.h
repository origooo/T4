#ifndef __exerc_3_5_
#define __exerc_3_5_

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

typedef struct { 
        char firstName[MAX_NAME]; 
        char familyName[MAX_NAME]; 
        char pers_number[MAX_PSN]; 
}PERSON; 

void printfileAlabetic(void); //Search and print alphabetically
void sort_alpha(PERSON *list, int count, int number);
void printStruct(PERSON toPrint[], int count);

#endif