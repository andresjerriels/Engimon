#include "Map.h"

// ctor
Map::Map(string filename)
{
    string line;

    length = 0;
    
    ifstream mapfile(filename);
    while(getline(mapfile, line)){ //ambil line
        width = line.length();
        vector<Tile> linevector;
        for (int i = 0; i < line.length(); i++) {
            if(line[i] == 'o'){
                Tile tile("Sea");
                linevector.push_back(tile);
            }
            else{
                Tile tile("Grassland");
                linevector.push_back(tile);
            }
            
        }
        mapMatrix.push_back(linevector);
        length++;
    }

    // sekalian generate engimon
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
            // if (ada engimon) print blablabla
            if(mapMatrix[i][j].getType() == "Sea") cout << "o";
            else cout << "-";
        }
        cout << endl;
    }
}

void Map::GenerateEngimon(){
    // random x
    int x = rand() % 12;

    // random y
    int y = rand() % 10;

    // random spesies
    int spesies = rand() % 10;

    // random level
    int level = rand() % 5;

    if (!mapMatrix[y][x].getIsEngimonOccupied()){
        if(spesies == 0){
            Charmamon wildEng ("Wild Charmamon");
            mapMatrix[y][x].setWildEngimon(&wildEng);
        }
        // Lanjut else

        // set name, level, dll
    }
}