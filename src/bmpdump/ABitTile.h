//Allegro Implementation Facade of ABitTile 

#include "BitTile.h"

class ABitTile: public IBitTile{

      public:
	virtual ~ABitTile();
	virtual void loadFTiles(FMap8* p_map);
	virtual void Release();
	virtual void Render();

	static ABitTile* InterfaceGet();

	//Tiles and maps


	private:
	inline ABitTile();

};

extern ABitTile* pABit;
