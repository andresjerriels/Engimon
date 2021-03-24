#ifndef MAP_H
#define MAP_H
// #include "../Tile/Tile.h"
#include "../Tile/Tile.h"
#include "Position.h"
#include "../Player/Player.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;

class Map
{
private:
    vector<vector<Tile>> mapMatrix;
    int width;
    int length;
    int nWildEngimon;
    Position playerPosition;
    map<vector<Element>, char> ElementCode;
    int levelCapslock;
    static int maxWildEngimon;
public:
    //ctor
    Map(string);
    //dtor
    ~Map();
    //cctor
    Map(const Map&);
    //assignment operator
    Map& operator= (const Map&);
    //method untuk mencetak peta
    void PrintMap();
    //method untuk generate wild engimon
    void GenerateEngimon();
    //cek posisi player
    bool isTilePlayerPosition(int x, int y);
    //move player
    void move(string direction);
    bool isPlayerPositionOutOfRange();
    bool isPlayerTileContainEngimon();
    void initializeElementCode();
    void moveWildEngimon();
    void changeLevelCapslock();
};

#endif