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
  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
  cout << "* Here are the available commands:      *\n";
  cout << "* w/a/s/d: Move                         *\n";
  cout << "* i: Interact with active engimon       *\n";
  cout << "* h: Change active engimon              *\n";
  cout << "* b: Battle with a nearby wild engimon  *\n";
  cout << "* e: Open engimon inventory             *\n";
  cout << "* t: Open skill inventory               *\n";
  cout << "* r: Breed two of your engimons         *\n";
  cout << "* x: Quit the game                      *\n";
  //lanjut
}
void Game::processCommand(char cmd){
  try{
    if(cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd') map->move(player, cmd);
    else if(cmd == 'i') player.getActiveEngimon()->interact();
    else if(cmd ==  'x'){
      cout << "* * * * * * * * * * * * * * * * * * * * *\n";
      cout << "*     Thank you for playing with us!    *\n";
      cout << "*              See you soon!            *\n";
    } 
    else if(cmd == 'b') battle();
    else if(cmd == 'l') printCommandList();
    else if(cmd == 'e'){
      player.getInventoryEngimon().openEngimonInventory();
    }
    else if(cmd == 't'){
      cout << "Your Skill(s):\n";
      player.getInventorySkill().printInventory();
    } else if (cmd == 'r'){
      BreedingConfirmation();
    } else if (cmd == 'h'){
      changeActiveEngimonConfirmation();
    }
    else throw "Command not available!\nEnter 'l' to see command list!";
  } catch (const char* err) {
    cerr << err << endl;
  } 
}

void Game::start() {
  cout << "* * * * * * * * * * * * * * * * * * * * *\n"
          "*                                       *\n"
          "*         !! ENGIMON FACTORY !!         *\n"
          "*                                       *\n"
          "* * * * * * * * * * * * * * * * * * * * *\n"
          "*               NEW GAME                *\n"
          "* * * * * * * * * * * * * * * * * * * * *\n";
  char cmd;
  cout << "* Welcome Player.                       *" << endl
       << "* Choose your starting Engimon          *\n"
       << "* 1. Charmamon (Fire)                   *" << endl
       << "* 2. Pikamon (Electric)                 *" << endl
       << "* * * * * * * * * * * * * * * * * * * * *"
       << endl;

  int engiChoice;
  do {   
    cout << "* Pilihan (1/2): ";
    cin >> engiChoice;
  } while (engiChoice < 1 || engiChoice > 2);

  string engiName;
  cout << "* * * * * * * * * * * * * * * * * * * * *\n"
       << "* Enter your engimon's name:            *\n"
       << "* ";
  cin >> engiName;
  cout << "* * * * * * * * * * * * * * * * * * * * *\n\n";
  Player newPlayer(engiName, engiChoice - 1);
  player = newPlayer;

  do {
    cout << "* * * * * * * * * * * * * * * * * * * * *\n"
            "*                                       *\n"
            "*         !! ENGIMON FACTORY !!         *\n"
            "*                                       *\n"
            "* * * * * * * * * * * * * * * * * * * * *\n"
            "*            Exploration Mode           *\n"
            "* * * * * * * * * * * * * * * * * * * * *\n";
    map->PrintMap();
    cout << "* * * * * * * * * * * * * * * * * * * * *\n";
    map->PrintNavigation();
    cout << "* * * * * * * * * * * * * * * * * * * * *\n";
    cout << "* Enter next command: ";
    cin >> cmd;

    try {
      processCommand(cmd);
    } catch (const char* e) {
      std::cerr << e << '\n';
    } catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
    } 
    
    map->setLevelCapslock(player.getActiveEngimon()->getLevel());
    cout << "* * * * * * * * * * * * * * * * * * * * *\n\n";
  } while (cmd != 'x');
}

void Game::battle(){
    cout << "* * * * * * * * * * * * * * * * * * * * *\n\n"
          "* * * * * * * * * * * * * * * * * * * * *\n"
          "*                                       *\n"
          "*         !! ENGIMON FACTORY !!         *\n"
          "*                                       *\n"
          "* * * * * * * * * * * * * * * * * * * * *\n"
          "*                BATTLE                 *\n"
          "* * * * * * * * * * * * * * * * * * * * *\n";
  Tile* tileWithEngimon = battleConfirmation();

  int playerPowerLevel, wildPowerLevel;
  // float playerAdvantage = 0, wildAdvantage = 0;

  Engimon playerEngimon = *player.getActiveEngimon();
  Engimon wildEngimon = tileWithEngimon->getWildEngimon();
  
  playerPowerLevel = playerEngimon.getPowerLevel(wildEngimon);
  wildPowerLevel = wildEngimon.getPowerLevel(playerEngimon);
  
  printFormatKiri(playerEngimon.getName());
  printFormatKiri("Power level: " + to_string(playerPowerLevel));
  cout << "\n*                  vs                   *\n";
  printFormatKanan(wildEngimon.getName()); cout << "\n";
  printFormatKanan("Power level: " + to_string(wildPowerLevel));
  cout << "* * * * * * * * * * * * * * * * * * * * *\n";

  // for (int i = 0; i < playerELements.size(); i++){
  //     for (int j = 0; j < wildELements.size(); j++){
  //         playerAdvantage = max(playerAdvantage, typeAdvTable[playerELements[i]][wildELements[j]]);
  //         wildAdvantage = max(wildAdvantage, typeAdvTable[wildELements[j]][playerELements[i]]);
  //     }
  // }
  // // power: level * element advantage + SUM(every skill’s base power * Mastery Level)
  // // belom consider skilll
  // playerPowerLevel = playerAdvantage * playerEngimon.getLevel();
  // wildPowerLevel = wildAdvantage * wildEngimon.getLevel();

  if(playerPowerLevel > wildPowerLevel){
    printFormatKiri(playerEngimon.getName() + " won!!");
    player.gainActiveEngimonExp(15*wildEngimon.getLevel());
    player.addToInvEngimon(wildEngimon);
    tileWithEngimon->deleteWildEngimon();
    map->decrementNWildEngimon();
  } else {
    printFormatKiri(wildEngimon.getName() + " won!!");
    // player.removeFromInvEngimon(*playerEngimon);
  }
}

void Game::printFormatKiri(string str){
cout << "* " << str << string((38-str.length()), ' ') << "*\n";
}

void Game::printFormatKanan(string str){
cout << "* " << string((37-str.length()), ' ') << str << " *\n";
}

Tile* Game::battleConfirmation(){
  int selection;
  
  vector<Tile*> tileswithEngimon = map->getTilesWithEngimonAroundPlayer();
  if(tileswithEngimon.size() > 1){
    printFormatKiri("Choose a wild engimon:"); cout << endl;
    for (int i = 0; i < tileswithEngimon.size(); i++){
      cout << i + 1 << ". " << tileswithEngimon[i]->getWildEngimon().getName() << endl;
    }
    cout << "* Insert number: ";
    cin >> selection;
  } else if (tileswithEngimon.size() == 1) {
    selection = 1;
  } else {
    throw "* There is no wild engimon around you!  *";
  }

  return tileswithEngimon[selection - 1];
}

void Game::BreedingConfirmation(){
  int eng1, eng2;
  printFormatKiri("Your Engimon(s):");
  player.getInventoryEngimon().printInventory();

  if(player.getInventoryEngimon().countItemInInventory() <= 1){
    printFormatKiri("You only have " + to_string(player.getInventoryEngimon().countItemInInventory()) + " engimon.");
    printFormatKiri("You need at least 2 of them to breed.");
  } else {
    bool valid = false;
    while(!valid){
      cout << "* Choose your first engimon: ";
      cin >> eng1;
      cout << "* Choose your second engimon: ";
      cin >> eng2;

      // try{
      //   player.getInventoryEngimon()[eng1].Breed((player.getInventoryEngimon()[eng2]));
      // }
      valid = true;
    }

  }
}

void Game::changeActiveEngimonConfirmation(){
  int i;
  printFormatKiri("Your Engimon(s):");
  player.getInventoryEngimon().printInventory();
  
  cout << "* Choose an engimon: ";
  cin >> i;
  if(i <= player.getInventoryEngimon().countItemInInventory()){
    player.setActiveEngimon(i-1);
  } else {
    throw "Index out of range";
  }
}