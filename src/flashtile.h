#ifndef FLASHTILE_H
#define FLASHTILE_H

enum CDEPTH{
COLOR_8 = 8,
COLOR_16 = 16
};

enum PXLSZ{
PIXEL_8 = 8,
PIXEL_16 = 16
};

//define structure for the tiles right here
typedef struct{
unsigned char* pixels;
enum CDEPTH depth;
//figure out how to hold palette values or something
}FTile8;
 
FTile8* initFTile8(enum CDEPTH cdepth, enum PXLSZ pixelsz);

#endif

