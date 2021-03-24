#include "Map.h"
#include <stdlib.h>

// map<vector<Element>, char> Map::ElementCode = {
//     {{WATER}, 'w'}, {{ICE}, 'i'},  {{FIRE}, 'f'}, {{GROUND}, 'g'},
//     {{ELECTRIC}, 'e'}, {{FIRE, ELECTRIC}, 'l'}, {{WATER, ICE}, 's'}, {{WATER, GROUND}, 'n'},
//     {{ELECTRIC, FIRE}, 'l'}, {{ICE, WATER}, 's'}, {{GROUND, WATER}, 'n'}};

int Map::maxWildEngimon = 10;

Map::Map(){

}

Map::Map(string filename)
{
    srand((unsigned) time(0));
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
        initializeElementCode();
    }
    // random spawn point player
    int x = rand() % 12;
    int y = rand() % 10;
    
    playerPosition.setX(x);
    playerPosition.setY(y);
    
    nWildEngimon = 0;
    while(nWildEngimon < 5) GenerateEngimon();
    
    levelCapslock = 3;
}

// dtor
Map::~Map()
{

}
// cctor
Map::Map(const Map& other){
    mapMatrix = other.mapMatrix;
    width = other.width;
    length = other.length;
    nWildEngimon = other.nWildEngimon;
    playerPosition = other.playerPosition;
    levelCapslock = other.levelCapslock;
    initializeElementCode();
}

// assignment operator
Map& Map::operator= (const Map& other){
    if (this != &other) {
        mapMatrix = other.mapMatrix;
        width = other.width;
        length = other.length;
        nWildEngimon = other.nWildEngimon;
        playerPosition = other.playerPosition;
        levelCapslock = other.levelCapslock;
    }
    initializeElementCode();
    return *this;
}

void Map::PrintMap(){
    for (int i = -1; i <= length; i++){
        for (int j = -1; j <= width; j++){
            // if (ada engimon) print blablabla
            if(isPositionOutOfRange(j,i)){
                cout << "*";
            }
            else if (isTilePlayerPosition(j, i)){
                cout << "\033[1;33m";
                cout << "P";
            }
            else if(mapMatrix[i][j].isEngimonOccupied()){
                cout << "\033[1;31m";
                if(mapMatrix[i][j].getWildEngimon().getLevel() > levelCapslock) cout << (char) (toupper(ElementCode[mapMatrix[i][j].getWildEngimon().getElements()]));
                else cout << ElementCode[mapMatrix[i][j].getWildEngimon().getElements()];
            }
            else if(mapMatrix[i][j].getType() == "Sea"){
                cout << "\033[1;34m";
                cout << "o";
            }
            else{
                cout << "\033[1;32m";
                cout << "-";
            }
            cout << " \033[0m";
        }
        cout << endl;
    }
}

void Map::GenerateEngimon(){
    if(nWildEngimon < maxWildEngimon && (rand() % 5)){
        srand((unsigned) time(0));
        int species;
        // random x
        int x = rand() % 12;

        // random y
        int y = rand() % 10;

        // random level
        int level = rand() % 5; // ini belom fix
        Tile* tile = &mapMatrix[y][x];
        if (!tile->isEngimonOccupied() && !isTilePlayerPosition(x,y)){
            if(tile->getType() == "sea") species = rand() % 6; //species grassland: 0 - 5
            else species = rand() % 5 + 5; // species sea: 5 - 9

            Engimon *wild = EngimonFactory::createEngimon(species);
            wild->gainExp(level*100 + rand() % 99);
            tile->setWildEngimon(wild);
            nWildEngimon++;
        }
    }
}

bool Map::isTilePlayerPosition(int x, int y){
    return playerPosition.getX() == x && playerPosition.getY() == y;
}

void Map::move(char direction){
    playerPosition.setXY(direction);
    if(isPlayerPositionOutOfRange()) {
        playerPosition.resetXY(direction);
        throw "Auch, you hit an invisible wall!";
    } else if(mapMatrix[playerPosition.getY()][playerPosition.getX()].isEngimonOccupied()) {
        playerPosition.resetXY(direction);
        throw "Auch, a wild engimon bit you!";
    }
    moveWildEngimon();
    GenerateEngimon();
    
    if (isPlayerTileContainEngimon()) {
        cout << "Do you want to do a battle?" << endl;
    }
}

bool Map::isPositionOutOfRange(int x, int y){
    return x < 0 || x >= width || y < 0 || y >= length;
}

bool Map::isPlayerPositionOutOfRange(){
    return playerPosition.getX() < 0 || playerPosition.getX() >= width || playerPosition.getY() < 0 || playerPosition.getY() >= length; 
}

bool Map::isPlayerTileContainEngimon(){
    return mapMatrix[playerPosition.getY()][playerPosition.getX()].isEngimonOccupied();
}

void Map::moveWildEngimon(){
    srand((unsigned) time(0));
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
            if(mapMatrix[i][j].isEngimonOccupied() && rand() % 2){
                int direction = rand() % 4;
                switch (direction)
                {
                case 0: // ke atas
                    if(i-1 >= 0 && i < length && !mapMatrix[i-1][j].isEngimonOccupied() && !isTilePlayerPosition(j,i-1)){
                        mapMatrix[i-1][j].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].moveWildEngimon();
                    }
                    break;
                case 1: // ke kiri
                    if(j < width && j-1 >= 0 && !mapMatrix[i][j-1].isEngimonOccupied() && !isTilePlayerPosition(j-1,i)){
                        mapMatrix[i][j-1].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].moveWildEngimon();
                    }
                    break;
                case 2: // ke bawah
                    if(i+1 < length && i >= 0 && !mapMatrix[i+1][j].isEngimonOccupied() && !isTilePlayerPosition(j,i+1)){
                        mapMatrix[i+1][j].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].moveWildEngimon();
                    }
                    break;
                case 3: // ke kanan
                    if(j >= 0 && j+1 < width && !mapMatrix[i][j+1].isEngimonOccupied() && !isTilePlayerPosition(j+1,i)){
                        mapMatrix[i][j+1].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].moveWildEngimon();
                    }
                    break;
                
                default:
                    break;
                }
            }
        }
    }

}

void Map::changeLevelCapslock(){
    cout << "Masukkan level baru: ";
    cin >> levelCapslock;
}

vector <Tile*> Map::getTilesWithEngimonAroundPlayer(){
    vector <Tile*> tilesWithEngimon;
    int x = playerPosition.getX();
    int y = playerPosition.getY();
    if(y != 0 && mapMatrix[y - 1][x].isEngimonOccupied()) tilesWithEngimon.push_back(&mapMatrix[y - 1][x]);
    if(y != length - 1 && mapMatrix[y + 1][x].isEngimonOccupied()) tilesWithEngimon.push_back(&mapMatrix[y + 1][x]);
    if(x != 0 && mapMatrix[y][x - 1].isEngimonOccupied()) tilesWithEngimon.push_back(&mapMatrix[y][x - 1]);
    if(x != width - 1 && mapMatrix[y][x + 1].isEngimonOccupied()) tilesWithEngimon.push_back(&mapMatrix[y][x + 1]);
    return tilesWithEngimon;
}

void Map::initializeElementCode(){
    //water
    vector<Element> elements;
    elements.push_back(WATER);
    ElementCode.insert(make_pair(elements, 'w'));

    //ice
    elements.clear();
    elements.push_back(ICE);
    ElementCode.insert(make_pair(elements, 'i'));

    //fire
    elements.clear();
    elements.push_back(FIRE);
    ElementCode.insert(make_pair(elements, 'f'));

    //GROUND
    elements.clear();
    elements.push_back(GROUND);
    ElementCode.insert(make_pair(elements, 'g'));

    //ELECTRIC
    elements.clear();
    elements.push_back(ELECTRIC);
    ElementCode.insert(make_pair(elements, 'e'));

    //FIRE/ELECTRIC
    elements.clear();
    elements.push_back(FIRE);
    elements.push_back(ELECTRIC);
    ElementCode.insert(make_pair(elements, 'l'));

    elements.clear();
    elements.push_back(ELECTRIC);
    elements.push_back(FIRE);
    ElementCode.insert(make_pair(elements, 'l'));

    //ICE/WATER
    elements.clear();
    elements.push_back(ICE);
    elements.push_back(WATER);
    ElementCode.insert(make_pair(elements, 's'));

    elements.clear();
    elements.push_back(WATER);
    elements.push_back(ICE);
    ElementCode.insert(make_pair(elements, 's'));

    //GROUND/WATER
    elements.clear();
    elements.push_back(GROUND);
    elements.push_back(WATER);
    ElementCode.insert(make_pair(elements, 'n'));

    elements.clear();
    elements.push_back(WATER);
    elements.push_back(GROUND);
    ElementCode.insert(make_pair(elements, 'n'));
}