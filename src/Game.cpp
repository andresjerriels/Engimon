#include <iostream>

#include "Game.h"

using namespace std;

Game::Game(string filename) {
  map = new Map(filename);
  gameOver = false;
}

Game::~Game(){
  delete map;
  delete player;
}

void Game::printCommandList(){
  cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
  cout << "* Here are the available commands:                  *\n";
  cout << "* w/a/s/d: Move                                     *\n";
  cout << "* i: Interact with active engimon                   *\n";
  cout << "* h: Change active engimon                          *\n";
  cout << "* b: Battle with a nearby wild engimon              *\n";
  cout << "* e: Open engimon inventory                         *\n";
  cout << "* t: Open skill inventory                           *\n";
  cout << "* r: Breed two of your engimons                     *\n";
  cout << "* u: Learn a skill                                  *\n";
  cout << "* x: Quit the game                                  *\n";
  //lanjut
}
void Game::processCommand(char cmd){
  try{
    if(cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd') map->move(*player, cmd);
    else if(cmd == 'i') player->getActiveEngimon()->interact();
    else if(cmd ==  'x'){
      cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
      cout << "*           Thank you for playing with us!          *\n";
      cout << "*                    See you soon!                  *\n";
    } 
    else if(cmd == 'b') battle();
    else if(cmd == 'l') printCommandList();
    else if(cmd == 'e'){
      player->openEngimonInventory();
    } else if(cmd == 't'){
      player->openSkillInventory();
    } else if (cmd == 'r'){
      BreedingConfirmation();
    } else if (cmd == 'h'){
      changeActiveEngimonConfirmation();
    } else if (cmd == 'u'){
      learnSkillConfirmation();
    }
    else throw "* Command not available!                            *\n* Enter 'l' to see command list!                    *";
  } catch (const char* err) {
    cerr << err << endl;
  } 
}

void Game::start() {
  cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
          "*                                                   *\n"
          "*               !! ENGIMON FACTORY !!               *\n"
          "*                                                   *\n"
          "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
          "*                     NEW GAME                      *\n"
          "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
  char cmd;
  cout << "* Welcome Player.                                   *" << endl
       << "* Choose your starting Engimon                      *\n"
       << "* 1. Charmamon (Fire)                               *" << endl
       << "* 2. Pikamon (Electric)                             *" << endl
       << "* * * * * * * * * * * * * * * * * * * * * * * * * * *"
       << endl;

  int engiChoice;
  do {   
    cout << "* Pilihan (1/2): ";
    cin >> engiChoice;
  } while (engiChoice < 1 || engiChoice > 2);

  string engiName;
  cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
       << "* Enter your engimon's name:                        *\n"
       << "* ";
  cin.ignore();
  getline(cin, engiName);

  player = new Player(engiName, engiChoice - 1);

  do {
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
            "*                                                   *\n"
            "*               !! ENGIMON FACTORY !!               *\n"
            "*                                                   *\n"
            "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
            "*                  Exploration Mode                 *\n"
            "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    map->PrintMap();
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    map->PrintNavigation();
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "* Enter next command: ";
    cin >> cmd;

    try {
      processCommand(cmd);
    } catch (const char* e) {
      std::cerr << e << '\n';
    } catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
    } 
    map->setLevelCapslock(player->getActiveEngimon()->getLevel());
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
  } while (cmd != 'x' && gameOver == false);
}

void Game::battle(){
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n"
          "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
          "*                                                   *\n"
          "*               !! ENGIMON FACTORY !!               *\n"
          "*                                                   *\n"
          "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
          "*                      BATTLE                       *\n"
          "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
  Tile* tileWithEngimon = battleConfirmation();

  int playerPowerLevel, wildPowerLevel;

  Engimon playerEngimon = *(player->getActiveEngimon());
  Engimon wildEngimon = tileWithEngimon->getWildEngimon();
  

  playerPowerLevel = playerEngimon.getPowerLevel(wildEngimon);
  wildPowerLevel = wildEngimon.getPowerLevel(playerEngimon);
  
  printFormatKiri(playerEngimon.getName());
  printFormatKiri("Power level: " + to_string(playerPowerLevel));
  cout << "\n*                        vs                         *\n";
  printFormatKanan(wildEngimon.getName());
  printFormatKanan("Power level: " + to_string(wildPowerLevel));
  cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";

  if(playerPowerLevel > wildPowerLevel){
    string engiName;
    vector<Element> wildElement = wildEngimon.getElements();
    printFormatKiri(playerEngimon.getName() + " won!!");
    player->gainActiveEngimonExp(15*wildEngimon.getLevel());
    printFormatKiri("You captured a " + wildEngimon.getSpecies());
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
         << "* Enter your new engimon's name:                    *\n"
         << "* ";
    cin.ignore();
    getline(cin, engiName);
    wildEngimon.setName(engiName);

    string newSkillName = LearnableSkill[wildElement[rand() % wildElement.size()]][rand() % 7];
    printFormatKiri("You get a skill item: " + newSkillName);

    player->addToInvSkill(newSkillName);
    player->addToInvEngimon(wildEngimon);
    tileWithEngimon->deleteWildEngimon();
    map->decrementNWildEngimon();

    if (playerEngimon.getCumExp() > 8000) {
      printFormatKiri("Engimon's cumulative EXP has reached its limit");
      player->removeEngimonByIndex(player->getActiveEngiIndex());
      if (player->getInventoryEngimon().countItemInInventory() > 0) {
        printFormatKiri("Please select another active engimon");

        int i;
        printFormatKiri("Your Engimon(s):");
        player->getInventoryEngimon().printInventory();
  
        cout << "* Choose an engimon: " << endl;
        do
        {
          cout << "* Choice: ";
          cin >> i;
        } while (i < 1 || i > player->getInventoryEngimon().countItemInInventory());

        player->setActiveEngimon(i-1);
      } else {
        printFormatKiri("You don't have any engimons left");
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
        cout << "*                     GAME OVER                     *\n";
        cout << "*           Thank you for playing with us!          *\n";
        cout << "*                    See you soon!                  *\n";
        gameOver = true;
      }
    }
  } else {
    printFormatKiri(wildEngimon.getName() + " won!!");
    printFormatKiri("Your engimon was defeated in battle");
    player->removeEngimonByIndex(player->getActiveEngiIndex());
    if (player->getInventoryEngimon().countItemInInventory() > 0) {
      printFormatKiri("Please select another active engimon");

      int i;
      printFormatKiri("Your Engimon(s):");
      player->getInventoryEngimon().printInventory();

      cout << "* Choose an engimon: " << endl;
      do
      {
        cout << "* Choice: ";
        cin >> i;
      } while (i < 1 || i > player->getInventoryEngimon().countItemInInventory());

      player->setActiveEngimon(i-1);
    } else {
      printFormatKiri("You don't have any engimons left");
      cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
      cout << "*                     GAME OVER                     *\n";
      cout << "*           Thank you for playing with us!          *\n";
      cout << "*                    See you soon!                  *\n";
      gameOver = true;
    }
  }
}

void Game::printFormatKiri(string str){
cout << "* " << str << string((50-str.length()), ' ') << "*\n";
}

void Game::printFormatKanan(string str){
cout << "* " << string((49-str.length()), ' ') << str << " *\n";
}

Tile* Game::battleConfirmation(){
  int selection;
  char continueSelection;
  
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
    throw "*       There is no wild engimon around you!        *";
  }

  Util::printFormatKiri("Wild engimon info:");
  tileswithEngimon[selection-1]->getWildEngimon().printInfo();
  cout << "* Continue battle (y/n)? ";
  cin >> continueSelection;
  

  if (toupper(continueSelection) != 'Y') {
    throw "* Cancelling battle                                 *";
  }
  
  return tileswithEngimon[selection - 1];
}

void Game::BreedingConfirmation(){
  if (!player->isInventoryFull()) {
    int eng1, eng2;
    printFormatKiri("Your Engimon(s):");
    player->getInventoryEngimon().printInventory();

    if(player->getInventoryEngimon().countItemInInventory() == 1){
      cout << "\n";
      printFormatKiri("You only have 1 engimon.");
      printFormatKiri("You need at least 2 of them to breed.");
    } else {
      cout << "* Choose your first engimon: ";
      cin >> eng1;
      cout << "* Choose your second engimon: ";
      cin >> eng2;
      
      Engimon child = player->getEngiRefFromIndex(eng1-1).Breed(player->getEngiRefFromIndex(eng2-1));
      player->addToInvEngimon(child);
    }
  } else {
    throw "Cannot breed with full inventory";
  }
}

void Game::learnSkillConfirmation(){
  if (player->getInventorySkill().countItemInInventory() > 0) {
    int engiChoice, skillChoice;
    printFormatKiri("Your Engimon(s):");
    player->getInventoryEngimon().printInventory();

    cout << "* Choose your engimon: ";
    cin >> engiChoice;

    Engimon &engi = player->getEngiRefFromIndex(engiChoice-1);

    printFormatKiri("Your Skill Item(s):");
    player->getInventorySkill().printInventory();
    cout << "* Choose a skill item: ";
    cin >> skillChoice;

    SkillItem &skill = player->getSkillRefFromIndex(skillChoice-1);
      
    if (skill.learn(engi) == 0) {
      player->removeSkillByIndex(skillChoice-1);
    }
  } else {
    throw "* You don't have any skill items                    *";
  }
}

void Game::changeActiveEngimonConfirmation(){
  printFormatKiri("Current active engimon:");
  cout << "* " << *(player->getActiveEngimon()) << endl;
  int i;
  printFormatKiri("Your Engimon(s):");
  player->getInventoryEngimon().printInventory();
  
  cout << "* Choose an engimon: ";
  cin >> i;
  if(i <= player->getInventoryEngimon().countItemInInventory()){
    player->setActiveEngimon(i-1);
  } else {
    throw "Index out of range";
  }
}