#ifndef ENGIMON_H
#define ENGIMON_H

#include <string>
#include <vector>

enum Element{none, fire, water, ground, electric, ice};

class Engimon {
protected:
    std::string name;
    std::string species;
    std::string slogan;
    std::vector<std::string> parentNames;
    std::vector<std::string> parentSpecies;
    // std::vector<Skill> skills //nunggu kelas Skill
    std::vector<Element> elements;
    int level;
    int exp;
    int cum_exp;

public:
    Engimon(std::string, Element, Element=none);

    // Setters
    void setName(std::string);
    void setSpecies(std::string);
    void setElements(Element, Element);
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
};

#endif