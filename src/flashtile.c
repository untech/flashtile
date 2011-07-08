//Title: FlashTile.c
//Author: Phil Smith && Stevie Frederick
//This serves as the base file for the Flash Tile source.
#include <malloc.h>
#include <string.h>
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

void loadFTile8(const unsigned char* src, FTile8* dst){
if(dst == 0){
return;
}
if(sizeof(src) != sizeof((*dst).pixels)){
return;
}
memcpy((*dst).pixels,src,sizeof((*dst).pixels));
}


