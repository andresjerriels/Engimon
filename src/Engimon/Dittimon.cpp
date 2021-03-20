#include "Dittimon.h"

Dittimon::Dittimon(std::string name) : Engimon(name, GROUND) {
  this->species = "Dittimon";
  this->slogan = "{Blm kepikiran slogan}";
  this->skills.push_back(Skill("Dittimon"));
}