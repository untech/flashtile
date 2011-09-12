//These functions allow for tiles to be shoved into bitmaps and vice versa
//this interface is intended for use with the allegro chain

//DeSignNotes: The BitTile interface serves as a facade for the functionality
//of the entire system along multiple platforms

//in theory implementations of the facade result in platform compatibility



//This structure feeds into the configuration manager

typedef struct BITCAPS{
int screen_w;
int screen_h;
int map_w;
int map_h;
int membank;
int colorD;
}*PBITCAPS;

extern "C" {
#include "../tilemap/flashtile.h" //C includes
}

class IBitTile
{
      public:
	virtual ~IBitTile() { }
	virtual void loadTiles(int size, unsigned char* src) = 0; 
	virtual void loadMap(int width, int height, unsigned short* src) = 0;
	virtual void loadPal(int size, unsigned short* src) = 0;
	virtual void loadSprite(int spriteBank, int width, int height, unsigned short* tilesrc, unsigned short* palsrc, int x, int y) = 0;
	virtual void ChangeBanks(int bank) = 0;
	virtual void Release() = 0;
	virtual void Flush() = 0;
	virtual void FlushBank() = 0;
	virtual void Render() = 0;
	virtual void PushConfig(PBITCAPS bitconfig) = 0;
	virtual void Init() = 0;
};

extern IBitTile* createAxBitTile();





