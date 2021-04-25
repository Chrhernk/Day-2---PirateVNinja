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
void Playthrough();
void FightthePirate();
void FighttheNinja();
void FightBoth();

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
	std::cout << " After you create your character, you must kill the person holding you hostage to escape!\n\n";
}

void GamePlay()  // Where the Player will chose their name
{
	std:: string PlayerChoice;

	std::cout << "What can we call you, Player? ";
	std::cin >> PlayerName;

	std::cout << "Welcome " << PlayerName << " Lets make you a character!";

	std::cout << "\nNow, " << PlayerName << " What would you like to Play!\n";
	
	PlayerChoice1();
	
}

void PlayerChoice1() // The choice of what storyline you go through
{
	int PlayerChoice;
	std::cout << "A rough and Ready Pirate [1]? Or a sneaky, lithe Ninja [2]? Choose [3] to re-read the message!\n";
	std::cin >> PlayerChoice;

	switch (PlayerChoice) {

	case 1:
		PiratePlay();
		break;

	case 2:
		NinjaPlay();
		break;

	case 3:
		std::cout << "Lets take it back a notch!";
		PlayerChoice1();
		break;
	}
}

void PiratePlay() // creating the Pirate Playthrough
{
	
	ClassPirate Player1;

	Player1.SetName(PlayerName);

	std::cout << "Welcome to the deck " << Player1.GetName() << "\n" << std::endl;

	//Player1.Help();

	std::cout << "\nHere are your stats!\n";

	std::cout << "Here are your stats!";

	Player1.DisplayStats();

	Playthrough();

}

void NinjaPlay()
{
	ClassNynja Player1;

	Player1.SetName(PlayerName);

	std::cout << " You are a Ninja! \n";

	std::cout << "Welcome to the Sanctuary " << Player1.GetName() << std::endl;

	std::cout << "Here are your stats!";

	Player1.DisplayStats();

	Playthrough();

}

void Playthrough()
{

	int PlayerChoice;
	std::cout << " Lets begin! You are in an arena, with the choice to make of who you face" << std::endl;
	std::cout << " For a Pirate, Choose [1]";
	std::cout <<  " For a Ninja, Choose [2]";
	std::cout <<     " For Both, Choose [3]";
	std::cin >> PlayerChoice;

	switch (PlayerChoice) {

	case 1:
		std::cout << "You have chosen to fight the Pirate!";
		//FightthePirate();
		break;

	case 2:
		std::cout << "You have chosen to fight the Ninja!";
		//FighttheNinja();
		break;

	case 3:
		std::cout << "You have chosen to fight Both at once!";
		//FightBoth();
		break;
	}



}