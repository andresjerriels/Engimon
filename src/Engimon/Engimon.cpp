#include <iostream>
#include <vector>

#include "Engimon.h"

Engimon::Engimon(std::string _name, Element elmt1, Element elmt2){
    this->name = _name;
    this->elements.clear();
    this->elements.push_back(elmt1);
    if (elmt2 != none) this->elements.push_back(elmt2);
    this->level = 1;
    this->exp = 0;
    this->cum_exp = 0;
}

void Engimon::setName(std::string _name) {
    this->name = _name;
}

void Engimon::setSpecies(std::string _species) {
    this->species = _species;
}

void Engimon::setElements(Element elmt1, Element elmt2) {
    this->elements.clear();
    this->elements.push_back(elmt1);
    if (elmt2 != none) this->elements.push_back(elmt2);
}

void Engimon::setLevel(int lvl) {
    this->level = lvl;
}

void Engimon::setExp(int xp) {
    this->exp = xp;
}

void Engimon::setCumExp(int xp) {
    this->cum_exp = xp;
}

std::string Engimon::getName() {
    return this->name;
}
std::string Engimon::getSpecies() {
    return this->species;
}

int Engimon::getLevel() {
    return this->level;
}

int Engimon::getExp() {
    return this->exp;
}

int Engimon::getCumExp() {
    return this->cum_exp;
}

std::vector<Element> Engimon::getElements() {
    return this->elements;
}

void Engimon::gainExp(int xp) {
    this->cum_exp += xp;
    this->exp += xp;
    this->exp %= 100;
    this->level = (this->cum_exp/100)+1;
}

void Engimon::interact() {
    std::cout << "[" << this->name << "]: " << this->slogan << std::endl;
}

float Engimon::calcTypeAdvantage(Engimon& e) {
    std::vector<Element> otherElements = e.getElements();
    float maxAdv = -1;

    for (auto i = elements.begin(); i != elements.end(); i++) {
        for (auto j = otherElements.begin(); j != otherElements.end(); j++) {
            if (typeAdvTable[*i][*j] > maxAdv) {
                maxAdv = typeAdvTable[*i][*j];
            }
        }
    }
    
    return maxAdv;
}
