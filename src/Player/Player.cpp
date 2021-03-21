#include "Player.hpp"
#include <iostream>
#include "../Engimon/Charmamon.h"
#include "../Engimon/Engimon.h"
#include "../Skill/skill.hpp"
#include "../Skill/skillitem.hpp"
#include "Inventory.hpp"
using namespace std;

Player::Player(std::string starter_name) : MaxCapacity(20) {
  Charmamon starterEngimon(starter_name);  // <- ini engimon starter
  this->activeEngimon = starterEngimon;
}

// getter
Inventory<Engimon> Player::getInventoryEngimon() const {
  return this->inventoryEngimon;
}

Inventory<SkillItem> Player::getInventorySkill() const {
  return this->inventorySkill;
}

Engimon Player::getActiveEngimon() const {
  return this->activeEngimon;
}

// set activeEngimon -> asumsi parameter valid
void Player::setActiveEngimon(Engimon _engimon) {
  this->activeEngimon = _engimon;
}

bool Player::isInventoryFull() {  // true kalo boleh ditambahin -> otomatis
                                  // maksimum MaxCapacity - 1
  int count = 0;
  count += inventoryEngimon.countItemInInventory();

  typename std::vector<SkillItem>::iterator it = inventorySkill.getContainer().begin();

  int i = 0;
  while (it != inventorySkill.getContainer().end()) {
    count += inventorySkill[i].getItemAmount();
    i++;
    it++;
  }

  if (count < MaxCapacity) {
    return true;
  } else {
    return false;
  }
}

void Player::addToInvEngimon(Engimon engi) {
  if (!isInventoryFull()) {
    this->inventoryEngimon.addToInventory(engi);
  } else {
    std::cout << "Inventory Full!" << std::endl;
  }
}

void Player::addToInvSkill(string _skill) {
  if (!isInventoryFull()) {  // jika tidak full
    typename std::vector<SkillItem>::iterator it = inventorySkill.getContainer().begin();
    int i = 0;
    bool found = false;

    while (!found && it != inventorySkill.getContainer().end()) {
      if (_skill == inventorySkill[i].skill->getName()) {
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