#ifndef ENGIMONFACTORY_H
#define ENGIMONFACTORY_H

#include "Engimon.h"

#include <map>

using namespace std;

class EngimonFactory {
 private:
  static map<string, int> speciesMap;

 public:
  static Engimon* createEngimon(int species);
  static Engimon createEngimon(string name, int species);
  static Engimon createEngimon(string name, string species);
};

#endif