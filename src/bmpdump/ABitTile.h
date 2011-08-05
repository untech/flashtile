//Allegro Implementation Facade of ABitTile 

#include "BitTile.h"
#include "allegro.h"


class ABitTile: public IBitTile{

      public:
	virtual ~ABitTile();
	virtual void loadFTiles(FMap8* p_map);
	virtual void Init();
	virtual void Release();
	virtual void Render();

	static ABitTile* InterfaceGet();

	//Tiles and maps and palette pointers

	FTile8* p_tile;
	FMap8* p_map;
	FPal8* p_pal;
	
	//Allegro Specific GFX
	BITMAP *backbuffer; //for double buffering draw to this sucker
	BITMAP *layer1; //Initial test for simple layering the bitmaps levels
	BITMAP *layer2;

	private:
	inline ABitTile();

};

extern ABitTile* pABit;
