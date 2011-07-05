#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/flashtile.h"

//write a function initFTile16(); that will take a struct type 
//that is an unsigned short 

//this tests the basic functionality of the FTile typedef using initFTile
//then testing to see if it can set the value of a middle spot in the memory
//array
void test_flashtiler(void)
{  
   FTile16* ftiles = initFTile16();
   if(ftiles == NULL){
      CU_FAIL("tiles not initalized, requirement failure, redo");
      return;
   }else{
   (*ftiles).tiles16[5] = 0x45ff;
   CU_ASSERT(0x45ff == (*ftiles).tiles16[5]);
   }
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
