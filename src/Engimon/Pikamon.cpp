#include "Pikamon.h"

Pikamon::Pikamon(std::string name) : Engimon(name, ELECTRIC) {
  this->species = "Pikamon";
  this->slogan = "Bzzt! Bzzt! Engimon tikus ini menyengat!";
  this->skills.push_back(Skill("Pikamon"));
}