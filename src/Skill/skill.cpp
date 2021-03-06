#include "skill.hpp"

Skill::Skill() {
  this->name = "NONE";
  this->basepower = 0;
  this->mastery = 1;
  this->elements = vector<string>();
  this->n_elmt = 0;
  this->maxElm = total_element_in_game;
}

Skill::Skill(string name) {
  bool isEngimonNameOrUniqueSkill = false;
  int k = 0;
  for (; k < total_engimon_species; k++) {
    if (EngimonBaseInfo[k][0].compare(name) == 0) {
      isEngimonNameOrUniqueSkill = true;
      break;
    }
  }
  // Bukan nama Engimon, maka periksa apakah nama unique skill
  if (!isEngimonNameOrUniqueSkill) {
    k = 0;
    for (; k < total_engimon_species; k++) {
      if (EngimonBaseInfo[k][1].compare(name) == 0) {
        isEngimonNameOrUniqueSkill = true;
        break;
      }
    }
  }
  // Apabila name merupakan nama Engimon atau nama unique skill, maka
  if (isEngimonNameOrUniqueSkill) {
    this->name = EngimonBaseInfo[k][1];
    this->basepower = USkillBP[k];
    this->mastery = 1;
    this->n_elmt = 1;
    this->maxElm = total_element_in_game;
    this->elements = vector<string>();
    this->elements.push_back(EngimonBaseInfo[k][2]);

  }
  // Bukan nama Engimon atau unique skill, berarti nama learnable skill atau
  // nama tidak dikenal
  else {
    bool isSkillName = false;
    int jName;
    int countElm = 0;
    this->elements = vector<string>();
    //
    // total_element_in_game digunakan karena skill diklasifikasikan berdasarkan
    // elemen.
    for (int i = 0; i < total_element_in_game; i++) {
      int totalSkillInElmtArr =
          sizeof(LearnableSkill[i]) / sizeof(LearnableSkill[i][0]);
      for (int j = 0; j < totalSkillInElmtArr; j++) {
        if (LearnableSkill[i][j].compare(name) == 0) {
          if (!isSkillName) {
            isSkillName = true;  // Ditemukan skill ada pada array skill
                                 // setidaknya 1 kali.
            jName = j;
          }
          this->elements.push_back(ElementTypes[i]);
          countElm++;
          break;
        }
      }
    }
    if (isSkillName) {
      this->name = name;
      this->basepower = LearnableSkillBP[jName];
      this->mastery = 1;
      this->n_elmt = countElm;
      this->maxElm = total_element_in_game;

    }
  }
}

Skill::Skill(const Skill& s) {
  this->name = s.name;
  this->basepower = s.basepower;
  this->mastery = s.mastery;
  this->n_elmt = s.n_elmt;
  this->maxElm = s.maxElm;
  this->elements = vector<string>();
  for (int i = 0; i < n_elmt; i++) {
    this->elements.push_back(s.elements[i]);
  }
}

// Destruktor
Skill::~Skill() {

}

// Getters
string Skill::getName() const {
  return name;
}

int Skill::getBasePower() const {
  return basepower;
}

int Skill::getMastery() const {
  return mastery;
}

vector<string> Skill::getSkillElements() const {
  return elements;
}

int Skill::getnSkillElmt() const {
  return n_elmt;
}

// Setters
void Skill::setName(string name) {
  this->name = name;
}

void Skill::setBasePower(int basepower) {
  this->basepower = basepower;
}

void Skill::setMastery(int mastery) {
  this->mastery = mastery;
}

void Skill::setSkillElements(vector<string> elements) {
  this->elements = elements;
}
void Skill::setnSkillElmt(int n_elmt) {
  this->n_elmt = n_elmt;
}

// Methods}

bool Skill::isSkillElement(string element) {
  for (int i = 0; i < n_elmt; i++) {
    if (elements[i].compare(element) == 0) {
      return true;
    }
  }
  return false;
}

void Skill::addElTypeToElArr(string element) {
  int i = 0;
  for (; i < total_element_in_game; i++) {
    if (this->elements[i].compare("") == 0) {
      this->elements[i] = element;
      break;
    }
  }
}

void Skill::printSkillInfo() {
  Util::printFormatKiri("- Name        : " + name);
  Util::printFormatKiri("- Basepower   : " + to_string(basepower));
  Util::printFormatKiri("- Mastery     : " + to_string(mastery));
  
  for (int i = 0; i < elements.size(); i++) {
    if(i == 0) Util::printFormatKiri("- Element(s)  : " + elements[i]);
    else Util::printFormatKiri("                " + elements[i]);
  }
  Util::printFormatKiri("");
}


