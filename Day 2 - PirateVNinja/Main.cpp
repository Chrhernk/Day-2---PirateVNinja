#include<iostream>
#include "ClassNynja.h"
#include "ClassPirate.h"
#include <time.h>

//* Proto Functions >
void GamePlay();
void DisplayIntro();
void PlayerChoice1();
void NinjaPlay();
void PiratePlay();

std::string PlayerName;

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
	std::cout << "Here are the example Characaters!";
	// Talk, Stat check, and shows the Throwing Star/Sword Use function
	Ninja.Talk("And Check out my stats!");
	Ninja.DisplayStats();
	Ninja.ThrowStars();
	Ninja.Attack();
	 
	Pirate.Talk("And here be my score sheet!");
	Pirate.DisplayStats();
	Pirate.UseSword();
	Pirate.Attack();

	ClassCharacter NPC;
	NPC.Attack();


	GamePlay(); // Moving to the next function


	//returns 0
	return 0;
}

//introduction function
void DisplayIntro()
{
	std::cout << std::endl << "Welcome into the world of Pirates Versus Ninjas!" << std::endl << std::endl;
	std::cout << "Prepare for the war of a lifetime!!!" << std::endl;
	std::cout << "This world is in a war to see who is either the most powerful, or who may live the longest to kill the others!";
	std::cout << " After you create your character, you must kill the person holding you hostage to escape!";
}

void GamePlay()  // Where the Player will chose their name
{
	std:: string PlayerChoice;

	std::cout << "What can we call you, Player?";
	std::cin >> PlayerName;

	std::cout << "Welcome " << PlayerName << " Lets make you a character!";

	std::cout << "\nNow, " << PlayerName << " What would you like to Play!\n";
	
	PlayerChoice1();
	
}

void PlayerChoice1() // The choice of what storyline you go through
{
	std::string PlayerChoice;
	std::cout << "A rough and Ready Pirate? Or a sneaky, lithe Ninja?\n";
	std::cin >> PlayerChoice;

	if (PlayerChoice == "Pirate")
	{
		PiratePlay();
	}
	else if (PlayerChoice == "Ninja")
	{
		NinjaPlay();
	}
	else
	{
		std::cout << "That is currently not an option!";
		PlayerChoice1(); // if they miskey, it will loop this so they can retry
	}
}

void PiratePlay() // creating the Pirate Playthrough
{
	

	ClassPirate Player1;

	Player1.SetName(PlayerName);

	std::cout << "You are a Pirate! \n";

	std::cout << "Welcome to the deck " << Player1.GetName() << "\n" << std::endl;

	std::cout << "Here are your stats!\n";

	Player1.Help();

	Player1.DisplayStats();

}

void NinjaPlay() // Ninja Playthrough
{

	ClassNynja Player1;

	Player1.SetName(PlayerName);

	std::cout << " You are a Ninja! \n";

	std::cout << "Welcome to the dojo " << Player1.GetName() << "\n" << std::endl;

	std::cout << "Here are your stats!\n";

	Player1.Help();

	Player1.DisplayStats();

	Player1.Attack();

}

