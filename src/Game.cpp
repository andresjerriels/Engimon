#include <iostream>

#include "Game.h"

using namespace std;

Game::Game(string filename) {
  map = new Map(filename);
  state = EXPLORE;
}

Game::~Game(){
  delete map;
}

void Game::printCommandList(){
  cout << "Here are the available commands:\n";
  cout << "w/a/s/d: Move\n";
  cout << "i: Interact with active engimon\n";
  cout << "b: Battle with a nearby wild engimon\n";
  cout << "x: Quit the game\n";
  //lanjut
}
void Game::processCommand(char cmd){
  try{
    if(cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd') map->move(cmd);
    else if(cmd == 'i') player.getActiveEngimon().interact();
    else if(cmd ==  'x'){
      cout << "Thank you for playing with us!\n";
      cout << "       See you soon!\n"; 
    } 
    else if(cmd == 'b') cout << "battling\n";
    else if(cmd == 'l') printCommandList();
    else throw "Command not available!\nEnter 'l' to see command list!";
  } catch (const char* err) {
    cerr << err << endl;
  }

}

void Game::start() {
  char cmd;
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

  do {
    map->PrintMap();
    cin >> cmd;
    try {
      processCommand(cmd);
    } catch (const char* e) {
      std::cerr << e << '\n';
    }
  } while (cmd != 'x');
}


