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

	


	private:
	inline ABitTile();

};

extern ABitTile* pABit;
