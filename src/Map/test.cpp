#include "../Engimon/Engimon.h"
#include "../Engimon/EngimonFactory.h"
#include "../Engimon/Engimons.h"
#include "../Skill/skill.hpp"
#include "Map.h"

int main(){
    // enum Element { NONE = -1, FIRE, WATER, ELECTRIC, GROUND, ICE };
    map<Element, string> ElementString = {
    {WATER, "WATER"}, {FIRE, "FIRE"},  {NONE, "NONE"}, {ELECTRIC, "ELECTRIC"},
    {GROUND, "GROUND"}, {ICE, "ICE"}};

    Map map("../../file/map.txt");
    Dittimon dittimon("Pakuy");
    vector<Element> elements;
    elements.push_back(WATER);
    elements.push_back(NONE);
    for(auto it = map.getElementCode().cbegin(); it != map.getElementCode().cend(); ++it){
        cout << "Elements:\n";
        cout << ElementString[it->first[0]] << " " << ElementString[it->first[1]] << endl;
        cout << "Character: " << it->second;
    }
    
    cout << map.getElementCode().find(elements)->second;
}

//g++ test.cpp ../Engimon/Engimon.cpp ../Engimon/EngimonFactory.cpp ../Engimon/Engimons.cpp ../Skill/Skill.cpp Map.cpp -o test