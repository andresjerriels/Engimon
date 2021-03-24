#ifndef MAP_H
#define MAP_H
// #include "../Tile/Tile.h"
#include "DummyTile.h"
#include "Position.h"
#include <bits/stdc++.h> //ini ntar diubah mager soalnya tadi
using namespace std;

class Map
{
private:
    vector<vector<Tile>> mapMatrix;
    int width;
    int length;
    int nWildEngimon;
    Position playerPosition;

public:
    //ctor
    Map();
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
};

#endif