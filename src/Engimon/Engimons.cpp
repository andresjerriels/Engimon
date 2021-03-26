#include "Engimons.hpp"

Charmamon::Charmamon(std::string name) : Engimon(name, FIRE) {
  this->species = "Charmamon";
  this->slogan = "Ada engimon api";
  this->skills.push_back(Skill("Charmamon"));
}

Pikamon::Pikamon(std::string name) : Engimon(name, ELECTRIC) {
  this->species = "Pikamon";
  this->slogan = "Bzzt! Bzzt! Engimon tikus ini menyengat!";
  this->skills.push_back(Skill("Pikamon"));
}

Electromon::Electromon(std::string name) : Engimon(name, ELECTRIC) {
  this->species = "Electromon";
  this->slogan = "Ada engimon listrik";
  this->skills.push_back(Skill("Electromon"));
}

Molemon::Molemon(std::string name) : Engimon(name, GROUND) {
  this->species = "Molemon";
  this->slogan = "Engimon ini suka menggali";
  this->skills.push_back(Skill("Molemon"));
}

Torchimon::Torchimon(std::string name) : Engimon(name, FIRE, ELECTRIC) {
  this->species = "Torchimon";
  this->slogan = "Engimon ini overloaded";
  this->skills.push_back(Skill("Torchimon"));
}

Dittimon::Dittimon(std::string name) : Engimon(name, WATER, GROUND) {
  this->species = "Dittimon";
  this->slogan = "Ada engimon lumpur";
  this->skills.push_back(Skill("Dittimon"));
}

Mamomon::Mamomon(std::string name) : Engimon(name, ICE) {
  this->species = "Mamomon";
  this->slogan = "Ada engimon mamut";
  this->skills.push_back(Skill("Mamomon"));
}

Tentamon::Tentamon(std::string name) : Engimon(name, WATER) {
  this->species = "Tentamon";
  this->slogan = "Ada engimon ubur-ubur";
  this->skills.push_back(Skill("Tentamon"));
}

Yetimon::Yetimon(std::string name) : Engimon(name, ICE) {
  this->species = "Yetimon";
  this->slogan = "Ada raksasa salju";
  this->skills.push_back(Skill("Yetimon"));
}

Tortomon::Tortomon(std::string name) : Engimon(name, WATER, ICE) {
  this->species = "Tortomon";
  this->slogan = "Ada engimon kura-kura";
  this->skills.push_back(Skill("Tortomon"));
}