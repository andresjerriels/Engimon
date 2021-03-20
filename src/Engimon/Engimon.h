#ifndef ENGIMON_H
#define ENGIMON_H

#include <string>
#include <vector>
#include "../Skill/skill.hpp"

enum Element{none = -1, fire, water, electric, ground, ice};

const float typeAdvTable[5][5] = {
    {1, 0, 1, 0.5, 2},
    {2, 1, 0, 1, 1}, 
    {1, 2, 1, 0, 1.5}, 
    {1.5, 1, 2, 1, 0}, 
    {0, 1, 0.5, 2, 1}
    };

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
    Engimon(std::string, Element, Element=none);

    // Setters
    void setName(std::string);
    void setSpecies(std::string);
    void setElements(Element, Element=none);
    void setLevel(int);
    void setExp(int);
    void setCumExp(int);
    
    // Getters
    std::string getName();
    std::string getSpecies();
    int getLevel();
    int getExp();
    int getCumExp();
    std::vector<Element> getElements();

    //Methods
    void gainExp(int);
    void interact();
    float calcTypeAdvantage(Engimon&);
    static Engimon GenerateEngimon(std::string, std::string);
    Engimon Breed(Engimon&);
};

#endif