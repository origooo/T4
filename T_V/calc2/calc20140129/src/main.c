#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

int main(int argc, char**argv) {
  int argNo, charNo;
  CalcStatePtr calc = mkCalcState();

  printf("Buffer: %s\n", getBuffer(calc));
  for(argNo=1; argNo<argc; argNo++) {
    for(charNo=0; argv[argNo][charNo]; charNo++) {
      char c = argv[argNo][charNo];
      printf("Pressing %c   ", c);
 
      if(c >= '0' && c <= '9')
	pressDigit(calc, c);
      else {
	switch(c) {
	case '+': pressPlus(calc); break;
	case '-': pressMinus(calc); break;
	case '*': pressMult(calc); break;
	case '/': pressDiv(calc); break;
	case '=': pressExec(calc); break;
	case 'C':
	case 'c': pressReset(calc); break;
	default:
	  printf("Warning: unknown key, \'%c\'\n", c);
	  break;
	}
      }
      printf("Buffer: %s\n", getBuffer(calc));
    }
  }

  freeCalcState(calc);
  return 0;
}
