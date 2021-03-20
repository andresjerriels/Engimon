#include "EngimonFactory.h"
#include "Engimons.h"

map<string, int> EngimonFactory::speciesMap = {
    {"Charmamon", 0}, {"Dittimon", 1}, {"Electromon", 2}, {"Mamomon", 3},
    {"Molemon", 4},   {"Pikamon", 5},  {"Tentamon", 6},   {"Torchimon", 7},
    {"Tortomon", 8},  {"Yetimon", 9}};

// Engimon creator nerima int (mempermudah randomizer)
Engimon EngimonFactory::createEngimon(string name, int species) {
  switch (species) {
    case 0:
      return Charmamon(name);
    case 1:
      return Dittimon(name);
    case 2:
      return Electromon(name);
    case 3:
      return Mamomon(name);
    case 4:
      return Molemon(name);
    case 5:
      return Pikamon(name);
    case 6:
      return Tentamon(name);
    case 7:
      return Torchimon(name);
    case 8:
      return Tortomon(name);
    case 9:
      return Yetimon(name);
    default:
      throw "Invalid species";
  }
}

Engimon EngimonFactory::createEngimon(string name, string species) {
  if (speciesMap.count(species)) {
    return createEngimon(name, speciesMap[species]);
  } else {
    throw "Invalid species";
  }
}