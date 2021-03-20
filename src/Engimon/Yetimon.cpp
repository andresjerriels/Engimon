#include "Yetimon.h"

Yetimon::Yetimon(std::string name) : Engimon(name, ICE) {
  this->species = "Yetimon";
  this->slogan = "{Blm kepikiran slogan}";
  this->skills.push_back(Skill("Yetimon"));
}