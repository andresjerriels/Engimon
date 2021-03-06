#ifndef _TILE_HPP_
#define _TILE_HPP_

#include <string>
#include "../Engimon/Engimon.hpp"
#include "../Engimon/Engimons.hpp"
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
  void moveWildEngimon();
};

#endif