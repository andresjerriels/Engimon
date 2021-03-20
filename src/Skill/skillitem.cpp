#include "skillitem.hpp"


SkillItem::SkillItem(int amount, string skillName) {
    this->amount = amount;
    this->skill = new Skill(skillName);
}
int SkillItem::getItemAmount(){
    return amount;
}

void SkillItem::incrementItemAmount(){
    amount++;
}

void SkillItem::printSkillItem(){
    amount--;
}
void SkillItem::printSkillItem(){
    cout << amount << " " << skill->getName() << endl;
}
void SkillItem::learn(int invenItemIdx, int InvenEngiIdx){
    
}

SkillItem returnSkillItem(int amount, string skillname){
    return SkillItem(amount, skillname);
}