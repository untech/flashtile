//This file serves as the facade necessary to 

#include "ABitTile.h"
#include "allegro.h"

IBitTile* createAxBitTile(){
return (IBitTile*)ABitTile::InterfaceGet();
}

ABitTile* ABitTile::InterfaceGet(){

if(!pABit)
pABit = new ABitTile();

pARef++;
return pABit;
}


ABitTile::ABitTile(){

}

void ABitTile::Render(){


}

void ABitTile::Release(){
pARef--;
if(!pARef){
delete pABit;
pABit = 0;
}
}

void ABitTile::loadFTiles(FMap8* p_map){



} 
