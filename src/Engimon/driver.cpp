#include <iostream>

#include "EngimonFactory.h"
#include "Engimons.h"

int main(int argc, char const* argv[]) {
  Engimon test = EngimonFactory::createEngimon("P1", "Tortomon");
  Engimon test2 = EngimonFactory::createEngimon("P2", "Dittimon");

  test.setLevel(31);
  test2.setLevel(31);
  cout << test;

  try {

    test2.addSkill(Skill("Tremor"));
    test2.addSkill(Skill("Water Spill"));

    // test.addSkill(Skill("Fire Breath"));
    // test.addSkill(Skill("Fire Bolt"));

    // test.addSkill(Skill("Flame Punch"));
    test.addSkill(Skill("Frostbite"));

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