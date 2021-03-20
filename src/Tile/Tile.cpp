#include "Tile.h"

Tile::Tile(string _type) {
  type = _type;
  isEngimonOccupied = false;
  wild_engimon = NULL;
}

Tile::Tile(string _type, Engimon* _wild_engimon) {
  type = _type;
  wild_engimon = _wild_engimon;
}

Tile::Tile(const Tile& other) {
  this->type = other.type;
  this->isEngimonOccupied = other.isEngimonOccupied;
  this->wild_engimon = other.wild_engimon;
}

Tile::~Tile() {
  delete wild_engimon;
}

string Tile::getType() {
  return type;
}

bool Tile::getIsEngimonOccupied() {
  return isEngimonOccupied;
}

Engimon Tile::getWildEngimon() {
  return *wild_engimon;
}

void Tile::setType(string _type) {
  type = _type;
}

void Tile::setIsEngimonOccupied(bool _isEngimonOccupied) {
  isEngimonOccupied = _isEngimonOccupied;
}

void Tile::setWildEngimon(Engimon* _wild_engimon) {
  wild_engimon = _wild_engimon;
}
