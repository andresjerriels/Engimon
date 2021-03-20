#include <iostream>
#include "Player.hpp"
#include "Inventory.hpp"
#include "../Engimon/Engimon.h"
#include "../Engimon/Charmamon.h"
using namespace std;

Player::Player(std::string starter_name) : MaxCapacity(20) {
	Charmamon starterEngimon(starter_name); // <- ini engimon starter
	this->activeEngimon = starterEngimon;
}

//getter
Engimon Player::getActiveEngimon() {
	return this->activeEngimon;
}

//set activeEngimon -> asumsi parameter valid
void Player::setActiveEngimon(Engimon _engimon) {
	this->activeEngimon = _engimon;
}

bool Player::isInventoryFull() { //true kalo boleh ditambahin -> otomatis maksimum MaxCapacity - 1
	int count = 0;
	count += inventoryEngimon.countItemInventory();

	typename std::vector<SkillItem>::iterator it;
	it = inventorySkill.begin();
	int i = 0;
	while (it != inventorySkill.end()) {
		count += inventorySkill[i].getAmount();
		i++;
		it++;
	}

	if (count < MaxCapacity) {
		return true;
	} else {return false;}
}

void Player::addToInvEngimon(Engimon engi) {
	if (!isInventoryFull()) {
		this->inventoryEngimon.addToInventory(engi);
	}
	else {
		std::cout << "Inventory Full!" << std::endl;
	}
}

void Player::addToInvSkill(Skill _skill) {
	if (!isInventoryFull()) { //jika tidak full
		typename std::vector<SkillItem>::iterator it;
		it = inventorySkill.begin();
		int i = 0;
		bool found = false;

		while (!found && it != inventorySkill.end()) {
			if (_skill == inventorySkill[i]) {
				found = true;
			}

			else {
				it++;
				i++;
			}
		}
			
		if (found) { //jika ketemu amount item ditambah
			inventorySkill[i].setAmount(inventorySkill[i].getAmount() + 1);
		} else { //lainnya
			SkillItem temp_skillitem(_skill, 1); //nanti di SkillItem buat constructor user define
			inventorySkill.addToInventory(temp_skillitem);
		}

	}
}