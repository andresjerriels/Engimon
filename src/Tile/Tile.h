#ifndef _TILE_H_
#define _TILE_H_

// #define NULL -1

#include <string>
#include "../Engimon/Engimon.h"
#include "../Engimon/Engimons.h"
using namespace std;

class Tile {
 private:
  string type;
  Engimon* wild_engimon;

 public:
  // user-defined ctor for non engimon-occupied tiles
  Tile(string _type);

  // user-defined ctor for engimon-occupied tiles
  Tile(string _type, Engimon* _wild_engimon);

  // cctor
  Tile(const Tile&);

  //assignment operator
  Tile operator=(const Tile&);
  // dtor
  ~Tile();

  // getter
  string getType();
  bool isEngimonOccupied();
  Engimon getWildEngimon();
  Engimon* getWildEngimonPointer();
  // setter
  void setType(string _type);
  void setWildEngimon(Engimon* _wild_engimon);
  void deleteWildEngimon();
};

#endif