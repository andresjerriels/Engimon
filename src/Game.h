#ifndef GAME_H
#define GAME_H

#include "Map/map.h"
#include "Player/Player.hpp"

enum State { EXPLORE, BATTLE, INVENTORY };

class Game {
 private:
  State state;
  Map map;
  Player player;

 public:
  Game(string);
  void getInput();
  void start();
};

#endif
