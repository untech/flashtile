#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../../src/tilemap/flashtile.h"
#include "flashcases.h"

//write a function initFTile16(); that will take a struct type 
//that is an unsigned short 

//this tests the basic functionality of the FTile typedef using initFTile
//then testing to see if it can set the value of a middle spot in the memory
//array

//TODO remove Color Depth, inherant in tile set and PAL width
//this includes PAL width C width
//TODO size of tests for all tiles test (pal too)

void test_flashtiles(void)
{  
//Test the initialization into memory
   FTile8* ftiles = initFTile8();
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
   FTile8* ftiles = initFTile8();
   if(ftiles == NULL){
      CU_FAIL("tiles not initalized, requirement failure, redo");
      return;
   }else{
   loadFTile8(testTile, ftiles);
   CU_ASSERT(1 == (*ftiles).pixels[62]);
   }
//   releaseFTile8(ftiles);
}

void test_flashtiledestroy(void)
{
   FTile8* ftiles = initFTile8();
   if(ftiles == NULL){
	CU_FAIL("memory failure");
        return;
    }
   releaseFTile8(ftiles);
   CU_ASSERT((*ftiles).pixels == NULL);
}

void test_flashpals(){
    FPal8* fpals = initFPal8(16, 256);
    if(fpals == NULL){
         CU_FAIL("pals failure");
         return;
   }
   (*fpals).colors[4] = 3;
   CU_ASSERT(3 == (*fpals).colors[4]);
}

void test_flashpalsload(){
    FPal8* fpals = initFPal8(16, 256);
    if(fpals == NULL){
         CU_FAIL("pals failure");
         return;
    }
   loadFPal8(testPal,fpals);
   CU_ASSERT(1 == (*fpals).colors[244]);
   CU_ASSERT(1 != (*fpals).colors[255]);
}

void test_flashmap(){
    FMap8* fmap = initFMap8(15,15);
    if(fmap == NULL){
	CU_FAIL("map init failure");
	return;
    }
   (*fmap).tiles[192] =  5;
   CU_ASSERT(15 == (*fmap).width);
   CU_ASSERT(15 == (*fmap).height);
   CU_ASSERT(5 == (*fmap).tiles[192]);
}
 
void test_flashmapload(){
    FMap8* fmap = initFMap8(15,15);
    if(fmap == NULL){
       	CU_FAIL("map init failure");
	return;
    }
    loadFMap8(fmap, testMap);

    CU_ASSERT(3 == ((*fmap).tiles[4]));

}

int main(void){
CU_initialize_registry();
CU_pSuite pSuite = CU_add_suite("Suite_1", NULL, NULL);
CU_add_test(pSuite, "tiler mem test", test_flashtiles);
CU_add_test(pSuite, "tiler load test", test_flashtileload);
CU_add_test(pSuite, "tiler release test", test_flashtiledestroy);
CU_add_test(pSuite, "pal mem test", test_flashpals);
CU_add_test(pSuite, "pal load test", test_flashpalsload);
CU_add_test(pSuite, "map mem test", test_flashmap);
CU_add_test(pSuite, "map load test", test_flashmapload);
CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_tests();
CU_cleanup_registry();
return 0;
}


