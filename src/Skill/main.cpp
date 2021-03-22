#include "../Player/Player.hpp"


int main(){
    // Player ash("Ketchum");
    // Engimon charmamon("Charmamon",FIRE,NONE);
    // ash.addToInvEngimoan(charmamon);
    // ash.setActiveEngimon(charmamon);
    // ash.addToInvSkill("Hydro Cannon");

    Skill a("Hydro Cannon");
    a.printSkillInfo();

    Skill b("Cold Burn");
    b.printSkillInfo();

    SkillItem siTremor(5, "Tremor");
    SkillItem siIBlast(4, "Ice Blast");

    siTremor.printSkillItem();
    siIBlast.printSkillItem();

    Inventory<SkillItem> invsi = Inventory<SkillItem>();
    invsi.addToInventory(siTremor);
    invsi.addToInventory(siIBlast);
    //invsi.printInventory()


}