#ifndef MAP_H
#define MAP_H
// #include "../Tile/Tile.h"
#include "Tile.h"
#include "Position.h"
#include "../Player/Player.hpp"
#include "../Engimon/EngimonFactory.h"
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
};

#endif

// KALO SEMPET MAU NGEHIAS GINI WKWK
// * * * * * * * * * * * * * * * * * *
// *                                 *
// *      !! ENGIMON FACTORY !!      *
// *                                 *
// * * * * * * * * * * * * * * * * * *
// *        Exploration Mode         *
// * * * * * * * * * * * * * * * * * *
// * * * - - - - - - o o o o o o * * *
// * * * - - - - - - o o o o o o * * *
// * * * - - - - - - o o o o o o * * *
// * * * - - - - - - o o o o o o * * *
// * * * - - - - - - I o o o w o * * *
// * * * - - - - - - o o o o o o * * *
// * * * - - i - - - - - - - - - * * *
// * * * I - - - - - - - - w - - * * *
// * * * - - - - - - - - - - - - * * *
// * * * - - - - - P - - - - - - * * *
// * * * * * * * * * * * * * * * * * *
// * Enter command: l                *
// * * * * * * * * * * * * * * * * * *
// * Here are the available commands:*
// * w/a/s/d: Move;                  *
// * i: Interact with active engimon *
// * b: Battle with a nearby engimon *
// * x: Quit the game                *
// * * * * * * * * * * * * * * * * * *
// * Auch, you hit an invisible wall!*
// * * * * * * * * * * * * * * * * * *
// *  Auch, a wild engimon bit you!  *
// * * * * * * * * * * * * * * * * * *


// * * * * * * * * * * * * * * * * * * 
// *                                 *
// *      !! ENGIMON FACTORY !!      *
// *                                 *
// * * * * * * * * * * * * * * * * * * 
// *           Battle Mode           *
// * * * * * * * * * * * * * * * * * *
// * Miu                             *
// * Power level: 75                 *
// *                                 *
// *              vs.                *
// *                                 *
// *                  Wild Charmamon *
// *                Power level: 100 *
// * * * * * * * * * * * * * * * * * *
// *                                 *
// *     ! WILD CHARMAMON WON !      *
// *                                 *
// * * * * * * * * * * * * * * * * * *