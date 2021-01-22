#include<iostream>
#include "ClassNynja.h"
#include "ClassPirate.h"
#include <time.h>

//* Proto Functions >
void DisplayIntro();
// main Function
int main() 
{
	// seeder for Random Number Generator
	srand((int)time(NULL));
	//Displays the intro
	DisplayIntro();
	// Births the Bouncing Babies
    ClassNynja Ninja;
    ClassPirate Pirate;
	// Talk, Stat check, and shows the Throwing Star/Sword Use function
	Ninja.Talk("And Check out my stats!");
	Ninja.DisplayStats();
	Ninja.ThrowStars();
	Ninja.Attack();

	Pirate.Talk("And here be my score sheet!");
	Pirate.DisplayStats();
	Pirate.UseSword();
	Pirate.Attack();

	//returns 0
	return 0;
}

//introduction function
void DisplayIntro()
{
	std::cout << std::endl << "Welcome into the world of Pirates Versus Ninjas!" << std::endl << std::endl;
	std::cout << "Prepare for the war of a lifetime!!!" << std::endl;
}