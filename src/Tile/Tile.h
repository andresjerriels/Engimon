#ifndef _TILE_H_
#define _TILE_H_

#define NULL -1

#include "../Engimon/Engimon.h"
#include <string>
using namespace std;

class Tile {
    private:
        string type;
        bool isEngimonOccupied;
        Engimon* wild_engimon;
    
    public:
        // user-defined ctor for non engimon-occupied tiles
        Tile(string _type);

        // user-defined ctor for engimon-occupied tiles
        Tile(string _type, Engimon* _wild_engimon);

        // cctor
        Tile(const Tile&);

        // dtor
        ~Tile();

        // getter
        string getType();
        bool getIsEngimonOccupied();
        Engimon getWildEngimon();

        // setter
        void setType(string _type);
        void setIsEngimonOccupied(bool _isEngimonOccupied);
        void setWildEngimon(Engimon* _wild_engimon);
};

#endif