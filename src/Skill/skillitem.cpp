#include "skillitem.hpp"

// Constructors
SkillItem::SkillItem() {
  this->skill = Skill();
  this->amount = 0;
}

SkillItem::SkillItem(int amount, string skillName) {
  this->skill = Skill(skillName);
  this->amount = amount;
}

// Copy Constructor
SkillItem::SkillItem(const SkillItem& si) {
  this->skill = Skill(si.skill.getName());
  this->amount = si.amount;
}

// Destructor
SkillItem::~SkillItem() {
  // delete skill;
}

// Getters
int SkillItem::getItemAmount() const {
  return amount;
}

Skill SkillItem::getSkill() const {
  return skill;
}

// Setters
void SkillItem::setAmount(int amount) {
  this->amount = amount;
}

void SkillItem::setSkill(Skill skill) {
  // delete this->skill;
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
  cout << amount << " " << skill.getName() << endl;
}

// void SkillItem::learn(int EngiInvenIdx,
//                       Inventory<Engimon> EngiInventory,
//                       Inventory<SkillItem> SIinventory)
// {
//     vector<Element> vectorEngiElmt = EngiInventory.itemInIventory(EngiInvenIdx).getElements();
//     string elemtSkill = this->skill->getSkillElements();
//     if (amount > 0)
//     {
//         for (int i=0; i<vectorEngiElmt.size(); i++){
//             for (int j=0; j < skill->getnSkillElmt(); j++){
//                 if (vectorEngiElmt[i] == skill->getSkillElements()[j] ){
//                   EngiInventory.itemInIventory(EngiInvenIdx).addSkill(returnSkill(skill->getName()));
//                   if(amount==1){
//                     SIinventory.removeFromInventory(*this);
//                   }
//                 }
//             }
//         }
//     }
// }

SkillItem returnSkillItem(int amount, string skillname) {
  return SkillItem(amount, skillname);
}