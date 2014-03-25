/* ==================================== 
File name: exerc_3_5.c (or cpp) 
Date: 2013‐01-23
Group Number: 03
Members that contributed: 
John Burchell
Patrik Backstrom
William Granli
Demonstration code: 48047 
====================================== */ 
#include <stdio.h>


int search_number(int number, int array[], int size);
void sort(int number, int tab[]);
void swap(int digit1, int digit2);
void print_array(int array[]);

int size;

int main(int argc, char *argv[])
{
	int test[] = {1,2,34,5,67,3,23,12,13,10};
	size = sizeof(test); 
	int search = 0;
	printf("Enter a number to search for:\n");
	scanf("%i", &search);
	int result = search_number(search, test, sizeof(test));
	result == -1 ? printf("Number not found.\n") :
			       printf("%d Found at index %d\n",search, result);


    int test2[] = {5,6,7,9,1,3,8,4,2,1};
    printf("\nArray before sort:\n");
	print_array(test2);
    sort(0,test2);
    printf("Array after sort:\n");
	print_array(test2);

    printf("\nTesting first array:\n");
    printf("Array before sort:\n");
    print_array(test);
    sort(0,test);
    printf("Array after sort:\n");
    print_array(test);

    return 0;
}

int search_number(int number, int array[], int size)
{
	int loc = 0;
	while(array[loc] != number && loc < size){
		loc++;
	}
	return loc < size ? loc : -1;
}

void sort(int number, int tab[])
{	

	int min = tab[number];
	int temp, i;

	if(number == sizeof(&tab) + 1){
		return;
	}
	for(i = number; i < sizeof(&tab) + 1; i++){
		if(min > tab[i]){
			min = tab[i];
		}
		if(tab[number] > min){
			temp = tab[number];
			tab[number] = min;
			tab[i] = temp;
		}
	}
	sort(number+1, tab);
}

void print_array(int array[])
{
	int i = 0;
	for(i = 0; i < 9; i++){
		printf("%d,", array[i]);
	}
	printf("\n");
}