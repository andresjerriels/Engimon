#ifndef GAME_H
#define GAME_H

#include "Map/map.h"
#include "Player/Player.hpp"

class Game {
 private:
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
  void learnSkillConfirmation();
  void changeActiveEngimonConfirmation();
  void printFormatKiri(string str);
  void printFormatKanan(string str);
};

#endif
