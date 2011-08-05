//These functions allow for tiles to be shoved into bitmaps and vice versa
//this interface is intended for use with the allegro chain

//DeSignNotes: The BitTile interface serves as a facade for the functionality
//of the entire system along multiple platforms

//in theory implementations of the facade result in platform compatibility


extern "C" {
#include "../tilemap/flashtile.h" //C includes
}

class IBitTile
{
      public:
	virtual ~IBitTile() { }
	virtual void loadFTiles(FMap8* p_map) = 0; 
	virtual void Release() = 0;
	virtual void Render() = 0;
	virtual void Init() = 0;

};






