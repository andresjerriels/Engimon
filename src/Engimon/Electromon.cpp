#include "Electromon.h"

Electromon::Electromon(std::string name) : Engimon(name, ELECTRIC) {
  this->species = "Electromon";
  this->slogan = "{Blm kepikiran slogan}";
  this->skills.push_back(Skill("Electromon"));
}