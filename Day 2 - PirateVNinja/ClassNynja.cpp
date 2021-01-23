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
	std::cout << "A Nynja is born!!" << std::endl; // Debugging phrase

	// Random stat and name!
	SetName("Samurai");
	SetHealth(100);
	SetCharisma(RandomRoll());
	SetDex(RandomRoll());
	SetStr(RandomRoll());
}

void ClassNynja::Talk(std::string StuffToSay)
{
	std::cout << std::endl << "Kon'nichiwa, watashinonamaeha " << GetName() << " " << StuffToSay << std::endl; // What it says
}

void ClassNynja::Attack()
{
	if (GetStr() <= 70)
	{
		std::cout << "This character is attacking for 25 Damage\n\n"; /// overlaoding attack
	}
	else
	{
		std::cout << "This is a critical hit!!! 50 damage!\n"; // strength check for more damage
	}
}

void ClassNynja::Help()
{ 
	std::cout << "\nNinjas are great! Theyre stealthy, and can attack without alearting anyone nearby!"; // Help function
}