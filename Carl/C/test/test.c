#include <stdio.h>
#include "logger.h"

int main() {
  
	int x = 199,i=0;
	char *s = "Bitter Truth";

	while(i<5) {
		LOG_PRINT("Hello World ");
		LOG_PRINT("Zing is back !!! %s %d",s,x++);
		i++;
	}
}