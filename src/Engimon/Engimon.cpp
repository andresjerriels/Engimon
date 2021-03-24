#include <algorithm>
#include <iostream>
#include <vector>

#include "Engimon.h"
#include "EngimonFactory.h"

Engimon::Engimon() {
  Engimon("", NONE, NONE);
}

Engimon::Engimon(std::string _name, Element elmt1, Element elmt2) {
  this->name = _name;
  this->elements.clear();
  if (elmt1 != NONE)
    this->elements.push_back(elmt1);
  if (elmt2 != NONE)
    this->elements.push_back(elmt2);
  this->level = 1;
  this->exp = 0;
  this->cum_exp = 0;
  this->parentNames = {"None", "None"};
  this->parentSpecies = {"None", "None"};
}

Engimon::Engimon(const Engimon& other){
  name = other.name;
  species = other.species;
  slogan = other.slogan;
  elements.clear();
  elements = other.elements;
  skills.clear();
  skills = other.skills;
  level = other.level;
  exp = other.exp;
  cum_exp = other.cum_exp;
  parentNames = other.parentNames;
  parentSpecies = other.parentSpecies;
}

Engimon& Engimon::operator=(const Engimon& other){
  if(this != &other){
    name = other.name;
    species = other.species;
    slogan = other.slogan;
    elements.clear();
    elements = other.elements;
    skills.clear();
    skills = other.skills;
    level = other.level;
    exp = other.exp;
    cum_exp = other.cum_exp;
    parentNames = other.parentNames;
    parentSpecies = other.parentSpecies;
  }
  return *this;
}

void Engimon::setName(std::string _name) {
  this->name = _name;
}

void Engimon::setSpecies(std::string _species) {
  this->species = _species;
}

void Engimon::setParents(Engimon p1, Engimon p2) {
  parentNames[0] = p1.getName();
  parentSpecies[0] = p1.getSpecies();
  parentNames[1] = p2.getName();
  parentSpecies[1] = p2.getSpecies();
}

void Engimon::setElements(Element elmt1, Element elmt2) {
  this->elements.clear();
  this->elements.push_back(elmt1);
  if (elmt2 != NONE)
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

std::string Engimon::getName() const {
  return this->name;
}
std::string Engimon::getSpecies() const {
  return this->species;
}

int Engimon::getLevel() const {
  return this->level;
}

int Engimon::getExp() const {
  return this->exp;
}

int Engimon::getCumExp() const {
  return this->cum_exp;
}

std::vector<Element> Engimon::getElements() const {
  return this->elements;
}

std::vector<Skill> Engimon::getSkills() const {
  return this->skills;
}

void Engimon::gainExp(int xp) {
  this->cum_exp += xp;
  this->exp += xp;
  this->exp %= 100;
  this->level = (this->cum_exp / 100) + 1;
}

void Engimon::interact() {
  std::cout << "[" << this->name << "]: " << this->slogan << std::endl;
}

void Engimon::addSkill(Skill s) {
  // Jika skill belum dimiliki engimon
  if (!isSkillLearned(s)) {
    // Jika tipe engimon sesuai dengan tipe skill
    if (canLearn(s)) {
      // Jika skill kurang dari 4
      if (skills.size() < 4) {
        skills.push_back(s);
        cout << name << " berhasil mempelajari skill " << s.getName() << endl;
      } else {  // Skill sudah 4
        int pilihan;
        cout << "Skill engimon sudah penuh, pilih skill untuk ditukar" << endl;
        printSkills();
        cout << "Masukkan pilihan (1/2/3/4): ";
        cin >> pilihan;
        if (1 <= pilihan && pilihan <= 4) {
          string oldSkillName = skills[pilihan - 1].getName();
          skills[pilihan - 1] = s;
          cout << name << " berhasil melupakan skill " << oldSkillName
               << " dan mempelajari skill " << s.getName() << endl;
        } else {
          throw "Nomor skill tidak valid";
        }
      }
    } else {
      throw "Elemen engimon tidak kompatibel";
    }
  } else {
    throw "Engimon sudah memiliki skill tersebut";
  }
}

float Engimon::calcTypeAdvantage(const Engimon& e) {
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

Engimon Engimon::Breed(Engimon& e) {
  // baru working untuk masing parent engimon hanya satu element
  // program untuk dual element parent bisa jadi redundan terhadap fungsi
  // calcTypeAdvantage
  if (&e != this) {
    if (level > 30 && e.getLevel() > 30) {
      float adv1 = calcTypeAdvantage(e);
      float adv2 = e.calcTypeAdvantage(*this);
      std::string nm;
      std::string spc;

      level = level - 30;
      e.setLevel(e.getLevel() - 30);

      // jika elemen sama atau advantage lebih tinggi
      if (elements == e.getElements() || adv1 > adv2) {
        spc = species;
      } else if (adv1 < adv2) {  // elemen berbeda dan advantage lebih kecil
        spc = e.getSpecies();
      } else {  // elemen berbeda dan advantage sama
        if ((elements[0] == FIRE && e.getElements()[0] == ELECTRIC) ||
            (elements[0] == ELECTRIC && e.getElements()[0] == FIRE)) {
          spc = "Torchimon";
        } else if ((elements[0] == WATER && e.getElements()[0] == GROUND) ||
                   (elements[0] == GROUND && e.getElements()[0] == WATER)) {
          spc = "Dittimon";
        } else {
          spc = "Tortomon";
        }
      }

      cout << adv1 << ", " << adv2 << endl;

      cout << "You hatched a new " << spc << "!" << endl << "Name: ";
      cin >> nm;

      Engimon child = EngimonFactory::createEngimon(nm, spc);

      child.setParents(*this, e);

      // Hapus skill unik anak
      child.clearSkills();

      // Urut skill parent A sesuai mastery
      vector<Skill> sortedParentASkills = skills;
      sort(sortedParentASkills.begin(), sortedParentASkills.end(),
           [](const Skill& l, const Skill& r) {
             return l.getMastery() > r.getMastery();
           });

      // Urut skill parent B sesuai mastery
      vector<Skill> sortedParentBSkills = e.getSkills();
      sort(sortedParentBSkills.begin(), sortedParentBSkills.end(),
           [](Skill const& l, Skill const& r) {
             return l.getMastery() > r.getMastery();
           });

      auto i = sortedParentASkills.begin();
      auto j = sortedParentBSkills.begin();

      while (child.getSkills().size() < 4 && i != sortedParentASkills.end() &&
             j != sortedParentBSkills.end()) {
        // Mastery skill parent A > parent B
        if ((*i).getMastery() > (*j).getMastery()) {
          if (!child.isSkillLearned(*i) && child.canLearn(*i)) {
            child.addSkill(*i);
          }
          i++;
        } else if ((*i).getMastery() < (*j).getMastery()) {  // Mastery skill parent A < parent B
          if (!child.isSkillLearned(*j) && child.canLearn(*j)) {
            child.addSkill(*j);
          }
          j++;
        } else {  // Mastery skill parent A = parent B
          if (!child.isSkillLearned(*i) && child.canLearn(*i)) {
            if (e.isSkillLearned(*i)) {
              Skill newSkill = (*i);
              newSkill.setMastery(newSkill.getMastery() + 1);
              child.addSkill(newSkill);
            } else {
              child.addSkill(*i);
            }
          }
          i++;
        }
      }

      if (child.getSkills().size() < 4) {
        if (i == sortedParentASkills.end()) {
          while (child.getSkills().size() < 4 && j != sortedParentBSkills.end()) {
            if (!child.isSkillLearned(*j) && child.canLearn(*j)) {
              child.addSkill(*j);
            }
            j++;
          }
        } else {
          while (child.getSkills().size() < 4 && i != sortedParentASkills.end()) {
            if (!child.isSkillLearned(*i) && child.canLearn(*i)) {
              child.addSkill(*i);
            }
            i++;
          }
        }
      }

      return child;
    } else {
      throw "Level parent <= 30";
    }
  } else {
    throw "Cannot breed with self";
  }
}

void Engimon::clearSkills() {
  skills.clear();
}

void Engimon::printSkills() {
  for (auto i = skills.begin(); i != skills.end(); i++) {
    cout << "Skill " << i - skills.begin() + 1 << endl;
    (*i).printSkillInfo();
  }
}

void Engimon::printInfo() {
  cout << "Name: " << name << endl
       << "Species: " << species << endl
       << "Slogan: " << slogan << endl
       << "Parent Names: " << parentNames[0] << ", " << parentNames[1] << endl
       << "Parent Species: " << parentSpecies[0] << ", " << parentSpecies[1]
       << endl
       << "ELement(s): " << ElementTypes[elements[0]]
       << (elements.size() == 2 ? (", " + ElementTypes[elements[1]]) : "")
       << endl
       << "Level: " << level << endl
       << "Exp: " << exp << endl
       << "Cumulative Exp: " << cum_exp << endl
       << "Skills: " << endl;
  printSkills();
}

float Engimon::getPowerLevel(const Engimon& e) {
  float powerLvl = level * calcTypeAdvantage(e);

  for (auto i = skills.begin(); i != skills.end(); i++) {
    powerLvl += (*i).getBasePower() * (*i).getMastery();
  }

  return powerLvl;
}

bool Engimon::isSkillLearned(const Skill& s) {
  for (auto i = skills.begin(); i != skills.end(); i++) {
    if ((*i).getName() == s.getName()) {
      return true;
    }
  }
  return false;
}

bool Engimon::canLearn(const Skill& s) {
  for (auto i = elements.begin(); i != elements.end(); i++) {
    for (auto j = 0; j < s.getnSkillElmt(); j++) {
      if (ElementTypes[(*i)] == s.getSkillElements()[j]) {
        return true;
      }
    }
  }
  return false;
}

ostream& operator<<(ostream &os, const Engimon& e){
  vector<Element> el = e.getElements();
  os << e.getName() << " (" << ElementTypes[el[0]] << (el.size() == 2 ? (", " + ElementTypes[el[1]] + ")") : ")") 
     << " Lvl " << e.getLevel() << endl;
  return os;
}