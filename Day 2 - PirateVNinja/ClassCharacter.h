#pragma once
#include <string> 
#include<iostream>
#include "ClassGameStructure.h"
// Class Definition
class ClassCharacter : public ClassGameStructure
{
    // Public properties
public:
    //Public Property Name
    std::string Name;
    // Stat setters
    void SetHealth(int HP) {Health = HP;}
    void SetDex(int Dexterity) { Dex = Dexterity; }
    void SetCharisma(int Char) { Charisma = Char; }
    void SetStr(int PP) { Str = PP; }
    //Stat Retrievers
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
    int Health =0;
    int Dex =0;
    int Charisma =0;
    int Str =0;
};
