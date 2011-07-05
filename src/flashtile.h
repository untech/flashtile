#ifndef FLASHTILE_H
#define FLASHTILE_H

//define structure for the tiles right here
typedef struct{
unsigned short int* tiles16;
//figure out how to hold palette values or something
}FTile16;
 
FTile16* initFTile16(void);

#endif

