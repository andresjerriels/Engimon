#include "Mamomon.h"

Mamomon::Mamomon(std::string name) : Engimon(name, ICE) {
  this->species = "Mamomon";
  this->slogan = "Ada engimon mamut";
  this->skills.push_back(Skill("Mamomon"));
}