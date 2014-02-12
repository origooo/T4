/*====================================
File name: exerc_3_5.c (or cpp) Date: 2014‐01‐30
Group Number: 3
Members that contributed:
        John Burchell,
        Patrik Bäckström,
        William Granli
Demonstration code: [<Ass code 1‐4> <abc>]
======================================*/


#include "exerc_3_5.h"

void printfileAlabetic(){

	PERSON *temp = malloc(sizeof(PERSON));
	FILE *file = fopen(FILENAME, "r");
	PERSON people[100];
	PERSON *ptr = people;
	int count = 0, i = 0;

	while(fread(temp, sizeof(PERSON), 1, file)){
		printf("Name: %s\n", temp->firstName);
		printf("Family Name: %s\n", temp->familyName);
		printf("Personal Number: %s\n", temp->pers_number);
		*ptr = *temp;
		ptr++;
		count++;
	}


	if(count > 0){

		printf("Before sort\n");
		for(i = 0; i < count; i++){
			printStruct(people[i]);
		}

		printf("This is the count %d\n", count);
		sort_alpha(people, 0, count-1);

		printf("After sort\n");
		for(i = 0; i < count; i++){
			printStruct(people[i]);
		}
	}
	// 	for(i = 0; i < count; i++){
	// 		printf("Name: %s\n", people[i].firstName);
	// 		printf("Family Name: %s\n", people[i].familyName);
	// 		printf("Personal Number: %s\n", people[i].pers_number);
	// 	}
	// } else {
	// 	printf("No entries exist.\n");
	// }

	free(temp);
	fclose(file);
}
void printStruct(PERSON toPrint){

	printf("Name: %s\n", toPrint.firstName);
	// printf("Family Name: %s\n", toPrint.familyName);
	// printf("Personal Number: %s\n", toPrint.pers_number);
}

void sort_alpha(PERSON *list, int first, int last){

	PERSON *temp = malloc(sizeof(PERSON));
	int i, j, pivNum;

	printf("%c vs %c\n", list[first].firstName[0], list[last].firstName[0]);
	if(toupper(list[first].firstName[0]) < toupper(list[last].firstName[0])){

		printf("less than\n");

		pivNum = first;
        i = first;
        j = last;

        while(i < j){
        	while(toupper(list[i].firstName[0]) <= toupper(list[pivNum].firstName[0]) && i < last){
        		i++;
        	}
        	while(toupper(list[j].firstName[0]) > toupper(list[pivNum].firstName[0])){
        		j--;
        	}
        	if(toupper(list[i].firstName[0]) < toupper(list[j].firstName[0])){
        		printf("inner less than\n");
        		*temp = list[i];
        		list[i] = list[j];
        		list[j] = *temp;
        	}

        }

        *temp = list[pivNum];
        list[pivNum] = list[j];
        list[j] = *temp;
        sort_alpha(list,first,j-1);
        sort_alpha(list,i+1,last);

	}

	free(temp);
}


// PERSON *sort_alpha(PERSON *list, int count, int number){

// 	char min_char;
// 	int i;
// 	PERSON *temp = malloc(sizeof(PERSON));

// 	min_char = list[0].firstName[0];

// 	if(count < 1){
// 		return list;
// 	}

// 	printf("Char is %c\n", min_char);

// 	for(i = 0; i < count; i++) {
// 		if(list[i].firstName[0] < min_char){
// 			printf("Lower\n");
// 		}
// 	}

// 	free(temp);
// }