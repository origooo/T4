/*====================================
File name: exerc_3_4.c (or cpp) Date: 2014‐01‐31
Group Number: 3
Members that contributed:
	Patrik Bäckström,
	John Burchell,
	William Granli
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define FILE_NAME "PersonRegister.txt"

typedef struct {
	char firstName[MAX];
	char lastName[MAX];
	char persNumber[13];
} PERSON;

PERSON input_record(void);
void write_new_file(PERSON *inrecord);
void printfile(void);
void search_by_firstname(char *name);
void append_file(PERSON *inrecord);
void enterToContinue(int);

int main(int argc, char *argv[]) {

	int loop = 1, option = 0;
	
	PERSON *person = malloc(sizeof(PERSON));
	strcpy(person->firstName, "John");
	strcpy(person->lastName, "Burchell");
	strcpy(person->persNumber, "19880923-1234");

	while (loop) {
		printf("\n\t#----------------------------------------");
		printf("\n\t# 1 Create a new file and delete the old");
		printf("\n\t# 2 Add a new person to the file");
		printf("\n\t# 3 Search for a person");
		printf("\n\t# 4 Print all persons");
		printf("\n\t# 5 Exit");
		printf("\n\t#----------------------------------------");
		printf("\n\tSELECT >>> ");
		scanf("%i",&option);

		printf("\n");
		switch (option) {
			case 1: 
				write_new_file(person);
				break;
			case 2:
				*person = input_record();
				append_file(person);
				break;
			case 3: break;
			case 4: printfile(); break;
			case 5: loop = 0; break;
			default: printf("\n\t# Invalid input! %i\n\n", option);
		}
	}

	free(person);
	printf("\t>>> Nuke nuke...\n\n");

	return 0;
}

void write_new_file(PERSON *inrecord) {
	
	FILE *file;
	
	file = fopen(FILE_NAME, "wb+");
	fwrite(inrecord, sizeof(PERSON),1,file);
	fclose(file);
}

void append_file(PERSON *inrecord) {
	
	FILE *file;
	
	file = fopen(FILE_NAME, "ab+");
	fwrite(inrecord, sizeof(PERSON),1,file);
	fclose(file);
}

PERSON input_record(void) {
	
	PERSON *inrecord = malloc(sizeof(PERSON));
	char fname[MAX], lname[MAX],pn[13], temp;
	
	printf("\tFirst name: ");
	scanf("%s", fname);
	strncpy(inrecord->firstName, fname, sizeof(inrecord->firstName));

	printf("\tLast name: ");
	scanf("%s", lname);
	strncpy(inrecord->lastName, lname, sizeof(inrecord->lastName));
	
	printf("\tPersonal number: ");
	scanf("%s", pn);
	strncpy(inrecord->persNumber, pn, sizeof(inrecord->persNumber));

	return *inrecord;
}

void printfile(void) {

	PERSON *temp = malloc(sizeof(PERSON));
	int listEntry = 0;

	FILE *file;
	file = fopen(FILE_NAME,"rb");

	while (getchar() != '\n');
	while (fread(temp, sizeof(PERSON), 1, file)) {
		printf("\t### Entry no: %i\n", listEntry + 1);
		printf("\t* First name: %s\n", temp->firstName);
		printf("\t* Last name: %s\n", temp->lastName);
		printf("\t* Personal number: %s\n\n", temp->persNumber);
		listEntry++;
		0 == listEntry % 5 ? enterToContinue(listEntry) : 0;
	}

	free(temp);
}

void enterToContinue(int listEntry) {
	printf("\n\t\t  >>> Showing no %i to %i <<<\n\t\t>>> Press ENTER to continue <<<\n", listEntry - 4, listEntry);
	int enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
}