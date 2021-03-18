#include <vector>

#include "Engimon.h"

void Engimon::setElements(Element elmt1, Element elmt2) {
    this->elements.clear();
    this->elements.push_back(elmt1);
    this->elements.push_back(elmt2);
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

int Engimon::getLevel() {
    return this->level;
}

int Engimon::getExp() {
    return this->exp;
}

int Engimon::getCumExp() {
    return this->cum_exp;
}

void Engimon::gainExp(int xp) {
    this->cum_exp += xp;
    this->exp += xp;
    this->exp %= 100;
    this->level = (this->cum_exp/100)+1;
}

std::vector<Element> Engimon::getElements() {
    return this->elements;
}