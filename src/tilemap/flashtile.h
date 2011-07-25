#ifndef FLASHTILE_H
#define FLASHTILE_H

enum PALSZ{
PALS_256 = 256,
PALS_512 = 512
};

enum CDEPTH{
COLOR_8 = 8,
COLOR_16 = 16
};

enum PXLSZ{
PIXEL_8 = 8,
PIXEL_16 = 16
};

enum CWIDTH{
BITWIDTH_16 = 16,
BITWIDTH_32 = 32,
};

typedef struct{
unsigned short* colors;
enum CWIDTH cwidth;
}FPal8;

//define structure for the tiles right here
typedef struct{
unsigned char* pixels;
enum CDEPTH depth;
//figure out how to hold palette values or something
}FTile8;
 
typedef struct{
unsigned short* tiles;
FPal8* palbase;
FTile8* tilebase;
int height;
int width;
}FMap8;

FTile8* initFTile8(enum CDEPTH cdepth, enum PXLSZ pixelsz);
void loadFTile8(const unsigned char* src, FTile8* dst);
FPal8* initFPal8(enum CWIDTH cbits, enum PALSZ palsize);
void loadFPal8(const unsigned short* src, FPal8* dst);
FMap8* initFMap8(int width, int height); //TODO perhaps width and height? 
#endif

