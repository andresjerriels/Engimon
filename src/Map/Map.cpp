#include "Map.h"

// ctor
Map::Map(string filename)
{
    string line;

    length = 0;
    
    ifstream mapfile(filename);
    while(getline(mapfile, line)){
        width = line.length();
        vector<Tile> linevector;
        for (int i = 0; i < line.length(); i++) {
            if(line[i] == 'o'){
                Tile tile("Sea");
                linevector.insert(linevector.begin() + i, tile);
            }
            else{
                Tile tile("Grassland");
                linevector.insert(linevector.begin() + i, tile);
            }
            
        }
        mapMatrix.insert(mapMatrix.begin() + length, linevector);
        length++;
    }
}

// dtor
Map::~Map()
{

}

// cctor
Map::Map(const Map& other){
    this->mapMatrix = other.mapMatrix;
    this->width = other.width;
    this->length = other.length;
}

// assignment operator
Map& Map::operator= (const Map& other){
    if (this != &other) {
        this->mapMatrix = other.mapMatrix;
        this->width = other.width;
        this->length = other.length;
    }
    return *this;
}

void Map::PrintMap(){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
            if(mapMatrix[i][j].getType() == "Sea") cout << "o";
            else cout << "-";
        }
        cout << endl;
    }
}