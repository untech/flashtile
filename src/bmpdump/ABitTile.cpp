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

#define BGMEM 4
#define TILEMEM 128
#define SPRITEMEM 128

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
initbit = false;
tilecap = 0; //current load of the first pool
palcap = 0;
r_config = 0;
r_bits = 0;

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
//p_map = initFMap8(256,256); //TODO add variable length in the future

}

//Flush the current tileset to bitmaps which can be placed into memory
//TODO This is where transparency should appear
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
blit(tempbittile, tileset, 0, 0,0,(i*8),8,8);
}

}

void ABitTile::SetRenderFlags(int flags){
r_bits = flags;
}

void ABitTile::SetRenderParams(PRPARAMS params){
r_config = params;
}

//TODO Remove dummy
void ABitTile::Render(){

if(r_bits & RENDER_0){
this->ChangeBanks(0);
blit(curlayer, backbuffer, (*r_config).screenX, (*r_config).screenY, 0, 0, SCREEN_W, SCREEN_H);
}

if(r_bits & RENDER_1){
this->ChangeBanks(1);
blit(curlayer, backbuffer, (*r_config).screenX, (*r_config).screenY, 0, 0, SCREEN_W, SCREEN_H);
}

if(r_bits & RENDER_2){
this->ChangeBanks(2);
blit(curlayer, backbuffer, (*r_config).screenX, (*r_config).screenY, 0, 0, SCREEN_W, SCREEN_H);
}

if(r_bits & RENDER_3){
this->ChangeBanks(3);
blit(curlayer, backbuffer, (*r_config).screenX, (*r_config).screenY, 0, 0, SCREEN_W, SCREEN_H);
}

blit(backbuffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

}

void ABitTile::showTiles(){
blit(tileset, backbuffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}
//End dummy

//flushes current banks map-tile correlation to bmp memory
void ABitTile::FlushBank(){
//fix up, look sharp.
int memElement = 0; //for locking the steps in the loop
bool flipbit = false;
unsigned short tileid;
int tilememcoord;
BITMAP* tmpmap = create_bitmap(8,8);
BITMAP* flipmap = create_bitmap(8,8);
//go through every tile on the image
//blit it

//UGH someone find a way to unroll this in the future
for(int i = 0; i < mapH; i++){
for(int j = 0; j < mapW; j++){
//retrieve tileID from the current map object in foreground mem
//get map[]
tileid = getFMapTID(memElement, p_map);

//get the coordinate in memory
tilememcoord = (0x3FF & tileid);

//frankie told me to parse flipping bits
int vflip = (0x800 & tileid);
int hflip = (0x400 & tileid);
/* tile id is parsed, perhaps optimize this routine? 
   Based on Nintendo Spec this is where hardware specifics come in 
   Perhaps scale reqs through the interface facade
*/

if(vflip || hflip){
flipbit = true;
//copy to tmp buffer
blit(tileset, tmpmap, 0, 8*(tilememcoord), 0, 0, 8, 8);
}

//flip the tile vertically and put in tmp space
if(vflip){
//flip it
draw_sprite_v_flip(flipmap, tmpmap, 0, 0);
//then copy back
blit(flipmap, tmpmap, 0, 0, 0, 0, 8, 8);
}

//flip the tile horizontally and put in tmp space
if(hflip){
draw_sprite_h_flip(flipmap, tmpmap, 0, 0);
blit(flipmap, tmpmap, 0, 0, 0, 0, 8, 8);
}

//if the tile is flipped
if(flipbit){
blit(tmpmap, curlayer, 0, 0, j*8, i*8, 8, 8);
}

//if the tile is not flipped
if(!flipbit){
blit(tileset, curlayer, 0, 8*tilememcoord /*tilememXY */, j*8, i*8, 8, 8); //check math and compl.
}
flipbit = false; //no matter what flipbit is reset after each tile copies
memElement += 1;
}
}

//finished blitting? Ready to put on the back buffer! (separate function)

}


//brings a bank to the foreground
void ABitTile::ChangeBanks(int bank){
if(bank < 0 || bank > 3) { return; } //safeguard

tileset = tilebanks[bank];
curlayer = layers[bank];
p_map = p_mapbank[bank];
mapH = p_map->height;
mapW = p_map->width;
}

//Make sure a config is pushed before a bank is used
//TODO: Make a lock that prevents memeory writes to non-configured banks
//(Re)configures the engine stats 
void ABitTile::PushConfig(PBITCAPS bitconfig){
if(initbit == false){
screenW = bitconfig->screen_w;
screenH = bitconfig->screen_h;}
mapW = bitconfig->map_w;
mapH = bitconfig->map_h;
//ignore color depth for now
if(initbit == true){ //this switch will (re)initialize the mem banks /w config

if(bitconfig->membank < 0 || bitconfig->membank > 3){ return; } //safeguard

BITMAP* Ttileset = tilebanks[bitconfig->membank];
BITMAP* Tcurlayer = layers[bitconfig->membank];
FMap8* Tp_map = p_mapbank[bitconfig->membank];

destroy_bitmap(Ttileset);
destroy_bitmap(Tcurlayer);
releaseFMap8(Tp_map);

//And change here too
Ttileset = create_bitmap(8,8*(TILEMEM));
Tcurlayer = create_bitmap(mapW*8,mapH*8);
Tp_map = initFMap8(mapW, mapH);

tilebanks[bitconfig->membank] = Ttileset;
layers[bitconfig->membank] = Tcurlayer;
p_mapbank[bitconfig->membank] = Tp_map;

}

}

void ABitTile::ConfigSprite(int spriteBank, int x, int y){
spriteXs[spriteBank] = x;
spriteYs[spriteBank] = y;
}

//Make sure engine is configured before initialising the engine
void ABitTile::Init(){
allegro_init();
install_keyboard(); //Comment this out when InputController constructed
set_color_depth(15);
set_gfx_mode(GFX_AUTODETECT_WINDOWED, screenW, screenH, 0, 0);
backbuffer = create_bitmap(SCREEN_W, SCREEN_H);

tilebanks = new BITMAP* [4];
layers = new BITMAP* [4]; 
p_mapbank = new FMap8* [4];


//Change Dimensional Blit here here
tileset = create_bitmap(8,8*(TILEMEM));
curlayer = create_bitmap(mapW*8,mapH*8);
p_map = initFMap8(mapW,mapH);

curbank = 0;
tilebanks[0] = tileset; //initial tileset
layers[0] = curlayer;
p_mapbank[0] = p_map;

initbit = true;

//layer1 = create_bitmap(mapW*8,mapH*8);
//finish up the base init after first config is pushed

//defining sprite refs here seems okay...probably will need
//someone to come in and do some tweaking
spriteXs = new int[SPRITEMEM];
spriteYs = new int[SPRITEMEM];
spriterefs = new BITMAP* [SPRITEMEM];

}

void ABitTile::Release(){
pARef--;
if(!pARef){
delete pABit; //destructor should take care of deallocation
pABit = 0;
}
}

void ABitTile::loadSprite(int spriteBank, int width, int height, unsigned short* tilesrc, unsigned short* palsrc, int x, int y){


spritrefs[spriteBank] = create_bitmap(width, height); 


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


void ABitTile::loadMap(int width, int height, unsigned short* src){ //TODO remove width and height base on bank
//if(width > 256 || height > 256){
//return;
//}
loadFMap8(p_map, (const unsigned short*)src); //Cur map bank


}


