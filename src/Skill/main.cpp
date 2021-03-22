#include "../Player/Player.hpp"


int main(){
    // Player ash("Ketchum");
    // Engimon charmamon("Charmamon",FIRE,NONE);
    // ash.addToInvEngimoan(charmamon);
    // ash.setActiveEngimon(charmamon);
    // ash.addToInvSkill("Hydro Cannon");

    cout << "Construct skill and Print" << endl;
    Skill a("Hydro Cannon");
    a.printSkillInfo();

    Skill b("Cold Burn");
    b.printSkillInfo();

    cout << "Construct skillItem and Print" << endl;
    SkillItem siTremor(5, "Tremor");
    SkillItem siIBlast(4, "Ice Blast");

    cout << siTremor;
    cout << siIBlast;

    Inventory<SkillItem> invsi = Inventory<SkillItem>();
    invsi.addToInventory(siTremor);
    invsi.addToInventory(siIBlast);

    siTremor.learn();
    siIBlast.learn();
    
    cout << "After learn" << endl;
    cout << siTremor;
    cout << siIBlast;


}