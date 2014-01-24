#include <stdio.h>
#include <ctype.h>

// William, you are counting white space, not words. Try entering this: "ab        def    ".

main()
{
	char input[100];
	int i;
	int number_of_words = -1;
	
	fgets(input, 100, stdin);
	
	for (i = 0; i<=100; i++) {
		if (isspace(input[i])) {
			number_of_words++;
		}
	}
	
	printf("number === %d", number_of_words);
}
