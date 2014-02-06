#include <stdio.h>
#include <string.h>

#define STRING_MAX_LENGTH 100

//method declarations
void *without (char input_string[STRING_MAX_LENGTH]);
void *with (char input_string[STRING_MAX_LENGTH]);
void *read_file();

//global variables
char internal_buffer[STRING_MAX_LENGTH];

//main function
void main (void) {
	char input_string[STRING_MAX_LENGTH];

	printf("Enter a string.\n");
	
	fgets(input_string, STRING_MAX_LENGTH, stdin);
	
	without(input_string);
	with(input_string);
	read_file();
 }

//without strcpy()
void *without (char input_string[STRING_MAX_LENGTH]) {
	
 	int i;
	for (i = 0; i <= sizeof(input_string); i++) {
		internal_buffer[i] = input_string[i];
	}
	
	printf("String without strcpy() == %s\n", internal_buffer);
}

//with strcpy()
void *with (char input_string[STRING_MAX_LENGTH]) {
	strcpy(input_string, internal_buffer);
	
	printf("String with strcpy() == %s\n", internal_buffer);
}

//reading from the file
void *read_file() {

	FILE *file;
	file = fopen("string.txt", "r");

	fgets(internal_buffer, STRING_MAX_LENGTH, file);

	printf("String from file == %s\n", internal_buffer);
	
	fclose(file);
}
