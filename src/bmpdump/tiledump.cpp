//These functions allow for tiles to be shoved into bitmaps and vice versa
//this interface is intended for use with the allegro chain

class IBitTile
{
      public:
	virtual ~IBitTile() { }
	virtual loadFTiles() = 0; 
	virtual Release() = 0;

};

//Streams tiles from a map to a bmp object
void createIBitTile(){
   



}

