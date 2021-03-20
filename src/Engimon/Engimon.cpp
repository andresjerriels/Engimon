#include <iostream>
#include <vector>

#include "Engimon.h"
#include "Engimons.h"

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

Engimon Engimon::GenerateEngimon(std::string _name, std::string _species) {
    if (_species.compare("Charmamon") == 0) {
        Engimon e1 = Charmamon(_name);
        return e1;
    } else if (_species.compare("Torchimon") == 0) {
        Engimon e1 = Torchimon(_name);
        return e1;
    } else if (_species.compare("Tentamon") == 0) {
        Engimon e1 = Tentamon(_name);
        return e1;
    } else if (_species.compare("Tortomon") == 0) {
        Engimon e1 = Tortomon(_name);
        return e1;
    } else if (_species.compare("Pikamon") == 0) {
        Engimon e1 = Pikamon(_name);
        return e1;
    } else if (_species.compare("Electromon") == 0) {
        Engimon e1 = Electromon(_name);
        return e1;
    } else if (_species.compare("Dittimon") == 0) {
        Engimon e1 = Dittimon(_name);
        return e1;
    } else if (_species.compare("Molemon") == 0) {
        Engimon e1 = Molemon(_name);
        return e1;
    } else if (_species.compare("Yetimon") == 0) {
        Engimon e1 = Yetimon(_name);
        return e1;
    } else if (_species.compare("Mamomon") == 0) {
        Engimon e1 = Mamomon(_name);
        return e1;
    } else {
        std::string err_msg = "Invalid species";
        throw err_msg;
    }
}

Engimon Engimon::Breed(Engimon& e2) {
    // baru working untuk masing parent engimon hanya satu element
    // program untuk dual element parent bisa jadi redundan terhadap fungsi calcTypeAdvantage
    Engimon e = GenerateEngimon(e2.getName(), e2.getSpecies());
    Engimon e0 = GenerateEngimon(this->getName(), this->getSpecies());
    float adv1 = calcTypeAdvantage(e);
    float adv2 = e.calcTypeAdvantage(e0);
    std::string nm;
    std::string spc;

    if (adv1 >= adv2) { // jika sama, pakai spesies parent 1
        spc = this->getSpecies();
        
    } else {
        spc = e.getSpecies();
    }

    cout << adv1 << ", " << adv2 << endl;

    cout << "You hatched a new " << spc << "!" << endl << "Name: ";
    cin >> nm;
    Engimon e1 = GenerateEngimon(nm, spc);
    return e1;
}