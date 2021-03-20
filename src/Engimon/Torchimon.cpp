#include "Torchimon.h"

Torchimon::Torchimon(std::string name) : Engimon(name, FIRE) {
  this->species = "Torchimon";
  this->slogan = "{Blm kepikiran slogan}";
  this->skills.push_back(Skill("Torchimon"));
}