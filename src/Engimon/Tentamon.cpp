#include "Tentamon.h"

Tentamon::Tentamon(std::string name) : Engimon(name, water) {
    this->species = "Tentamon";
    this->slogan = "Ada engimon ubur-ubur";
    this->skills.push_back(Skill("Tentamon"));
}