#include "../../src/calc.h"
#include "unity/src/unity.h"

CalcStatePtr calc = NULL;

/*
TEST_GROUP_RUNNER(buffer_test)
{
  RUN_TEST_CASE(buffer_test,digits);
}
*/

void setUp(void)
{
  calc = mkCalcState();
}

void tearDown(void)
{
  calc = NULL;
}

void test_DigitsChangeBuffer(void)
{
  // TEST_ASSERT (expected, actual)
  TEST_ASSERT_EQUAL_STRING("", getBuffer(calc));
  pressDigit(calc, '1');
  TEST_ASSERT_EQUAL_STRING("1", getBuffer(calc));
}

void test_Sum(void)
{
  TEST_ASSERT_EQUAL_STRING("", getBuffer(calc));
  pressDigit(calc, '9');
  pressPlus(calc);
  pressDigit(calc, '7');
  pressExec(calc);
  TEST_ASSERT_EQUAL_STRING("16", getBuffer(calc));
}

//TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, actual, message); 
  
