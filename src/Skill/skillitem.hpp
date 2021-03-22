#include "skill.hpp"
#include "../Player/Inventory.hpp"

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

        // Operator
        friend ostream& operator<<(ostream&, const SkillItem&);

        // Getters
        int getItemAmount() const;
        Skill getSkill() const;

        // Setters
        void setSkill(Skill);
        void setAmount(int);

        // Methods
        void incrementItemAmount();
        void decrementItemAmount();
        void learn();
};

// SkillItem returnSkillItem(int amount, string skillname);