#ifndef GAME_H
#define GAME_H

#include "Map/map.h"
#include "Player/Player.hpp"

enum State { EXPLORE, BATTLE, INVENTORY };

class Game {
 private:
  State state;
  Map* map;
  Player* player;

 public:
  Game(string);
  ~Game();
  void getInput();
  void start();
  void printCommandList();
  void processCommand(char cmd);
  void battle();
  Tile* battleConfirmation();
  void BreedingConfirmation();
};

#endif
