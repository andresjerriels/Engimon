#include "Tile.h"

Tile::Tile(string _type) {
  type = _type;
  wild_engimon = NULL;
}

Tile::Tile(string _type, Engimon* _wild_engimon) {
  type = _type;
  wild_engimon = _wild_engimon;
}

Tile::Tile(const Tile& other) {
  type = other.type;
  wild_engimon = other.wild_engimon;
}

Tile::~Tile() {
  delete wild_engimon;
}

string Tile::getType() {
  return type;
}

Engimon Tile::getWildEngimon() {
  return *wild_engimon;
}

Engimon* Tile::getWildEngimonPointer(){
  return wild_engimon;
}

void Tile::setType(string _type) {
  type = _type;
}

bool Tile::isEngimonOccupied(){
  return wild_engimon!=NULL;
}

void Tile::setWildEngimon(Engimon* _wild_engimon) {
  wild_engimon = _wild_engimon;
}

void Tile::deleteWildEngimon(){
  wild_engimon = NULL;
}
