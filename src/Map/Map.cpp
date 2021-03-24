#include "Map.h"
#include "../Engimon/EngimonFactory.h"

// map<vector<Element>, char> Map::ElementCode = {
//     {{WATER}, 'w'}, {{ICE}, 'i'},  {{FIRE}, 'f'}, {{GROUND}, 'g'},
//     {{ELECTRIC, NONE}, 'e'}, {{FIRE, ELECTRIC}, 'l'}, {{WATER, ICE}, 's'}, {{WATER, GROUND}, 'n'},
//     {{NONE, ELECTRIC}, 'e'}, {{ELECTRIC, FIRE}, 'l'}, {{ICE, WATER}, 's'}, {{GROUND, WATER}, 'n'}};

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
            if (isTilePlayerPosition(j, i)){
                printf("\033[1;33m");
                cout << "P";
            }
            else if(mapMatrix[i][j].isEngimonOccupied()){
                
                printf("\033[0;31m");
                if(mapMatrix[i][j].getWildEngimon().getLevel() > levelCapslock) cout << (char) (toupper(ElementCode[mapMatrix[i][j].getWildEngimon().getElements()]));
                else cout << ElementCode[mapMatrix[i][j].getWildEngimon().getElements()];
            }
            else if(mapMatrix[i][j].getType() == "Sea"){
                printf("\033[0;34m");
                cout << "o";
            }
            else{
                printf("\033[0;32m");
                cout << "-";
            }
            cout << " ";
        }
        cout << endl;
    }
    printf("\033[0m");
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
        if (!tile->isEngimonOccupied()){
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
        throw "Kamu menabrak tembok!\n";
    } 
    moveWildEngimon();
    GenerateEngimon();
    
    if (isPlayerTileContainEngimon()) {
        cout << "Do you want to do a battle?" << endl;
    }
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
                    if(i-1 >= 0 && i < length && !mapMatrix[i-1][j].isEngimonOccupied()){
                        mapMatrix[i-1][j].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].deleteWildEngimon();
                    }
                    break;
                case 1: // ke kiri
                    if(j < width && j-1 >= 0 && !mapMatrix[i][j-1].isEngimonOccupied()){
                        mapMatrix[i][j-1].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].deleteWildEngimon();
                    }
                    break;
                case 2: // ke bawah
                    if(i+1 < length && i >= 0 && !mapMatrix[i+1][j].isEngimonOccupied()){
                        mapMatrix[i+1][j].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].deleteWildEngimon();
                    }
                    break;
                case 3: // ke kanan
                    if(j >= 0 && j+1 < width && !mapMatrix[i][j+1].isEngimonOccupied()){
                        mapMatrix[i][j+1].setWildEngimon(mapMatrix[i][j].getWildEngimonPointer());
                        mapMatrix[i][j].deleteWildEngimon();
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