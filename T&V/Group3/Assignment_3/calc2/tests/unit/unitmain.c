#include <CUnit/Basic.h>

#include "test_calc_h.c"

int main(void) {
  CU_pSuite pSuite1 = NULL;
  
  /* Initialize CUnit test registry */
  if(CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* add suite to the registry */
  pSuite1 = CU_add_suite("Suite 1", init_suite, clean_suite);
  if(NULL == pSuite1) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add tests to suite */
  if(NULL == CU_add_test(pSuite1, "Test Equation Chain", testEquation) || NULL == CU_add_test(pSuite1, "Test negatives", testNegatives)
    || NULL == CU_add_test(pSuite1, "Test Unsigned Int Limits ", testUnsignedIntLimits) 
    || NULL == CU_add_test(pSuite1, "Test Signed Int Limits ", testSignedIntLimits) 
    || NULL == CU_add_test(pSuite1, "Test Addition ", testPlus )
    || NULL == CU_add_test(pSuite1, "Test Subtraction ", testMin)
    || NULL == CU_add_test(pSuite1, "Test Multiplication ", testMul)
    || NULL == CU_add_test(pSuite1, "Test Division ", testDiv)
    || NULL == CU_add_test(pSuite1, "Test Max Buffer ", testMaxBuffer)
    || NULL == CU_add_test(pSuite1, "Test Operands ", testOperands)


     // || NULL == CU_add_test(pSuite1, ...[next test case]...)
     ) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using console interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
