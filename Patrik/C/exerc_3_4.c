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
void search();
void search_by_firstname(char *name);
void search_by_lastname(char *name);
void append_file(PERSON *);
void enterToContinue(int);
void cls(void);

int main(int argc, char *argv[]) {

	int loop = 1, option = 0;
	
	PERSON *person = malloc(sizeof(PERSON));
	strncpy(person->firstName, "Test", sizeof(person->firstName));
	strncpy(person->lastName, "Testson", sizeof(person->lastName));
	strncpy(person->persNumber, "11112233-4445", sizeof(person->persNumber));

	while (loop) {
		printf("\n\t\033[0;31;1m#----------------------------------------\033[00m");
		printf("\n\t\033[0;31;1m# 1\033[00m Create a new file and delete the old");
		printf("\n\t\033[0;31;1m# 2\033[00m Add a new person to the file");
		printf("\n\t\033[0;31;1m# 3\033[00m Search for a person");
		printf("\n\t\033[0;31;1m# 4\033[00m Print all persons");
		printf("\n\t\033[0;31;1m# 5\033[00m Exit");
		printf("\n\t\033[0;31;1m#----------------------------------------\033[00m");
		printf("\n\t\033[0;31;1mSELECT >>>\033[00m ");
		scanf("%i",&option);

		cls();
		switch (option) {
			case 1:
				write_new_file(person);
				break;
			case 2:
				input_record(person);
				append_file(person);
				break;
			case 3:
				search();
				break;
			case 4:
				printfile();
				break;
			case 5:
				loop = 0;
				break;
			default: printf("\n\t\033[0;31;5m# Invalid input: %i...\033[00m\n", option);
		}
	}

	free(person);
	printf("\n\t>>> Nuke nuke...\n\n");

	return 0;
}

void write_new_file(PERSON *inrecord) {
	
	FILE *file;
	
	file = fopen(FILE_NAME, "wb+");
	fwrite(inrecord, sizeof(PERSON),1,file);
	fclose(file);
	printf("\n\t\033[0;31;5m# Created new file!\033[00m\n");
}

void append_file(PERSON *inrecord) {
	
	FILE *file;
	
	file = fopen(FILE_NAME, "ab+");
	fwrite(inrecord, sizeof(PERSON),1,file);
	fclose(file);
	printf("\n\t\033[0;31;5m# Wrote new entry to file...\033[00m\n");
}

void input_record(PERSON *inrecord) {
	
	char fname[MAX], lname[MAX],pn[13];

	while (getchar() != '\n');
	printf("\t\033[0;31;1mFirst name:\033[00m ");
	fgets(fname, MAX, stdin);
	strncpy(inrecord->firstName, fname, sizeof(inrecord->firstName));

	printf("\t\033[0;31;1mLast name:\033[00m ");
	fgets(lname, MAX, stdin);
	strncpy(inrecord->lastName, lname, sizeof(inrecord->lastName));
	
	printf("\t\033[0;31;1mPersonal number:\033[00m ");
	fgets(pn, 13, stdin);
	strncpy(inrecord->persNumber, pn, sizeof(inrecord->persNumber));
}

void search() {
	int option = 0, loop = 1;
	char searchFor[20];
	while (loop) {
		printf("\n\t\033[0;31;1m#----------------------------------------\033[00m");
		printf("\n\t\033[0;31;1m#\033[00m 1 Search by first name");
		printf("\n\t\033[0;31;1m#\033[00m 2 Search by last name");
		printf("\n\t\033[0;31;1m#\033[00m 3 Return");
		printf("\n\t\033[0;31;1m#----------------------------------------\033[00m");
		printf("\n\t\033[0;31;1mSELECT >>>\033[00m ");
		scanf("%i",&option);
		while (getchar() != '\n');

		cls();
		switch (option) {
			case 1:
				printf("\n\t\033[0;31;1mType name to search for: \033[00m");
				fgets(searchFor,MAX,stdin);
				search_by_firstname(searchFor);
				break;
			case 2:
				printf("\n\t\033[0;31;1mType name to search for: \033[00m");
				fgets(searchFor,MAX,stdin);
				search_by_lastname(searchFor);
				break;
			case 3:
				loop = 1;
				return;
			default: printf("\n\t\033[0;31;5m# Invalid input: %i...\033[00m\n", option);
		}
	}
}

void search_by_firstname(char *name) {
	
	FILE *file;
	
	PERSON *temp = malloc(sizeof(PERSON));
	int listEntry = 0;
	char nameString[MAX+1];
	strncpy(nameString, name, MAX+1);

	file = fopen(FILE_NAME,"rb");

	printf("\n");
	while (fread(temp, sizeof(PERSON), 1, file)) {
		if (!strcmp(nameString,temp->firstName)) {
			printf("\t\033[0;31;1m### Entry no: %i\033[00m\n", listEntry + 1);
			printf("\t\033[0;31m* First name:\033[00m %s", temp->firstName);
			printf("\t\033[0;31m* Last name:\033[00m %s", temp->lastName);
			printf("\t\033[0;31m* Personal number:\033[00m %s\n", temp->persNumber);
			listEntry++;
			0 == listEntry % 5 ? enterToContinue(listEntry) : 0;
		}
	}
    fclose(file);
	free(temp);
}

void search_by_lastname(char *name) {
	
	FILE *file;
	
	PERSON *temp = malloc(sizeof(PERSON));
	int listEntry = 0;
	char nameString[MAX+1];
	strncpy(nameString, name, MAX+1);

	file = fopen(FILE_NAME,"rb");
	
	printf("\n");
	while (fread(temp, sizeof(PERSON), 1, file)) {
		if (!strcmp(nameString,temp->lastName)) {
			printf("\t\033[0;31;1m### Entry no: %i\033[00m\n", listEntry + 1);
			printf("\t\033[0;31m* First name:\033[00m %s", temp->firstName);
			printf("\t\033[0;31m* Last name:\033[00m %s", temp->lastName);
			printf("\t\033[0;31m* Personal number:\033[00m %s\n", temp->persNumber);
			listEntry++;
			0 == listEntry % 5 ? enterToContinue(listEntry) : 0;
		}
	}
    fclose(file);
	free(temp);
}

void printfile(void) {

	PERSON *temp = malloc(sizeof(PERSON));
	int listEntry = 0;

	FILE *file;
	file = fopen(FILE_NAME,"rb");

	while (getchar() != '\n');
	fread(temp, sizeof(PERSON), 1, file); // Reads first entry. Makes no use of the data, to prevent displaying dummy data.
	while (fread(temp, sizeof(PERSON), 1, file)) {
		printf("\t\033[0;31;1m### Entry no: %i\033[00m\n", listEntry + 1);
		printf("\t\033[0;31m* First name:\033[00m %s", temp->firstName);
		printf("\t\033[0;31m* Last name:\033[00m %s", temp->lastName);
		printf("\t\033[0;31m* Personal number:\033[00m %s\n", temp->persNumber);
		listEntry++;
		0 == listEntry % 5 ? enterToContinue(listEntry) : 0;
	}
    fclose(file);
	free(temp);
}

void enterToContinue(int listEntry) {
	int enter = 0;
	printf("\n\t\t  >>> Showing no %i to %i <<<\n\t\t>>> Press ENTER to continue <<<\n", listEntry - 4, listEntry);
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
}

void cls(void) {
	printf("\033[2J");
	printf("\033[0;0f");
}