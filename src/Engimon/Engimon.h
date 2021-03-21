#ifndef ENGIMON_H
#define ENGIMON_H

#include <map>
#include <string>
#include <vector>
#include "../Skill/skill.hpp"

enum Element { NONE = -1, FIRE, WATER, ELECTRIC, GROUND, ICE };

// const std::map<Element, string> elementString = {{FIRE, "Fire"},
//                                                  {WATER, "Water"},
//                                                  {ELECTRIC, "Electric"},
//                                                  {GROUND, "Ground"},
//                                                  {ICE, "Ice"}};

const float typeAdvTable[5][5] = {{1, 0, 1, 0.5, 2},
                                  {2, 1, 0, 1, 1},
                                  {1, 2, 1, 0, 1.5},
                                  {1.5, 1, 2, 1, 0},
                                  {0, 1, 0.5, 2, 1}};

class Engimon {
 protected:
  std::string name;
  std::string species;
  std::string slogan;
  std::vector<std::string> parentNames;
  std::vector<std::string> parentSpecies;
  std::vector<Skill> skills;
  std::vector<Element> elements;
  int level;
  int exp;
  int cum_exp;

 public:
  Engimon();
  Engimon(std::string, Element, Element = NONE);

  // Setters
  void setName(std::string);
  void setSpecies(std::string);
  void setParents(Engimon, Engimon);
  void setElements(Element, Element = NONE);
  void setLevel(int);
  void setExp(int);
  void setCumExp(int);

  // Getters
  std::string getName() const;
  std::string getSpecies() const;
  int getLevel() const;
  int getExp() const;
  int getCumExp() const;
  std::vector<Element> getElements() const;

  // Methods
  void gainExp(int);
  void interact();
  void addSkill(Skill);
  float calcTypeAdvantage(const Engimon&);
  Engimon Breed(Engimon&);
  void printSkills();
  void printInfo();
  float getPowerLevel(const Engimon&);

 protected:
  bool isSkillLearned(const Skill&);
  bool canLearn(const Skill&);
};

#endif