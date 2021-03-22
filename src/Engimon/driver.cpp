#include <iostream>

#include "EngimonFactory.h"
#include "Engimons.h"

int main(int argc, char const* argv[]) {
  Engimon test = EngimonFactory::createEngimon("P1", "Charmamon");
  Engimon test2 = EngimonFactory::createEngimon("P2", "Charmamon");

  test.setLevel(30);
  test2.setLevel(30);

  try {

    test.addSkill(Skill("Flame Claw"));

    // test.addSkill(Skill("Fire Breath"));
    // test.addSkill(Skill("Fire Bolt"));

    test.addSkill(Skill("Flame Punch"));
    test2.addSkill(Skill("Flame Punch"));

    Engimon anak = test.Breed(test2);
    anak.printInfo();
    test.printInfo();
    test2.printInfo();

  } catch (char const* e) {
    std::cerr << e << '\n';
  }

  return 0;
}

// g++ .\driver.cpp .\Engimon.cpp .\EngimonFactory.cpp .\Engimons.cpp ..\Skill\skill.cpp