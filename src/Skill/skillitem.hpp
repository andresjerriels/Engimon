#include "skill.hpp"


class SkillItem {
    private :
        Skill skill;
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
        int getItemAmount() const;
        Skill getSkill() const;

        // Setters
        void setSkill(Skill);
        void setAmount(int);

        // Methods
        void incrementItemAmount();
        void decrementItemAmount();
        void printSkillItem();
        // void learn(int EngiInvenIdx,
        //               Inventory<Engimon> EngiInventory,
        //               Inventory<SkillItem> SIinventory);
};

SkillItem returnSkillItem(int amount, string skillname);