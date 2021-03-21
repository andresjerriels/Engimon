#include "skill.hpp"
#include "../Player/Inventory.hpp"
#include "../Engimon/Engimon.h"

class SkillItem {
    private :
        Skill *skill;
        int amount;
    public :
        // Constructor
        SkillItem();
        SkillItem(int amount, string skillname);

        // Copy Constructor
        SkillItem(const SkillItem&);

        // Destructor
        ~SkillItem();

        // Getters
        int getItemAmount();
        Skill getSkill();

        // Setters
        void setSkill(Skill*);
        void setAmount(int);

        // Methods
        void incrementItemAmount();
        void decrementItemAmount();
        void printSkillItem();
        void learn(int invenItemIdx, int invenEngiIdx);
};

SkillItem returnSkillItem(int amount, string skillname);