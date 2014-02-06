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

void testUnsignedIntLimits(void){
  //Reset buffer first.
  testClear();
  //Testing unisnged int
  pressDigit(calc, '4');
  pressDigit(calc, '2');
  pressDigit(calc, '9');
  pressDigit(calc, '4');
  pressDigit(calc, '9');
  pressDigit(calc, '6');
  pressDigit(calc, '7');
  pressDigit(calc, '2');
  pressDigit(calc, '9');
  pressDigit(calc, '4');
  CU_ASSERT(!strcmp(getBuffer(calc), "4294967294"));

  pressPlus(calc);
  pressDigit(calc, '1');
  pressExec(calc);
  //Should fail because the int has overflowed, this should just 
  //add 1 as expected
  CU_ASSERT(!strcmp(getBuffer(calc), "4294967295"));
}

void testSignedIntLimits(void){

  testClear();
  //testing singed int
  pressDigit(calc, '2');
  pressDigit(calc, '1');
  pressDigit(calc, '4');
  pressDigit(calc, '7');
  pressDigit(calc, '4');
  pressDigit(calc, '8');
  pressDigit(calc, '3');
  pressDigit(calc, '6');
  pressDigit(calc, '4');
  pressDigit(calc, '7');
  CU_ASSERT(!strcmp(getBuffer(calc), "2147483647"));

  pressPlus(calc);
  pressDigit(calc, '1');
  pressExec(calc);
  //Again, like the Unsigned version, the calculator should be able to handle
  //larger numbers than this. 
  CU_ASSERT(!strcmp(getBuffer(calc), "2147483648"));
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
  pressMult(calc);
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
  pressDigit(calc, '2');
  pressMinus(calc);
  pressDigit(calc, '4');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "-2"));
  //Assume that it should be negative.
  CU_ASSERT(calc->bufferNegative == 1);

  testClear();

  pressDigit(calc, '0');
  pressMinus(calc);
  pressDigit(calc, '2');
  pressPlus(calc);
  pressDigit(calc, '2');
  pressExec(calc);

  CU_ASSERT(!strcmp(getBuffer(calc), "0"));
  CU_ASSERT(calc->bufferNegative == 0);



}

void testPlus() {
 //plus
  testClear();
  pressDigit(calc, '2');
  CU_ASSERT(!strcmp(getBuffer(calc), "2"));
  pressPlus(calc);
  pressDigit(calc, '4');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "6"));
}

void testMin() {
 //min
  testClear();
  pressDigit(calc, '1');
  CU_ASSERT(!strcmp(getBuffer(calc), "1"));
  pressMinus(calc);
  pressDigit(calc, '1');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "0"));
}

void testMul() {
 //mul
  testClear();
  pressDigit(calc, '4');
  CU_ASSERT(!strcmp(getBuffer(calc), "4"));
  pressMult(calc);
  pressDigit(calc, '4');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "16"));
}

void testDiv() {
  //div
  testClear();
  pressDigit(calc, '1');
  pressDigit(calc, '6');
  CU_ASSERT(!strcmp(getBuffer(calc), "16"));
  pressDiv(calc);
  pressDigit(calc, '4');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "4"));

  testClear();
  pressDigit(calc, '1');
  pressDiv(calc);
  pressDigit(calc, '0');
  pressExec(calc);
  CU_ASSERT(!strcmp(getBuffer(calc), "[error]"));
  CU_ASSERT(calc->err == 1);
}

void testMaxBuffer() {
  testClear();
  pressDigit(calc, '1');
  pressDigit(calc, '2');
  pressDigit(calc, '3');
  pressDigit(calc, '4');
  pressDigit(calc, '5');
  pressDigit(calc, '6');
  pressDigit(calc, '7');
  pressDigit(calc, '8');
  pressDigit(calc, '9');
  pressDigit(calc, '1');
  pressDigit(calc, '2');
  pressDigit(calc, '3');
  pressDigit(calc, '4');
  pressDigit(calc, '5');
  pressDigit(calc, '6');
  CU_ASSERT(!strcmp(getBuffer(calc), "123456789123456"));

  pressDigit(calc, '1');
  CU_ASSERT(!strcmp(getBuffer(calc), "[error]"));
  CU_ASSERT(calc->err == 1);
}

void testOperands(){

  pressDigit(calc, '2');
  pressPlus(calc);
  pressDigit(calc, '2');
  pressExec(calc);
  pressDigit(calc, '3');
  CU_ASSERT(!strcmp(getBuffer(calc), "3"));

}