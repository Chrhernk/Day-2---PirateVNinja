#pragma once
#include <string> 
#include <fstream>
#include<iostream>
#include "ClassGameStructure.h"
// Class Definition
class ClassCharacter : public ClassGameStructure
{
    // Public properties
public:
    // Attack Baseline
    virtual int Attack();
    // Help Baseline
    //virtual void Help();   

    void Talk(std::string stuffToSay); // Talk 1
    void Talk(std::string MyName, std::string stuffToSay); // Talk 2
   
    // Stat setters
    void SetName(std::string NN) { Name = NN; }
    void Heal(int AmmountHealed) { SetHealth( Health + AmmountHealed); } // Sets the ammount healed
    void TakeDamage(int Damage) { SetHealth( Health - Damage); }// sets the damage taken
    void SetHealth(int HP) // sets our health
    {
        if (HP <= 0) // If health is less or equal to 0
        {
            Health = 0;
            std::cout << Name << " has expired..." << std::endl;
        }
        else // if not, it carries on
        {
            Health = HP;
            std::cout << Name << " has " << Health << " Health remaining" << std::endl;
        }
    }
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
    void WriteStattoFile(std::ofstream *FileIn)
    {
        *FileIn << std::endl << "Name : " << Name << std::endl;
        *FileIn << " Health : " << GetHealth() << std::endl;
        *FileIn << " Dexterity : " << GetDex() << std::endl;
        *FileIn << " Charisma : " << GetCharisma() << std::endl;
        *FileIn << " Strength : " << GetStr() << std::endl;
    }

private:
    //Secret stats!
    std::string Name; // had to change the neame to Private so that i could use the Getter to change name for player
    int Health = 100;
    int Dex =0;
    int Charisma =0;
    int Str =0;
};
