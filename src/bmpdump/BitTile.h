//These functions allow for tiles to be shoved into bitmaps and vice versa
//this interface is intended for use with the allegro chain

//DeSignNotes: The BitTile interface serves as a facade for the functionality
//of the entire system along multiple platforms

//in theory implementations of the facade result in platform compatibility

class IBitTile
{
      public:
	virtual ~IBitTile() { }
	virtual loadFTiles() = 0; 
	virtual Release() = 0;

};






