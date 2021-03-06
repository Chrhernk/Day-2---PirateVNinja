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
		std::cout << "A Pirate is born!!" << std::endl; // A funny way of debugging 
		// Name, and random stat generator :D
		SetName("Buck");
		SetHealth(100);
		SetCharisma(RandomRoll());
		SetDex(RandomRoll());
		SetStr(RandomRoll()); 
	}

	void ClassPirate::Talk(std::string StuffToSay)
	{
		std::cout << std::endl << "YAR, My name be " << GetName() << " " << StuffToSay << std::endl; // What it says
	}

	void ClassPirate::Attack()
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

	void ClassPirate::Help()
	{
		std::cout << "\nPirates are Burly and strong, Theyre able to attack with brutal force!"; // Help Function
	}