#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#ifndef __SKILL_HPP__
#define __SKILL_HPP__

const string ElementTypes[5] = {"Fire","Water","Electric","Ground","Ice"};
const string EngimonBaseInfo[10][3] =   {  // Enginame, UniqueSkill, EngimonElement
                                        {"Charmamon","Flame Whip","Fire"},  
                                        {"Torchimon", "Burn", "Fire"}, 
                                        {"Tentamon", "Ink Stroke", "Water"},   
                                        {"Tortomon", "Water Cannon", "Water"},     
                                        {"Pikamon", "Volt Tackle" , "Electric"},     
                                        {"Electromon", "Thunderwhip", "Electric"},  
                                        {"Dittimon", "Dig Strike", "Ground"},   
                                        {"Molemon", "Dirt Claw", "Ground"},    
                                        {"Yetimon", "Cold Stomp", "Ice"},    
                                        {"Mamomon", "Ice Skewer", "Ice"}
                                        };

const float USkillBP[10] = {35,45,35,45,35,45,35,45,35,45};

// const string FireSkill[6] = {"Flame Claw", "Fire Breath", "Fire Bolt", "Flame Punch", "Fiery Explosion", "Magma Spill"};
// const string WaterSkill[6] = {"Water Spill", "Water Slice", "Water Burst", "Surf Wave", "Hydro Cannon", "Tsunami"};
// const string ElectroSkill[6] = {"Shock", "Lightning Bolt", "Thunderbolt", "Electric Surge", "Electric Discharge" ,"Storm Hammer"};
// const string GroundSkill[6] = {"Rock Throw", "Tremor", "Stone Cutter", "Earth Spike", "Bury", "Earthquake"};
// const string IceSkill[6] = {"Frostbite", "Frost Breath", "Ice Spike", "Chilling Touch", "Winter Curse" ,"Ice Blast"};

const string LearnableSkill[5][7] ={
                                    {"Flame Claw", "Fire Breath", "Fire Bolt", "Flame Punch", "Fiery Explosion", "Magma Spill", "Cold Burn"},
                                    {"Water Spill", "Water Slice", "Water Burst", "Surf Wave", "Hydro Cannon", "Tsunami"},
                                    {"Shock", "Lightning Bolt", "Thunderbolt", "Electric Surge", "Electric Discharge" ,"Storm Hammer"},
                                    {"Rock Throw", "Tremor", "Stone Cutter", "Earth Spike", "Bury", "Earthquake"},
                                    {"Frostbite", "Frost Breath", "Ice Spike", "Chilling Touch", "Winter Curse" ,"Ice Blast", "Cold Burn"}
                                    };
const float LearnableSkillBP[7] = {40,45,55,65,75,75,80};

const int total_element_in_game = sizeof(ElementTypes)/sizeof(ElementTypes[0]);
const int total_engimon_species = sizeof(EngimonBaseInfo)/sizeof(EngimonBaseInfo[0]);

class Skill{
    private:
        //int skillID; //
        string name;
        int basepower;
        int mastery;
        vector<string> elements;
        int n_elmt;
        int maxElm; 
    public:
        // Constructor
        Skill();
        Skill(string name); // Menerima nama Engimon atau nama skill.
        
        // Copy Constructor
        Skill(const Skill& s);

        // Destructor
        ~Skill();

        // Getters
        string getName() const;
        int getBasePower() const;
        int getMastery() const;
        vector<string> getSkillElements() const;
        int getnSkillElmt() const;

        // Setters
        void setName(string);
        void setBasePower(int);
        void setMastery(int);
        void setSkillElements(vector<string>);
        void setnSkillElmt(int);

        // Methods
        bool isSkillElement(string element);
        void addElTypeToElArr(string element);
        void printSkillInfo();

};

// Fungsi yang mengconstruct dan mengembalikan Skill.
Skill returnSkill(string name);



#endif