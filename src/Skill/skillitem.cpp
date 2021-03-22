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

ostream& operator<<(ostream &os, const SkillItem& si){
  os << si.getItemAmount() << " " << si.getSkill().getName() << endl;
  return os;
}

void SkillItem::learn(){
  if (amount > 0){
    decrementItemAmount();
  }
  else throw "You don't have the skill item";
}
