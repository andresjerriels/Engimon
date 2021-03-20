#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "Inventory.hpp"
#include "../Engimon/Engimon.h"
#include "../Skill/skill.hpp"
#include <vector>
using namespace std;

class Player
{
protected:
	Inventory<Engimon> inventoryEngimon;
	Inventory<SkillItem> inventorySkill;
	Engimon activeEngimon;
	const int MaxCapacity;

public:
	Player();
	
	//getter
	Engimon getActiveEngimon();

	//set activeEngimon
	void setActiveEngimon(Engimon); // asumsi Engimon valid

	bool isInventoryFull();
	void addToInvEngimon(Engimon engi);
	void addToInvSkill(SkillItem skill);

	~Player();
	
};


#endif