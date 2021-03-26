#ifndef MAP_HPP
#define MAP_HPP

#include "Tile.hpp"
#include "Position.hpp"
#include "../Player/Player.hpp"
#include "../Engimon/EngimonFactory.hpp"
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
    Position activeEngimonPosition;
    map<vector<Element>, char> ElementCode;
    int levelCapslock;
    static int maxWildEngimon;
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
    void PrintNavigation();
    //method untuk generate wild engimon
    void GenerateEngimon(int minLvl, int maxLvl);
    //cek posisi player
    bool isTilePlayerPosition(int x, int y);
    //cek posisi active engimon
    bool isTileActiveEngimonPosition(int x, int y);
    //move player
    void move(const Player& player, char direction);
    bool isPlayerPositionOutOfRange();
    bool isPositionOutOfRange(int x, int y);
    bool isPlayerTileContainEngimon();
    void initializeElementCode();
    void moveWildEngimon();
    void setLevelCapslock(int _levelCapslock);
    vector <Tile*> getTilesWithEngimonAroundPlayer();
    bool isSpeciesAndGroundTypeValid(Engimon engimon, Tile tile);
    void decrementNWildEngimon();
};

#endif
