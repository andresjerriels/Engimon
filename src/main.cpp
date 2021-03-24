#include "Game.h"

#include <string>

int main(int argc, char const* argv[]) {
  string filename = "../file/map.txt";
  Game newGame(filename);
  cout << "ng";
  newGame.start();
  return 0;
}
