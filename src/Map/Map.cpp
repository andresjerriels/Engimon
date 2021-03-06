#include "Map.hpp"
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
    int x = rand() % 11 + 1;
    int y = rand() % 10;
    
    playerPosition.setX(x);
    playerPosition.setY(y);
    
    activeEngimonPosition.setX(x-1);
    activeEngimonPosition.setY(y);

    nWildEngimon = 0;
    while(nWildEngimon < 5) GenerateEngimon(1, 3);
    
    levelCapslock = 1;
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

void Map::PrintNavigation(){
    cout << "* Navigation:                                       *\n"
         << "* W/w: Water engimon                                *\n"
         << "* I/i: Ice engimon                                  *\n"
         << "* F/f: Fire engimon                                 *\n"
         << "* G/g: Ground engimon                               *\n"
         << "* E/e: Electric engimon                             *\n"
         << "* L/l: Fire/Electric engimon                        *\n"
         << "* S/s: Water/Ice engimon                            *\n"
         << "* N/n: Water/Ground engimon                         *\n"
         << "*                                                   *\n"
         << "* P: Player    X: Active Engimon                    *\n";

}
void Map::PrintMap(){
    for (int i = -1; i <= length; i++){
        for (int j = -7; j <= width + 7; j++){
            // if (ada engimon) print blablabla
            if(j == -7 || j == width + 7) cout << "*";
            else if(isPositionOutOfRange(j,i)){
                cout << " ";
            }
            else if (isTilePlayerPosition(j, i)){
                cout << "P";
            }
            else if (isTileActiveEngimonPosition(j, i)){
                cout << "X";
            }
            else if(mapMatrix[i][j].isEngimonOccupied()){
                if(mapMatrix[i][j].getWildEngimon().getLevel() > levelCapslock) cout << (char) (toupper(ElementCode[mapMatrix[i][j].getWildEngimon().getElements()]));
                else cout << ElementCode[mapMatrix[i][j].getWildEngimon().getElements()];
            }
            else if(mapMatrix[i][j].getType() == "Sea"){
                cout << "o";
            }
            else{
                cout << "-";
            }
            cout << " ";
        }
        cout << endl;
    }
}

void Map::GenerateEngimon(int minLvl, int maxLvl){
    if(nWildEngimon < maxWildEngimon && (rand() % 5)){
        srand((unsigned) time(0));
        int species;
        // random x
        int x = rand() % 12;

        // random y
        int y = rand() % 10;

        // random level
        int level = rand() % (maxLvl - minLvl + 1) + minLvl; // ini belom fix
        Tile* tile = &mapMatrix[y][x];
        if (!tile->isEngimonOccupied() && !isTilePlayerPosition(x,y)){
            if(tile->getType() == "Grassland") species = rand() % 6; //species grassland: 0 - 5
            else species = rand() % 5 + 5; // species sea: 5 - 9

            Engimon *wild = EngimonFactory::createEngimon(species);
            wild->setLevel(level);
            wild->setExp(rand() % 99);
            tile->setWildEngimon(wild);
            nWildEngimon++;
        }
    }
}

bool Map::isTilePlayerPosition(int x, int y){
    return playerPosition.getX() == x && playerPosition.getY() == y;
}

bool Map::isTileActiveEngimonPosition(int x, int y) {
    return activeEngimonPosition.getX() == x && activeEngimonPosition.getY() == y;
}

void Map::move(const Player& player, char direction){
    playerPosition.setXY(direction);
    if(isPlayerPositionOutOfRange()) {
        playerPosition.resetXY(direction);
        throw "* * * * * * * * * * * * * * * * * * * * *\n* Ouch, you hit an invisible wall!      *";
    } else if(isPlayerTileContainEngimon()) {
        playerPosition.resetXY(direction);
        throw "* * * * * * * * * * * * * * * * * * * * *\n* Ouch, a wild engimon bit you!         *";
    }
    activeEngimonPosition = playerPosition;
    activeEngimonPosition.resetXY(direction);

    int actEngiLvl = player.getActiveEngimon()->getLevel();

    moveWildEngimon();
    GenerateEngimon(max(1, actEngiLvl - 2), actEngiLvl + 2);
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

bool Map::isSpeciesAndGroundTypeValid(Engimon engimon, Tile tile){
    return (tile.getType() == "Sea" && 
    EngimonFactory::getSpeciesNumber(engimon.getSpecies()) >= 5 
    && EngimonFactory::getSpeciesNumber(engimon.getSpecies()) <= 9) || (tile.getType() == "Grassland" && 
    EngimonFactory::getSpeciesNumber(engimon.getSpecies()) <= 5);
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
                    if(i-1 >= 0 && i < length && !mapMatrix[i-1][j].isEngimonOccupied() && !isTilePlayerPosition(j,i-1) 
                       && !isTileActiveEngimonPosition(j,i-1)
                       && isSpeciesAndGroundTypeValid(mapMatrix[i][j].getWildEngimon(), mapMatrix[i-1][j])){
                        mapMatrix[i-1][j].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].moveWildEngimon();
                    }
                    break;
                case 1: // ke kiri
                    if(j < width && j-1 >= 0 && !mapMatrix[i][j-1].isEngimonOccupied() && !isTilePlayerPosition(j-1,i) && !isTileActiveEngimonPosition(j-1,i) && isSpeciesAndGroundTypeValid(mapMatrix[i][j].getWildEngimon(), mapMatrix[i][j-1])){
                        mapMatrix[i][j-1].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].moveWildEngimon();
                    }
                    break;
                case 2: // ke bawah
                    if(i+1 < length && i >= 0 && !mapMatrix[i+1][j].isEngimonOccupied() && !isTilePlayerPosition(j,i+1) && !isTileActiveEngimonPosition(j,i+1) && isSpeciesAndGroundTypeValid(mapMatrix[i][j].getWildEngimon(), mapMatrix[i+1][j])){
                        mapMatrix[i+1][j].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].moveWildEngimon();
                    }
                    break;
                case 3: // ke kanan
                    if(j >= 0 && j+1 < width && !mapMatrix[i][j+1].isEngimonOccupied() && !isTilePlayerPosition(j+1,i) && !isTileActiveEngimonPosition(j+1,i) && isSpeciesAndGroundTypeValid(mapMatrix[i][j].getWildEngimon(), mapMatrix[i][j+1])){
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

void Map::setLevelCapslock(int _levelCapslock){
    levelCapslock = _levelCapslock;
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

void Map::decrementNWildEngimon(){
    nWildEngimon--;
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