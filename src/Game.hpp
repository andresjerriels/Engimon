#ifndef GAME_HPP
#define GAME_HPP

#include "Map/map.hpp"
#include "Player/Player.hpp"

class Game {
 private:
  Map* map;
  Player* player;
  bool gameOver;

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
};

#endif
