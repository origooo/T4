#include <stdio.h>

main()
{
	char input[100];
	int i;
	while (1)
	{

		printf("Enter a word!!!\n");
		fgets(input, 100, stdin);

		for (i=0; i<=sizeof(input); i++) {
			if (input[i] >= 'a' && input[i] <= 'm') {
				input[i] +=13;
			}
			else if (input[i] > 'm' && input[i] <= 'z') {
				input[i] -= 13;
			}
			else if (input[i] >= 'A' && input[i] <= 'M') {
				input[i] +=13;
			}
			else if (input[i] > 'M' && input[i] <= 'Z') {
				input[i] -= 13;
			}
		}
	
	printf("%s \n", input);
	}
}
