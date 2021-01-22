#pragma once
#include<iostream>
#include "ClassCharacter.h"
class ClassNynja : public ClassCharacter
{
public:
	void Attack(); // the overriding attack
	void ThrowStars(); // Throwing Star Function
	ClassNynja(); // Class constructor
	void Talk(std::string); // Speaking function

};
