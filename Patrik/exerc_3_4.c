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
	char firstName[MAX+1];
	char lastName[MAX+1];
	char persNumber[13+1];
} PERSON;

void input_record(PERSON *);
void write_new_file(PERSON *);
void printfile(void);
void search_by_firstname(char *);
void append_file(PERSON *);
void enterToContinue(int);

int main(int argc, char *argv[]) {

	int loop = 1, option = 0;
	
	PERSON *person = malloc(sizeof(PERSON));
	strcpy(person->firstName, "TestTestTestTestTest");
	strcpy(person->lastName, "Testson");
	strcpy(person->persNumber, "11112233-4445");

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
				input_record(person);
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

void input_record(PERSON *inrecord) {
	
	char fname[MAX], lname[MAX],pn[13], temp;

	while (getchar() != '\n');
	printf("\tFirst name: ");
    fgets(fname, MAX, stdin);
	strncpy(inrecord->firstName, fname, sizeof(inrecord->firstName));

	printf("\tLast name: ");
    fgets(lname, MAX, stdin);
	strncpy(inrecord->lastName, lname, sizeof(inrecord->lastName));
	
	printf("\tPersonal number: ");
    fgets(pn, 13, stdin);
	strncpy(inrecord->persNumber, pn, sizeof(inrecord->persNumber));
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
    fclose(file);
	free(temp);
}

void enterToContinue(int listEntry) {
	printf("\n\t\t  >>> Showing no %i to %i <<<\n\t\t>>> Press ENTER to continue <<<\n", listEntry - 4, listEntry);
	int enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
}
