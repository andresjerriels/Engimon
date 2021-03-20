#include "Tortomon.h"

Tortomon::Tortomon(std::string name) : Engimon(name, WATER) {
  this->species = "Tortomon";
  this->slogan = "Ada engimon kura-kura";
  this->skills.push_back(Skill("Tortomon"));
}