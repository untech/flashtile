#ifndef FLASHTILE_H
#define FLASHTILE_H

enum PALSZ{
PALS_256 = 256,
PALS_512 = 512
};

//TODO Remove
enum CDEPTH{
COLOR_8 = 8,
COLOR_16 = 16
};

//TODO remove implicitly defined based on tile strong TYPE
enum PXLSZ{
PIXEL_8 = 8,
PIXEL_16 = 16
};

//TODO remove
enum CWIDTH{
BITWIDTH_16 = 16,
BITWIDTH_32 = 32,
};

typedef struct{
unsigned short* colors;
enum CWIDTH cwidth;
}FPal8;

//define structure for the tiles right here
typedef struct {
unsigned char* pixels;
enum CDEPTH depth;
} FTile8;
//figure out how to hold palette values or something
// FTile8 *next;
// };

 
typedef struct{
unsigned short* tiles;
//FPal8* palbase;
//FTile8* tilebase;
int height;
int width;
int size; //now necessary
}FMap8;

FTile8* initFTile8();
void loadFTile8(const unsigned char* src, FTile8* dst);
FPal8* initFPal8(enum CWIDTH cbits, enum PALSZ palsize);
void releaseFTile8(FTile8* ftiles);
void loadFPal8(const unsigned short* src, FPal8* dst);
FMap8* initFMap8(int width, int height); //TODO perhaps width and height?
void loadFMap8(FMap8* dst, const unsigned short* src);
 
#endif

