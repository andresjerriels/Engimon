#include "Molemon.h"

Molemon::Molemon(std::string name) : Engimon(name, ground) {
    this->species = "Molemon";
    this->slogan = "Engimon ini suka menggali";
    this->skills.push_back(Skill("Molemon"));
}