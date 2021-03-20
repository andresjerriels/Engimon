#include "skill.hpp"
#include "../Engimon/Engimon.h"

class SkillItem {
    private :
        Skill *skill;
        int amount;
    public :
        SkillItem(int amount, string skillname);
        int getItemAmount();
        void incrementItemAmount();
        void decrementItemAmount();
        void printSkillItem();
        void learn(int invenItemIdx, int invenEngiIdx);
};

SkillItem returnSkillItem(int amount, string skillname);