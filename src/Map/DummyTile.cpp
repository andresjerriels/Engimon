#include "DummyTile.h"

Tile::Tile(string _type) {
  type = _type;
  isEngimonOccupied = false;
}

Tile::Tile(const Tile& other) {
  this->type = other.type;
  this->isEngimonOccupied = other.isEngimonOccupied;
}


string Tile::getType() {
  return type;
}

bool Tile::getIsEngimonOccupied() {
  return isEngimonOccupied;
}

void Tile::setType(string _type) {
  type = _type;
}

void Tile::setIsEngimonOccupied(bool _isEngimonOccupied) {
  isEngimonOccupied = _isEngimonOccupied;
}