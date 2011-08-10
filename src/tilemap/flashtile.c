//Title: FlashTile.c
//Author: Phil Smith && Stevie Frederick
//This serves as the base file for the Flash Tile source.
#include <malloc.h>
#include <string.h>
#include "flashtile.h"

FPal8* initFPal8(enum CWIDTH cbits, enum PALSZ palsize){
FPal8* tpal = 0;
tpal = (FPal8*)malloc(sizeof(FPal8));
(*tpal).colors = (unsigned short*)malloc(sizeof(unsigned short)*(palsize));
(*tpal).cwidth = cbits;
}

void loadFPal8(const unsigned short* src, FPal8* dst){
if(dst == 0){
return;
}
if(sizeof(src) != sizeof((*dst).colors)){
return;
}
memcpy((*dst).colors,src,sizeof(unsigned short)*128);
}

FMap8* initFMap8(int width, int height){ //will probably enumerate this
FMap8* fmaps = 0;
fmaps = (FMap8*)malloc(sizeof(FTile8));
(*fmaps).size = width*height;
(*fmaps).tiles = (unsigned short*)malloc(sizeof(unsigned short)*(width*height));
(*fmaps).tilebase = 0;
(*fmaps).palbase = 0;
return fmaps;
}

void loadFMap8(FTile8* tilebase, FPal8* palbase, FMap8* dst, const unsigned short* src){
if(src == 0){
return;
}
if(!(*dst).width || !(*dst).height){
return;
}
if(sizeof(src) != sizeof((*dst).tiles)){
return;
}
//load up the tiles
memcpy((*dst).tiles,src,sizeof(unsigned short)*15*15);
(*dst).tilebase = tilebase;
(*dst).palbase = palbase;
}

//first function based on unit tests fill in to pass unit test
FTile8* initFTile8(enum CDEPTH cdepth, enum PXLSZ pixelsz){
FTile8* ptiles = 0;
ptiles = (FTile8*)malloc(sizeof(FTile8));
(*ptiles).pixels = (unsigned char*)malloc(sizeof(unsigned char)*(pixelsz*pixelsz));
(*ptiles).depth = cdepth; //this can probably be deprecated
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
memcpy((*dst).pixels,src,sizeof(unsigned char)*64);
}


