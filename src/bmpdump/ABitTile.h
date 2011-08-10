//Allegro Implementation Facade of ABitTile 

#include "BitTile.h"
#include "allegro.h"


class ABitTile: public IBitTile{

      public:
	virtual ~ABitTile();
        virtual void loadTiles(FTile8* p_tile, int size, unsigned char* src);
        virtual void loadPal(FPal8* p_pal, int size, unsigned short* src);
        virtual void loadMap(FMap8* p_map, int size, unsigned short* src);
	virtual void Init();
	virtual void Release();
	virtual void Render();

	static ABitTile* InterfaceGet();

	//Tiles and maps and palette pointers

	FTile8* p_tile; //tile base memory
	FMap8* p_map; //a map
	FPal8* p_pal; //pal memory
	
	//Allegro Specific GFX
	BITMAP *backbuffer; //for double buffering draw to this sucker
	BITMAP *layer1; //Initial test for simple layering the bitmaps levels
	BITMAP *layer2;

	private:
	inline ABitTile();

};

extern ABitTile* pABit;
