#include "Engimons.h"

Charmamon::Charmamon(std::string name) : Engimon(name, FIRE) {
  this->species = "Charmamon";
  this->slogan = "Ada engimon api";
  this->skills.push_back(Skill("Charmamon"));
}

Dittimon::Dittimon(std::string name) : Engimon(name, GROUND) {
  this->species = "Dittimon";
  this->slogan = "{Blm kepikiran slogan}";
  this->skills.push_back(Skill("Dittimon"));
}

Electromon::Electromon(std::string name) : Engimon(name, ELECTRIC) {
  this->species = "Electromon";
  this->slogan = "{Blm kepikiran slogan}";
  this->skills.push_back(Skill("Electromon"));
}

Mamomon::Mamomon(std::string name) : Engimon(name, ICE) {
  this->species = "Mamomon";
  this->slogan = "Ada engimon mamut";
  this->skills.push_back(Skill("Mamomon"));
}

Molemon::Molemon(std::string name) : Engimon(name, GROUND) {
  this->species = "Molemon";
  this->slogan = "Engimon ini suka menggali";
  this->skills.push_back(Skill("Molemon"));
}

Pikamon::Pikamon(std::string name) : Engimon(name, ELECTRIC) {
  this->species = "Pikamon";
  this->slogan = "Bzzt! Bzzt! Engimon tikus ini menyengat!";
  this->skills.push_back(Skill("Pikamon"));
}

Tentamon::Tentamon(std::string name) : Engimon(name, WATER) {
  this->species = "Tentamon";
  this->slogan = "Ada engimon ubur-ubur";
  this->skills.push_back(Skill("Tentamon"));
}

Torchimon::Torchimon(std::string name) : Engimon(name, FIRE) {
  this->species = "Torchimon";
  this->slogan = "{Blm kepikiran slogan}";
  this->skills.push_back(Skill("Torchimon"));
}

Tortomon::Tortomon(std::string name) : Engimon(name, WATER) {
  this->species = "Tortomon";
  this->slogan = "Ada engimon kura-kura";
  this->skills.push_back(Skill("Tortomon"));
}

Yetimon::Yetimon(std::string name) : Engimon(name, ICE) {
  this->species = "Yetimon";
  this->slogan = "{Blm kepikiran slogan}";
  this->skills.push_back(Skill("Yetimon"));
}