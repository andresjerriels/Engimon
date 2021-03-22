#include "Map.h"
#include "../Engimon/EngimonFactory.h"

map<char, Position*> Map::moveMap = {
    {'w', new Position(0, -1)},
    {'a', new Position(-1, 0)},
    {'s', new Position(0, 1)},
    {'d', new Position(1, 0)}
};

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

    // random spawn point player
    int x = rand() % 12;
    int y = rand() % 10;

    playerPosition.setX(x);
    playerPosition.setY(y);

    while(nWildEngimon < 5) GenerateEngimon();

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
            if (isPlayerPosition(j, i)) cout << "P";
            else if(mapMatrix[i][j].isEngimonOccupied()) cout << "E";
            else if(mapMatrix[i][j].getType() == "Sea") cout << "o";
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
    int species = rand() % 10;

    // random level
    int level = rand() % 5;

    if (!mapMatrix[y][x].getIsEngimonOccupied()){
        mapMatrix[y][x].setWildEngimon(&EngimonFactory::createEngimon(species));
        mapMatrix[y][x].getWildEngimon().gainExp(level*100);
    }

    nWildEngimon++;
}

bool Map::isPlayerPosition(int x, int y){
    return playerPosition.getX() == x && playerPosition.getY() == y;
}

void Map::move(char direction){
    Position *moveDirection = moveMap[direction];
    playerPosition = playerPosition + *moveDirection;

    if(playerPosition.getX() < 0 || playerPosition.getY() < 0){
        playerPosition = playerPosition - *moveDirection;
        delete moveDirection;
        throw "Position out of bound";
    }

    delete moveDirection;
}

Position::Position(){
    x = 0;
    y = 0;
}

Position::Position(int _x, int _y){
    x = _x;
    y = _y;
}

int Position::getX(){
    return x;
}

int Position::getY(){
    return y;
}

void Position::setX(int _x){
    x = _x;
}

void Position::setY(int _y){
    y = _y;
}

Position Position::operator+(Position& const other){
    Position newPosition((this->x + other.getX()), (this->y + other.getY()));
    return newPosition;
}

Position Position::operator-(Position& const other){
    Position newPosition((this->x - other.getX()), (this->y - other.getY()));
    return newPosition;
}