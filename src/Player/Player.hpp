#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "Inventory.hpp"
#include "Engimon.h"
#include "skill.hpp"
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

	int countItem();
	void addToInvEngimon(Engimon engi);
	void addToInvSkill(SkillItem skill);

	~Player();
	
};


#endif