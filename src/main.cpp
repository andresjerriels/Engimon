#include "Game.hpp"

#include <string>

int main(int argc, char const* argv[]) {
  string filename = "../file/map.txt";
  Game newGame(filename);
  newGame.start();
  return 0;
}
