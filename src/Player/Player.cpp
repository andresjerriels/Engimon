#include "Player.hpp"
#include <iostream>
#include "../Engimon/Engimon.h"
#include "../Engimon/EngimonFactory.h"
#include "../Skill/skillitem.hpp"
#include "Inventory.hpp"
using namespace std;

Player::Player(std::string starter_name, int species) : MaxCapacity(30) {
  Engimon starterEngimon = EngimonFactory::createEngimon(starter_name, species);  // <- ini engimon starter, bisa dipilih atau engga(?)
  inventoryEngimon.addToInventory(starterEngimon);
  this->activeEngimon = &inventoryEngimon[0];
}

// getter
Inventory<Engimon> Player::getInventoryEngimon() const {
  return this->inventoryEngimon;
}

Inventory<SkillItem> Player::getInventorySkill() const {
  return this->inventorySkill;
}

Engimon* Player::getActiveEngimon() const {
  return this->activeEngimon;
}

int Player::getMaxCapacity() const{
  return this->MaxCapacity;
}

// set activeEngimon -> asumsi parameter valid
void Player::setActiveEngimon(int i){
  this->activeEngimon = &inventoryEngimon[i];
}

bool Player::isInventoryFull() {  // true kalo udah gabisa ditambahin -> otomatis
                                  // maksimum MaxCapacity - 1
  int count = 0;
  count += inventoryEngimon.countItemInInventory();
  cout << "x";
  typename std::vector<SkillItem>::iterator it = inventorySkill.getContainer().begin();
cout << "y";
  int i = 0;

  for (i = 0; i < inventorySkill.getContainer().size(); i++){
    count += inventorySkill[i].getItemAmount();
  }
  // while (it != inventorySkill.getContainer().end()) {
  //   count += inventorySkill[i].getItemAmount();
  //   i++;
  //   it++;
  // }
  cout << "d";

  if (count >= MaxCapacity) {
    return true;
  } else {
    return false;
  }
}

void Player::addToInvEngimon(Engimon engi) {
  cout << "c";
  if (!isInventoryFull()) {
    cout <<"c";
    int index = activeEngimon - &inventoryEngimon[0];
    cout <<"d";
    this->inventoryEngimon.addToInventory(Engimon(engi));
    cout <<"e";
    activeEngimon = &inventoryEngimon[index];
  } else {
    Util::printFormatKiri("Inventory Full!");
  }
}

void Player::addToInvSkill(string _skill) {
  if (!isInventoryFull()) {  // jika tidak full
    typename std::vector<SkillItem>::iterator it = inventorySkill.getContainer().begin();
    int i = 0;
    bool found = false;

    while (!found && it != inventorySkill.getContainer().end()) {
      if (_skill == inventorySkill[i].getSkill().getName()) {
        found = true;
      }

      else {
        it++;
        i++;
      }
    }

    if (found) {  // jika ketemu amount item ditambah
      inventorySkill[i].incrementItemAmount();
    } else {  // lainnya
      SkillItem temp_skillitem(
          1, _skill);  // nanti di SkillItem buat constructor user define
      inventorySkill.addToInventory(temp_skillitem);
    }
  }
}

void Player::gainActiveEngimonExp(int exp){
  activeEngimon->gainExp(exp);
}

int Player::getActiveEngiIndex() {
  return (activeEngimon - &inventoryEngimon[0]);
}

void Player::removeEngimonByIndex(int idx) {
  inventoryEngimon.removeByindex(idx);
}

void Player::removeSkillByIndex(int idx) {
  inventorySkill.removeByindex(idx);
}

void Player::openEngimonInventory(){
  string cmd;
  do{
    cout << "*****************************************************\n";
    Util::printFormatKiri("Your Engimon(s):");
    inventoryEngimon.printInventory();
    Util::printFormatKiri("- To see details, select a number");
    Util::printFormatKiri("- To close inventory, select 'c'");
    Util::printFormatKiri("What do you want to do?");
    cout << "* ";
    cin >> cmd;

    if(cmd != "c"){
      int i = stoi(cmd);
      if(1 <= i && i <= inventoryEngimon.getContainer().size()) inventoryEngimon[i-1].printInfo();
      else Util::printFormatKiri("Number invalid");
    }
  } while (cmd != "c");
}

void Player::openSkillInventory(){
  string cmd;
  do{
    Util::printFormatKiri("Your Skill Item(s):");
    inventorySkill.printInventory();
    Util::printFormatKiri("- To see details, select a number");
    Util::printFormatKiri("- To close inventory, select 'c'");
    Util::printFormatKiri("What do you want to do?");
    cout << "* ";
    cin >> cmd;

    if(cmd != "c"){
      int i = stoi(cmd);
      if(1 <= i && i <= inventorySkill.getContainer().size()) inventorySkill[i-1].getSkill().printSkillInfo();
      else Util::printFormatKiri("Number invalid");
    }
  } while (cmd != "c");
}

Engimon& Player::getEngiRefFromIndex(int i) {
  if ( 0 <= i && i < inventoryEngimon.countItemInInventory()) {
    return inventoryEngimon[i];
  } else {
    throw "Index out of range";
  }
}

SkillItem& Player::getSkillRefFromIndex(int i) {
  if ( 0 <= i && i < inventorySkill.countItemInInventory()) {
    return inventorySkill[i];
  } else {
    throw "Index out of range";
  }
}