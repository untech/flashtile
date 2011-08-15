//This file serves as the facade necessary to render out to Allegro 

#define TILEMEM 100

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
//A pool of tiles. Destruction method needed
p_tile = new FTile8*[TILEMEM];
//Allocate tile memory in software
for(int i = 0; i < TILEMEM; i++){
p_tile[i] = initFTile8(); //kinda tile pool
}

}

//Flush the current tileset to bitmaps which can be placed into memory
void ABitTile::Flush(){


}

void ABitTile::Render(){


}

void ABitTile::Init(){
allegro_init();
install_keyboard(); //Comment this out when InputController constructed
set_color_depth(16);
set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
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



} 

void ABitTile::loadPal(int size, unsigned short* src){



}


void ABitTile::loadMap(int size, unsigned short* src){

}

