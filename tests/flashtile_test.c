#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/flashtile.h"
#include "flashcases.h"

//write a function initFTile16(); that will take a struct type 
//that is an unsigned short 

//this tests the basic functionality of the FTile typedef using initFTile
//then testing to see if it can set the value of a middle spot in the memory
//array
void test_flashtiles(void)
{  
//Test the initialization into memory
   FTile8* ftiles = initFTile8(8, 256);
   if(ftiles == NULL){
      CU_FAIL("tiles not initalized, requirement failure, redo");
      return;
   }else{
   (*ftiles).pixels[5] = 0x45;
   CU_ASSERT(0x45 == (*ftiles).pixels[5]);
//   destroyFTile8(ftiles);
   }
}
//Test batch initialization into memory




void test_flashtileload(void)
{
//Test the pixels
   FTile8* ftiles = initFTile8(8, 256);
   if(ftiles == NULL){
      CU_FAIL("tiles not initalized, requirement failure, redo");
      return;
   }else{
//   loadFTile8(testTile, ftiles);
   CU_ASSERT(2 == (*ftiles).pixels[5]);
   }
//   destroyFTile8(ftiles);
}

int main(void){
CU_initialize_registry();
CU_pSuite pSuite = CU_add_suite("Suite_1", NULL, NULL);
CU_add_test(pSuite, "tiler mem test", test_flashtiles);
CU_add_test(pSuite, "tiler load test", test_flashtileload);
CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_tests();
CU_cleanup_registry();
return 0;
}
