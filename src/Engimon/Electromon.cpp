#include "Electromon.h"

Electromon::Electromon(std::string name) : Engimon(name, electric) {
    this->species = "Electromon";
    this->slogan = "{Blm kepikiran slogan}";
    this->skills.push_back(Skill("Electromon"));
}