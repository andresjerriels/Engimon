#include <iostream>

#include "Game.h"

using namespace std;

Game::Game(string filename) {
  map = Map(filename);
  state = EXPLORE;
}

void Game::start() {
  cout << "Welcome Player, please choose your starting Engimon." << endl
       << "1. Charmamon (Fire)" << endl
       << "2. Pikamon (Electric)" << endl
       << endl;

  int engiChoice;
  do {
    cout << "Pilihan (1/2): ";
    cin >> engiChoice;
  } while (engiChoice < 1 || engiChoice > 2);

  string engiName;
  cout << "Enter your engimon's name: ";
  cin >> engiName;
  Player newPlayer(engiName, engiChoice);
  player = newPlayer;

  while (true) {
    try {
      char cmd;
      map.PrintMap();
      cin >> cmd;
      if (cmd == 'i') {
        player.getActiveEngimon().interact();
      } else if (cmd == 'x') {
        break;
      } else {
        map.move(cmd);
      }
    } catch (const char* e) {
      std::cerr << e << '\n';
    }
  }
}
