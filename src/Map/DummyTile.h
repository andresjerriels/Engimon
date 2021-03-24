//Class Tile tapi gapake engimon buat nyoba move
#ifndef _TILE_H_
#define _TILE_H_

// #define NULL -1

#include <string>
using namespace std;

class Tile {
 private:
  string type;
  bool isEngimonOccupied;

 public:
  // user-defined ctor for non engimon-occupied tiles
  Tile(string _type);

  // cctor
  Tile(const Tile&);

  // getter
  string getType();
  bool getIsEngimonOccupied();

  // setter
  void setType(string _type);
  void setIsEngimonOccupied(bool _isEngimonOccupied);
};
#endif