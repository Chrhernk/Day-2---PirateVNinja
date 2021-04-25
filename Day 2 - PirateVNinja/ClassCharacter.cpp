#include "ClassCharacter.h"
#include <iostream>

int ClassCharacter::Attack()
{
	std::cout << "Youve been attacked for 10 hit points!!\n\n"; // Baseline attack
	int Damage = 10;
	return Damage;
}

//void ClassCharacter::Help() {} // Void Help function

void ClassCharacter::Talk(std::string stuffToSay) // talking 1
{

	std::cout << "Hello! my name is " << GetName() << " " << stuffToSay << std::endl;

}
void ClassCharacter::Talk(std::string MyName, std::string stuffToSay) // talking 2
{

	std::cout << "Hello! my name is " << MyName << " " << stuffToSay << std::endl;

}