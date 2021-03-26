#ifndef ENGIMONFACTORY_HPP
#define ENGIMONFACTORY_HPP

#include <map>

#include "Engimon.hpp"

using namespace std;

class EngimonFactory {
 private:
  static map<string, int> speciesMap;

 public:
  static Engimon* createEngimon(int species);
  static Engimon createEngimon(string name, int species);
  static Engimon createEngimon(string name, string species);
  static int getSpeciesNumber(string species);
};

#endif