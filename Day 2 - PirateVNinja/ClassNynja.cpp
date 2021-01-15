#pragma once
#include<iostream>
#include "ClassNynja.h"

void ClassNynja::ThrowStars()
{
	// Throwing stars function
	std::cout << "I am throwing stars!" << std::endl;
}

ClassNynja::ClassNynja()
{
	// Random stat and name!
	Name = "Samurai";

	SetHealth(100);
	SetCharisma(RandomRoll());
	SetDex(RandomRoll());
	SetStr(RandomRoll());

	std::cout << "A Nynja is born!!" << std::endl; // Debugging phrase
}

void ClassNynja::Talk(std::string StuffToSay)
{
	std::cout << std::endl << "Kon'nichiwa, watashinonamaeha " << Name << " " << StuffToSay << std::endl; // What it says
}
