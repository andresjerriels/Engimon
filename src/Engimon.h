#ifndef ENGIMON_H
#define ENGIMON_H

#include <vector>

enum Element{none, fire, water, ground, electric, ice};

class Engimon {
private:
    std::vector<Element> elements;
    int level;
    int exp;
    int cum_exp;

public:
    void setElements(Element, Element);
    void setLevel(int);
    void setExp(int);
    void setCumExp(int);
    
public:
    int getLevel();
    int getExp();
    int getCumExp();
    void gainExp(int);
    std::vector<Element> getElements();
};

#endif