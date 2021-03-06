#include "EngimonFactory.hpp"
#include "Engimons.hpp"

map<string, int> EngimonFactory::speciesMap = {
    {"Charmamon", 0}, {"Pikamon", 1},  {"Electromon", 2}, {"Molemon", 3},
    {"Torchimon", 4}, {"Dittimon", 5}, {"Mamomon", 6},    {"Tentamon", 7},
    {"Yetimon", 8},   {"Tortomon", 9}};

int EngimonFactory::getSpeciesNumber(string species){
  return speciesMap[species];
}
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
      throw "*                 Invalid species                   *";
  }
}

Engimon* EngimonFactory::createEngimon(int species) {
  switch (species) {
    case 0:
      return new Charmamon("Wild Charmamon");
    case 1:
      return new Pikamon("Wild Pikamon");
    case 2:
      return new Electromon("Wild Electromon");
    case 3:
      return new Molemon("Wild Molemon");
    case 4:
      return new Torchimon("Wild Torchimon");
    case 5:
      return new Dittimon("Wild Dittimon");
    case 6:
      return new Mamomon("Wild Mamomon");
    case 7:
      return new Tentamon("Wild Tentamon");
    case 8:
      return new Yetimon("Wild Yetimon");
    case 9:
      return new Tortomon("Wild Tortomon");
    default:
      throw "*                 Invalid species                   *";
  }
}

Engimon EngimonFactory::createEngimon(string name, string species) {
  if (speciesMap.count(species)) {
    return createEngimon(name, speciesMap[species]);
  } else {
    throw "*                 Invalid species                   *";
  }
}