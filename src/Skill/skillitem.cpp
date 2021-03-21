#include "skillitem.hpp"

// Constructors
SkillItem::SkillItem() {
  this->skill = new Skill();
  this->amount = 0;
}

SkillItem::SkillItem(int amount, string skillName) {
  this->skill = new Skill(skillName);
  this->amount = amount;
}

// Copy Constructor
SkillItem::SkillItem(const SkillItem& si) {
  this->skill = new Skill(si.skill->getName());
  this->amount = si.amount;
}

// Destructor
SkillItem::~SkillItem() {
  delete skill;
}

// Getters
int SkillItem::getItemAmount() {
  return amount;
}

Skill SkillItem::getSkill() {
  return *skill;
}

// Setters
void SkillItem::setAmount(int amount) {
  this->amount = amount;
}

void SkillItem::setSkill(Skill *skill) {
  delete this->skill;
  this->skill = skill;
}

// Methods
void SkillItem::incrementItemAmount() {
  amount++;
}

void SkillItem::decrementItemAmount() {
  amount--;
}

void SkillItem::printSkillItem() {
  cout << amount << " " << skill->getName() << endl;
}

// void SkillItem::learn(int EngiInvenIdx,
//                       Inventory<Engimon> EngiInventory,
//                       Inventory<SkillItem> SIinventory)
// {
//     vector<Element> vectEngiElements = vector<Element>();
//     if (amount > 0 && EngiInventory.g != -1)
//     {
//         for (int i=0; i<EngiInventory[EngiInvenIdx].getElements().size();
//         i++){
//             for (int j=0; j < this->skill.getSkillElmt() ){
//                 if (EngiInventory[EngiInvenIdx].getElements()[i] ){

//                 }
//             }
//         }
//     }
// }

SkillItem returnSkillItem(int amount, string skillname) {
  return SkillItem(amount, skillname);
}