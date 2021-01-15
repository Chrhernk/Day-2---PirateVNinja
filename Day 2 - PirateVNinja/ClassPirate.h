#pragma once
#include<iostream>
#include "ClassCharacter.h"
// Class Definition
class ClassPirate : public ClassCharacter 
{
public:
	
	void UseSword(); // Sword use function
	ClassPirate(); // Pirate class constructor
	void Talk(std::string); // Talking function
};


