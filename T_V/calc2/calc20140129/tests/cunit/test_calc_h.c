#include "../../src/calc.h"

CalcStatePtr calc = NULL;

void testClear();

/* Set up and clean up test suite */

int init_suite(void) {
  calc = mkCalcState();
  return calc == NULL;
}

int clean_suite(void) {
  freeCalcState(calc);
  calc=NULL;
  return 0;
}

void testCase1(void) {
  // Enter 17+3=, monitor buffer between button presses

  // Initial buffer is empty
  CU_ASSERT(!strcmp(getBuffer(calc), ""));

  // Press '1'  (expected buffer: "1")
  pressDigit(calc, '1');
  CU_ASSERT(!strcmp(getBuffer(calc), "1"));

  // Press '7'  (expected buffer: "17")
  pressDigit(calc, '7');
  CU_ASSERT(!strcmp(getBuffer(calc), "17"));
  
  // Press '+'  (expected buffer: "17")
  pressPlus(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "17"));

  // Press '3'  (expected buffer: "3")
  pressDigit(calc, '3');
  CU_ASSERT(!strcmp(getBuffer(calc), "3"));

  // Press '='  (expected buffer: "20")
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "20"));
}

void testCase2(void) {
  CU_ASSERT(!strcmp(getBuffer(calc), "20"));

  pressReset(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), ""));

  pressDigit(calc, '3');
  pressMult(calc);
  pressDigit(calc, '7');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "21"));
}

void testLimits(void){
  //Test if it can handle 15 digits
  //Reset buffer first.
  testClear();
  //Add 15 9s
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  CU_ASSERT(!strcmp(getBuffer(calc), "9999999999999999"));

  //Attempt 16'th digit
  pressDigit(calc, '1');
  CU_ASSERT(!strcmp(getBuffer(calc), "9999999999999999"));

}

void testClear(void){
  pressReset(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), ""));
}

void testEquation(void){
  //Test that it computes when another operand is pressed
  //After a one is pressed before hand.
  testClear();
  pressDigit(calc, '2');
  pressMult(calc);
  pressDigit(calc, '2');
  CU_ASSERT(!strcmp(getBuffer(calc), "2"));
  pressMult(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "4"));
  pressDigit(calc, '2');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "8"));

  testClear();
  pressDigit(calc, '3');
  pressMult(calc);
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "9"));


}

void testNegatives()
{
  testClear();
  pressDigit(calc, '0');
  pressMinus(calc);
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressDigit(calc, '9');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "-9999999999"));
  //Assume that it should be negative.
  CU_ASSERT(calc->bufferNegative == 1);

  testClear();
  pressDigit(calc, '2');
  pressMinus(calc);
  pressDigit(calc, '4');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "-2"));
  //Assume that it should be negative.
  CU_ASSERT(calc->bufferNegative == 1);
}




