// Based on Unity code examples
// (see file 'examples/test/no_ruby/TestProductionCode_Runner.c'
//  in the Unity distribution folder)

#include "unitytest.c"

static void runTest(UnityTestFunction test)
{
  if (TEST_PROTECT())
    {
      setUp();
      test();
    }
  if (TEST_PROTECT() && !TEST_IS_IGNORED)
    {
      tearDown();
    }
}

void resetTest()
{
  tearDown();
  setUp();
}

int main(void)
{
  RUN_TEST(test_DigitsChangeBuffer,23);
  RUN_TEST(test_Sum,31);
}

