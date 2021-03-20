#include "Torchimon.h"

Torchimon::Torchimon(std::string name) : Engimon(name, fire) {
    this->species = "Torchimon";
    this->slogan = "{Blm kepikiran slogan}";
    this->skills.push_back(Skill("Torchimon"));
}