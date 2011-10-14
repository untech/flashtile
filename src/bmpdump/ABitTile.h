//Allegro Implementation Facade of ABitTile 

#include "BitTile.h"
#include "allegro.h"

//After background basics are written
//TODO Sprite Control
//TODO Abstract Render Controller for the mega world


class ABitTile: public IBitTile{

      public:
	virtual ~ABitTile();
        virtual void loadTiles(int size, unsigned char* src);
        virtual void loadPal(int size, unsigned short* src);
        virtual void loadMap(int width, int height, unsigned short* src);
	virtual void loadSprite(int spriteBank, int width, int height, unsigned short* tilesrc, unsigned short* palsrc, int x, int y);
	virtual void ChangeBanks(int bank);
	virtual void Init();
	virtual void Release();
	virtual void Flush();
	virtual void FlushBank();
	virtual void SetRenderFlags(int flags);
	virtual void SetRenderParams(PRPARAMS params);
	virtual void Render();
	virtual void PushConfig(PBITCAPS bitconfig);


	static ABitTile* InterfaceGet();

	void showTiles(); //Render tiles to screen for render testing

	//init stuff
	bool initbit;

	//Tiles and maps and palette pointers

	int curbank; //bank changing
	BITMAP** tilebanks;
	FMap8** p_mapbank;
	

	int tilecap; //pool loads
	int palcap;

	//Allegro Specific GFX
	FTile8** p_tile; //current tile base memory (flush load only)
	FMap8* p_map; //current map in memory context for bank flush
	FPal8* p_pal; //current pal memory for tile flush (flush load only)
	
	BITMAP *tileset; //first of many tileset memory banks
	BITMAP *backbuffer; //for double buffering draw to this sucker
	BITMAP *curlayer; //currently framed layer; use as a pointer not a bmp
	BITMAP** layers; //Bank of layers

	BITMAP** spriterefs; //reference to sprite objects

	//A map will be drawn to the bitmaps during a flush call
	//Afterwards the surfaces must be blitted to be rendered to the display

	int screenX, screenY; //used for clipping
	int screenW, screenH;

	int mapW, mapH; //for map configuration within the system

	private:
	inline ABitTile();

};

extern ABitTile* pABit;
