#include "Map.h"
// #include "../Engimon/EngimonFactory.h"
// ctor
Map::Map() {
    width = 0;
    length = 0;
    nWildEngimon = 0;
}

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

    // random spawn point player
    int x = rand() % 12;
    int y = rand() % 10;

    playerPosition.setX(x);
    playerPosition.setY(y);

    nWildEngimon = 0;
    while(nWildEngimon < 5) GenerateEngimon();
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
    this->nWildEngimon = other.nWildEngimon;
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
            if (isTilePlayerPosition(j, i)) cout << "P";
            // else if(mapMatrix[i][j].isEngimonOccupied()) cout << "E";
            else if(mapMatrix[i][j].getIsEngimonOccupied()) cout << "E";
            else if(mapMatrix[i][j].getType() == "Sea") cout << "o";
            else cout << "-";
            cout << " ";
        }
        cout << endl;
    }
}

// void Map::GenerateEngimon(){
//     // random x
//     int x = rand() % 12;

//     // random y
//     int y = rand() % 10;

//     // random spesies
//     int species = rand() % 10;

//     // random level
//     int level = rand() % 5;

//     if (!mapMatrix[y][x].getIsEngimonOccupied()){
//         Engimon wild = EngimonFactory::createEngimon(species);
//         mapMatrix[y][x].setWildEngimon(&wild);
//         mapMatrix[y][x].getWildEngimon().gainExp(level*100);
//     }

//     nWildEngimon++;
// }

void Map::GenerateEngimon(){
    // random x
    int x = rand() % 12;

    // random y
    int y = rand() % 10;

    // random spesies
    int species = rand() % 10;

    // random level
    int level = rand() % 5;

    if (!mapMatrix[y][x].getIsEngimonOccupied() || isTilePlayerPosition(x, y)){
        mapMatrix[y][x].setIsEngimonOccupied(true);
    }
    nWildEngimon++;
}

bool Map::isTilePlayerPosition(int x, int y){
    return playerPosition.getX() == x && playerPosition.getY() == y;
}

void Map::move(string direction){
    playerPosition.setXY(direction);
    if(isPlayerPositionOutOfRange()) {
        playerPosition.resetXY(direction);
        throw "Map index out of range";
    } else if (isPlayerTileContainEngimon()) {
        cout << "Do you want to do a battle?" << endl;
    }
}

bool Map::isPlayerPositionOutOfRange(){
    return playerPosition.getX() < 0 || playerPosition.getX() >= width || playerPosition.getY() < 0 || playerPosition.getY() >= length; 
}

bool Map::isPlayerTileContainEngimon(){
    return mapMatrix[playerPosition.getY()][playerPosition.getX()].getIsEngimonOccupied();
}