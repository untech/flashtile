//Title: FlashTile.c
//Author: Phil Smith && Stevie Frederick
//This serves as the base file for the Flash Tile source.
#include <malloc.h>
#include "flashtile.h"


//first function based on unit tests fill in to pass unit test
FTile8* initFTile8(enum CDEPTH cdepth, enum PXLSZ pixelsz){
FTile8* ptiles = 0;
ptiles = (FTile8*)malloc(sizeof(FTile8));
(*ptiles).pixels = (unsigned char*)malloc(sizeof(unsigned char)*(pixelsz*pixelsz));
(*ptiles).depth = cdepth;
//stub, put your shit in here

return ptiles;
}


