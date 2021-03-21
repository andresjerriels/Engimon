#include "EngimonFactory.h"
#include "Engimons.h"

map<string, int> EngimonFactory::speciesMap = {
    {"Charmamon", 0}, {"Pikamon", 1},  {"Electromon", 2}, {"Molemon", 3},
    {"Torchimon", 4}, {"Dittimon", 5}, {"Mamomon", 6},    {"Tentamon", 7},
    {"Yetimon", 8},   {"Tortomon", 9}};

// Engimon creator nerima int (mempermudah randomizer)
Engimon EngimonFactory::createEngimon(string name, int species) {
  switch (species) {
    case 0:
      return Charmamon(name);
    case 1:
      return Pikamon(name);
    case 2:
      return Electromon(name);
    case 3:
      return Molemon(name);
    case 4:
      return Torchimon(name);
    case 5:
      return Dittimon(name);
    case 6:
      return Mamomon(name);
    case 7:
      return Tentamon(name);
    case 8:
      return Yetimon(name);
    case 9:
      return Tortomon(name);
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