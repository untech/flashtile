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
(*tpal).palsize = palsize;
(*tpal).cwidth = cbits;
}

void loadFPal8(const unsigned short* src, FPal8* dst){
if(dst == 0){
return;
}
memcpy((*dst).colors,src,sizeof(unsigned short)*(*dst).palsize);
}

FMap8* initFMap8(int width, int height){ //will probably enumerate this
FMap8* fmaps = 0;
fmaps = (FMap8*)malloc(sizeof(FMap8));
(*fmaps).width = width;
(*fmaps).height = height;
(*fmaps).size = width*height;
(*fmaps).tiles = (unsigned short*)malloc(sizeof(unsigned short)*(width*height));
return fmaps;
}

void loadFMap8(FMap8* dst, const unsigned short* src){
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
memcpy((*dst).tiles,src,sizeof(unsigned short)*(*dst).width*(*dst).height);
}

//first function based on unit tests fill in to pass unit test
FTile8* initFTile8(){
FTile8* ptiles = 0;
ptiles = (FTile8*)malloc(sizeof(FTile8));
(*ptiles).pixels = (unsigned char*)malloc(sizeof(unsigned char)*(64));
//(*ptiles).depth = cdepth; //this can probably be deprecated
//stub, put your shit in here

return ptiles;
}

unsigned short getFMapTID(int element, FMap8* src){
return (unsigned short)((*src).tiles[element]);
}

void releaseFTile8(FTile8* ftiles){
free((*ftiles).pixels);
(*ftiles).pixels = NULL;
free(ftiles);
//ftiles = (FTile8*)NULL; have no idea why this lline has no effect 
//Struct pointers are really fucking weird ugh makes me miss C++
}

void releaseFPal8(FPal8* pals){
free((*pals).colors);
(*pals).colors = NULL;
free(pals);
}

void releaseFMap8(FMap8* map){
if(!map){ return; }
free((*map).tiles);
(*map).tiles = NULL;
free(map);
}

void loadFTile8(const unsigned char* src, FTile8* dst){
if(dst == 0){
return;
}
memcpy((*dst).pixels,src,sizeof(unsigned char)*64);
}


