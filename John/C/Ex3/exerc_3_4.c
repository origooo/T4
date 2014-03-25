/*====================================
File name: exerc_3_4.c (or cpp) Date: 2014‐01‐30
Group Number: 3
Members that contributed:
        John Burchell,
        Patrik Bäckström,
        William Granli
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/


#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include "exerc_3_5.h"

PERSON input_record(void);// Reads in a person record. 
void write_new_file(PERSON *inrecord); //Creats a file and write a first record 
void printfile(void); // print out all persons in the file 
void search();
void search_by_firstname(char *name);// print out person if in list 
void search_by_lastname(char *name);// print out person if in list  
void append_file(PERSON *inrecord);// appends a new person to the file 
void delete_file(); // Delete the file.
 
int main(int argc, char *argv[]){ 
    PERSON *ppost = malloc(sizeof(PERSON));
    int i = 0, loop = 1, choice = 0;

    char *choices[] = {"Create new File", "Add new Person",
    	"Search for a person", "Print all in a list", "Exit", "Print all alphabetically"};

    printf("\t---- 3.4 DB ----\n\n"); 
    printf("Welcome to the main program."
    	"\nPlease make a choice from the menu below:\n");
    for(i = 0; i < 6; i++){
    	printf("%d - %s\n", i+1, choices[i]);
	}


	while(loop) {

		printf("> ");
		scanf("%d", &choice);

		switch(choice) {
		case 1: write_new_file(ppost); ppost = malloc(sizeof(PERSON)); break;
		case 2: *ppost = input_record(); append_file(ppost); ppost = malloc(sizeof(PERSON)); break;
		case 3: search(); break;
		case 4: printfile(); break;
		case 5: printf("Exit\n"); loop = 0; break;
		case 6: printfileAlabetic(); break;
		default: printf("Taking your input as an exit attempt, quitting...\n");
		}
	}

	free(ppost);
    return 0; 
} 

void write_new_file(PERSON *inrecord)
{
	FILE *file;

	//Copy to the record with the size of the arrays.
	strncpy(inrecord->firstName, "John", sizeof(inrecord->firstName));
	strncpy(inrecord->familyName, "Burchell", sizeof(inrecord->familyName));
	strncpy(inrecord->pers_number, "198809231234", sizeof(inrecord->pers_number));

	//If file exists, delete it
	if((file = fopen(FILENAME, "r")) != NULL){
		delete_file();
		fclose(file);
	}

	//Create file and close it.
	file = fopen(FILENAME, "w");
	fclose(file);
	append_file(inrecord);
}

void printfile()
{	
	PERSON *temp = malloc(sizeof(PERSON));
	FILE *file = fopen(FILENAME, "r");

	if(file == NULL){
		printf("error opening file.\n");
		exit(1);
	}

	while(fread(temp, sizeof(PERSON), 1, file)){
		printf("Name: %s\n", temp->firstName);
		printf("Family Name: %s\n", temp->familyName);
		printf("Personal Number: %s\n", temp->pers_number);
	}

	free(temp);
	fclose(file);
}



void search()
{	
	int choice = 0;
	char name[5];

	printf("Press 1 for first name, 2 for last name: ");
	scanf("%d", &choice);

	printf("Please enter the name you wish to search for: ");
	scanf("%s", name);

	switch(choice){

		case 1: search_by_firstname(name); break;
		case 2: search_by_lastname(name); break;
		default : printf("You picked something other than the options provided, stopping search\n");
	}


}

void search_by_firstname(char *name)
{
	int count = 0;
	PERSON *temp = malloc(sizeof(PERSON));
	PERSON matches[100];
	PERSON *ptr = matches;
	FILE *file = fopen(FILENAME, "r");


	int rc = fread(temp, sizeof(PERSON), 1, file);

	while(rc != 0){

		if(strcmp(temp->firstName, name) == 0){
			*ptr = *temp;
			ptr++;
			count++;
		}

		rc = fread(temp, sizeof(PERSON), 1, file);
	}


	int i = 0;
	if(count == 0) {
		printf("Sorry, no-one exists by that name\n");
	}
	for(i = 0; i < count; i++){
		printf("Name: %s\n", matches[i].firstName);
		printf("Family Name: %s\n", matches[i].familyName);
		printf("Personal Number: %s\n", matches[i].pers_number);
	}

	free(temp);
	fclose(file);

}


void search_by_lastname(char *name){

	int count = 0;
	PERSON *temp = malloc(sizeof(PERSON));
	PERSON matches[100];
	PERSON *ptr = matches;
	FILE *file = fopen(FILENAME, "r");


	int rc = fread(temp, sizeof(PERSON), 1, file);

	while(rc != 0){

		if(strcmp(temp->familyName, name) == 0){
			*ptr = *temp;
			ptr++;
			count++;
		}

		rc = fread(temp, sizeof(PERSON), 1, file);
	}

	fclose(file);

	if(count == 0) {
		printf("Sorry, no-one exists by that name\n");
	}

	int i = 0;
	for(i = 0; i < count; i++){
		printf("Name: %s\n", matches[i].firstName);
		printf("Family Name: %s\n", matches[i].familyName);
		printf("Personal Number: %s\n", matches[i].pers_number);
	}

	free(temp);
}

PERSON input_record(){

	PERSON *input = malloc(sizeof(PERSON));
	char firstName[sizeof(input->firstName)], familyName[sizeof(input->familyName)], 
		pers_num[sizeof(input->pers_number)];

	printf("Please provide the following information:\n1 - Firstname: ");
	scanf("%s", firstName);
	printf("2 - Family Name: ");
	scanf("%s", familyName);
	printf("3 - Personal Number: ");
	scanf("%s", pers_num);

	strncpy(input->firstName, firstName, sizeof(input->firstName));
	strncpy(input->familyName, familyName, sizeof(input->familyName));
	strncpy(input->pers_number, pers_num, sizeof(input->pers_number));

	return *input;
}

void append_file(PERSON *inrecord)
{
	FILE *file = fopen(FILENAME, "a");
	if(file == NULL){
		printf("Error opening file\n");
		exit(1);
	}

	fwrite(inrecord, sizeof(PERSON), 1, file);
	fclose(file);
	free(inrecord);
}


void delete_file()
{	
	//Try to remove, report error if it cannot.
	remove(FILENAME) == 0 ? printf("Deleted old DB\n") : 
							fprintf(stderr, "Error deleting %s\n", FILENAME);
}
