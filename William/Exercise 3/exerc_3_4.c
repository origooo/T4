#include <stdlib.h>
#include <stdio.h>

#define MAXN 20
#define MAXP 13

FILE *file;
char filename[12] = "datorbas.bin";

typedef struct {
	char firstname[MAXN];
	char famname[MAXN];
	char pnumber[MAXP]; // yyyymmddnnnc
}PERSON;

// Function declaration (to be extend )
PERSON input_record(void);				// Reads in a person record.
void write_new_file( PERSON *inrecord); //Creats a file and write a first record
void printfile(void); 					// print out all persons in the file
void search_by_firstname(char *name);	// print out person if in list
void append_file(PERSON *inrecord);		// appends a new person to the file

int main(int *argc, int argv[]) {
	PERSON *willy = malloc(sizeof(PERSON));
	

	char first[MAXN] = "Willy";
	char fam[MAXN] = "Doe";
	char pnr[MAXP] = "19900606000";
	
	willy->firstname[MAXN] = first[MAXN];
	willy->famname[MAXN] = fam[MAXN];
	willy->pnumber[MAXP] = pnr[MAXN];
	
	write_new_file(willy);
 	free(willy);
	input_record();
	printfile();


	
	return(0);
}

void write_new_file(PERSON *inrecord) {

	file = fopen(filename, "wb+");
	if (file != NULL) {
		fwrite(inrecord, sizeof(PERSON), 1, file);
	}
	fclose(file);

}

PERSON input_record(void) {
	
	char first[MAXN], fam[MAXN], pnr[MAXP];
	PERSON *person = malloc(sizeof(PERSON)); //remember to free this somewhere
	
	//first person
 	person->firstname[MAXN] = first[MAXN];
	person->famname[MAXN] = fam[MAXN];
	person->pnumber[MAXP] = pnr[MAXN];
	
	
	
	//input
	printf("Input first name\n");
	scanf("%s", first);
	printf("Input family name\n");
	scanf("%s", fam);
	printf("Input personal num\n");
	scanf("%s", pnr);
	
	append_file(person);

	free(person);
}



void append_file(PERSON *inrecord) {

 	file = fopen(filename, "ab+");
	fwrite(inrecord, sizeof(PERSON), 1, file);
	fclose(file);

}

void printfile(void) {
	PERSON* person = malloc(sizeof(PERSON));

	file = fopen(filename, "rb");
	
	while(fread(person, sizeof(PERSON), 1, file)) {
		printf("%s ", person->firstname);
		printf("%s ", person->famname);
		printf("%s\n", person->pnumber);
  	}
  	
  	free(person);
}

void search_by_firstname(char *name) {
	
}


