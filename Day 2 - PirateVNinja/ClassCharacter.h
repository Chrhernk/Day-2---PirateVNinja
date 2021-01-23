#pragma once
#include <string> 
#include<iostream>
#include "ClassGameStructure.h"
// Class Definition
class ClassCharacter : public ClassGameStructure
{
    // Public properties
public:
    // Attack Baseline
    virtual void Attack();
    virtual void Help();
    //Public Property Name
   
    // Stat setters
    void SetName(std::string NN) { Name = NN; }
    void SetHealth(int HP) {Health = HP;}
    void SetDex(int Dexterity) { Dex = Dexterity; }
    void SetCharisma(int Char) { Charisma = Char; }
    void SetStr(int PP) { Str = PP; }
    //Stat Retrievers
    std::string GetName() { return Name; }
    int GetHealth() { return Health; }
    int GetDex() { return Dex; }
    int GetCharisma() { return Charisma; }
    int GetStr() { return Str; }

    void DisplayStats() 
    {
        // Displaying the stats
        std::cout << std::endl << "Name : " << Name << std::endl;
        std::cout << " Health : " << GetHealth() << std::endl;
        std::cout << " Dexterity : " << GetDex() << std::endl;
        std::cout << " Charisma : " << GetCharisma() << std::endl;
        std::cout << " Strength : " << GetStr() << std::endl;
    }

private:
    //Secret stats!
    std::string Name;
    int Health = 100;
    int Dex =0;
    int Charisma =0;
    int Str =0;
};
