#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_flashtiler(void)
{
   CU_PASS("Unit tests operational");
}

int main(void){
CU_initialize_registry();
CU_pSuite pSuite = CU_add_suite("Suite_1", NULL, NULL);
CU_add_test(pSuite, "tiler test", test_flashtiler);
CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_suite(pSuite);
CU_cleanup_registry();
return 0;
}
