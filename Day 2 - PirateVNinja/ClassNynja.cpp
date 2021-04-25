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
	SetName("Samurai");
	SetHealth(100);
	SetCharisma(RandomRoll());
	SetDex(RandomRoll());
	SetStr(RandomRoll());

	//std::cout << "A Nynja is born!!" << std::endl; // Debugging phrase
}

void ClassNynja::Talk(std::string StuffToSay)
{
	std::cout << std::endl << "Kon'nichiwa, watashinonamaeha " << GetName() << " " << StuffToSay << std::endl; // What it says
}

int ClassNynja::Attack()
{
	if (ClassNynja::GetStr() >= 50)
	{
		std::cout << GetName() << " is attacking for 50 Damage\n\n";
		int Damage = 50;

		return Damage;
	}
	else
	{
		std::cout << GetName() << " is attacking for 25 Damage\n\n";
		int Damage = 25;
		return Damage;
	}
}