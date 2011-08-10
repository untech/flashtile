//This file serves as the facade necessary to render out to Allegro 

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

}

void ABitTile::Render(){


}

void ABitTile::Init(){
allegro_init();
install_keyboard();
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

void ABitTile::loadTiles(FTile8* p_tile, int size, unsigned char* src){



} 

void ABitTile::loadPal(FPal8* p_pal, int size, unsigned short* src){



}


void ABitTile::loadMap(FMap8* p_map, int size, unsigned short* src){

}

