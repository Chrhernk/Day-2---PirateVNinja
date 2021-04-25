#pragma once
#include<iostream>
#include "ClassPirate.h"

void ClassPirate::UseSword()
{
	// Swoosh the sword 
	std::cout << "I am swooshing my sword!" << std::endl;
}

	ClassPirate::ClassPirate()
	{
		// Name, and random stat generator :D
		SetName("Buck");
		SetHealth(100);
		SetCharisma(RandomRoll());
		SetDex(RandomRoll());
		SetStr(RandomRoll()); 

		//std::cout << "A Pirate is born!!" << std::endl; // A funny way of debugging 
	}

	void ClassPirate::Talk(std::string StuffToSay)
	{
		std::cout << std::endl << "YAR, My name be " << GetName() << " " << StuffToSay << std::endl; // What it says
	}

	int ClassPirate::Attack()
	{
		if (ClassPirate::GetStr() >= 50)
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