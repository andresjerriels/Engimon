#include "Dittimon.h"

Dittimon::Dittimon(std::string name) : Engimon(name, ground) {
    this->species = "Dittimon";
    this->slogan = "{Blm kepikiran slogan}";
    this->skills.push_back(Skill("Dittimon"));
}