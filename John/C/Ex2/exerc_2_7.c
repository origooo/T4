/* ==================================== 
File name: exerc_2_4.c (or cpp) 
Date: 2013‐01-23
Group Number: 03
Members that contributed: b
John Burchell
Patrik Backstrom
William Granli
Demonstration code: [<Ass code 1‐4> <abc>]        Important , No code no bonus ! 
====================================== */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SSN_LEN 12

struct Ssn {

	int year;
	int month;
	int day;
	int digits;
	int check;
};

void readPerson(char *person);
void clearInput();
int controlDigit(const char *personr, struct Ssn *person);
int digit_multiply(int number);
void convert(char *string, struct Ssn *person);


int main(int argc, char *argv[])
{

	//Assign memory for the struct
	char input[SSN_LEN];

	while(1){
		
		struct Ssn *person = malloc(sizeof(struct Ssn));
		readPerson(input);
		if(input[0] == 'q') break;
		convert(input, person);
		controlDigit(input, person) ? printf("Valid SSN\n") : printf("Invalid SSN\n");
		free(person);

	}

}

int digit_multiply(int number)
{
	return (number * 2 / 10) + (number * 2 % 10);
}

int controlDigit(const char *personr, struct Ssn *person)
{
	int year, month, day, digits, checksum;
	//Check in correct range:
	if((person->month >= 1 && person->month <= 12) && 
		(person->day >= 1 && person->day <= 31)) {

		year =   digit_multiply(person->year  /10) + (person->year % 10);
		month =  digit_multiply(person->month / 10) + (person->month % 10);
		day =    digit_multiply(person->day / 10) + (person->day % 10);
		digits = digit_multiply(person->digits / 100) + (person->digits / 10 % 10) 
			   + digit_multiply(person->digits % 10);

		checksum = (year+month+day+digits) % 10;

		return ((10 - checksum)%10) == person->check ? 1 : 0;
	}

	//Not in correct range, not a valid id.
	else{

		return 0;
	}

}

void readPerson(char *person)
{
	printf("Please input a valid SWE-SSN\nIt should take the format:\nYYMMDD-XXXX\n");
	scanf("%s", person);
}

void convert(char *string, struct Ssn *person)
{
	person->year   =  (string[0] - '0') * 10  + string[1] - '0';
	person->month  =  (string[2] - '0') * 10  + string[3] - '0';
	person->day    =  (string[4] - '0') * 10  + string[5] - '0';
	person->digits =  (string[7] - '0') * 100 + ((string[8] - '0') * 10) + string[9] - '0';
	person->check  =  (string[10] - '0');
}