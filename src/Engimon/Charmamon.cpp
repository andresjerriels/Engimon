#include "Charmamon.h"

Charmamon::Charmamon(std::string name) : Engimon(name, fire) {
    this->species = "Charmamon";
    this->slogan = "Ada engimon api";
    this->skills.push_back(Skill("Charmamon"));
}