//This file serves as the facade necessary to render out to Allegro 

//NOTES: The Allegro and SDL Facade unlike console mechanisms construct their
//own render pipeline. This assumes certain factors correlating to the general
//mechanics of generic hardware both desktop and embedded (for Android SDL
//purposes).

//This Allegro facade to the main pipeline operates by setting characteristics
//of the render pipeline and graphics hardware during the init phase.
//
//Given the nature of the facade here, the constructed vtable, will be filled
//in with the functions assigned from an individuals create##BitTile() function
//Allegro is the sandbox platform. And changes will like cascade from this
//platform, using the NDS as an ideal.

#define TILEMEM 128

#include "ABitTile.h"

ABitTile* pABit = 0;
int pARef = 0;

IBitTile* createAxBitTile(){
return (IBitTile*)ABitTile::InterfaceGet();
}

ABitTile* ABitTile::InterfaceGet(){


if(!pABit)
pABit = new ABitTile();

pARef++;
return pABit;
}


ABitTile::~ABitTile(){

}

ABitTile::ABitTile(){
tilecap = 0; //current load of the first pool
palcap = 0;
//Base memory instantiation

//Flash Memory Pool/Memory "Bank"
//Tile Pool 1 TODO make more tilepools if this works
//A pool of tiles. Destruction method needed
p_tile = new FTile8*[TILEMEM];
//Allocate tile memory in software
for(int i = 0; i < TILEMEM; i++){
p_tile[i] = initFTile8(); //kinda tile pool
}
p_pal = initFPal8(BITWIDTH_16, PALS_256);
//TODO SBB/CBB for Nintendo based hardware? 
p_map = initFMap8(256,256); //TODO add variable length in the future

}

//Flush the current tileset to bitmaps which can be placed into memory
void ABitTile::Flush(){
BITMAP* tempbittile = create_bitmap(8, 8);
for(int i = 0; i < tilecap; i++){
FTile8* temptile = p_tile[i];

for(int k = 0; k < 64; k++){
int px = (*temptile).pixels[k];
int rawcol = (*p_pal).colors[px];
int r_red = (31 & rawcol)*8;
int r_green = (((31 << 5) & rawcol) >> 5)*8;
int r_blue = (((31 << 10) & rawcol) >> 10)*8;
int realcol = makecol15(r_red, r_green, r_blue);

putpixel(tempbittile, k%8, (int)(k/8), realcol);
}
blit(tempbittile, tileset, 0, 0, (i*8)%(8*(TILEMEM/2)), ((i*8)/(8*(TILEMEM/2)))*8,8,8);
}

}

void ABitTile::Render(){
this->showTiles();
blit(backbuffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}

void ABitTile::showTiles(){
blit(tileset, backbuffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}

void ABitTile::Init(){
allegro_init();
install_keyboard(); //Comment this out when InputController constructed
set_color_depth(15);
set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);


tileset = create_bitmap(8*(TILEMEM/2),8*(TILEMEM/2));
backbuffer = create_bitmap(SCREEN_W, SCREEN_H);
layer1 = create_bitmap(256*8,256*8);

}

void ABitTile::Release(){
pARef--;
if(!pARef){
delete pABit;
pABit = 0;
}
}


//Controlled by config flags in the FlashConfig API call
void ABitTile::loadTiles(int size, unsigned char* src){
if(size%64 != 0){
return;
}
if(size/64 > TILEMEM){
return;
}
for(int i = 0; i<size/64; i++){
loadFTile8((const unsigned char*)(&src[i*64]),p_tile[i]);
tilecap += 1;
}

} 

void ABitTile::loadPal(int size, unsigned short* src){
if(size > 256){ //TODO make variable (one great refactor I won't mind)
return;
}
loadFPal8((const unsigned short*)src, p_pal);
palcap = size;
}


void ABitTile::loadMap(int width, int height, unsigned short* src){ //TODO this will need width and height
if(width > 256 || height > 256){
return;
}
loadFMap8(p_map, (const unsigned short*)src); //This map points to layer 1 of
//the screen
}

