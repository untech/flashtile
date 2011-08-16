//Allegro Implementation Facade of ABitTile 

#include "BitTile.h"
#include "allegro.h"


class ABitTile: public IBitTile{

      public:
	virtual ~ABitTile();
        virtual void loadTiles(int size, unsigned char* src);
        virtual void loadPal(int size, unsigned short* src);
        virtual void loadMap(int size, unsigned short* src);
	virtual void Init();
	virtual void Release();
	virtual void Flush();
	virtual void Render();

	static ABitTile* InterfaceGet();

	//Tiles and maps and palette pointers

	int tilecap;

	FTile8** p_tile; //tile base memory
	FMap8* p_map; //a map
	FPal8* p_pal; //pal memory
	
	//Allegro Specific GFX
	BITMAP *backbuffer; //for double buffering draw to this sucker
	BITMAP *layer1; //Initial test for simple layering the bitmaps levels
	BITMAP *layer2;
	//A map will be drawn to the bitmaps during a flush call
	//Afterwards the surfaces must be blitted to be rendered to the display

	int screenX, screenY; //used for clipping
	int screenW, screenH;

	private:
	inline ABitTile();

};

extern ABitTile* pABit;
