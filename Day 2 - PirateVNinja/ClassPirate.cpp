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
		Name = "Buck";

		SetHealth(100);
		SetCharisma(RandomRoll());
		SetDex(RandomRoll());
		SetStr(RandomRoll()); 

		std::cout << "A Pirate is born!!" << std::endl; // A funny way of debugging 
	}

	void ClassPirate::Talk(std::string StuffToSay)
	{
		std::cout << std::endl << "YAR, My name be " << Name << " " << StuffToSay << std::endl; // What it says
	}
