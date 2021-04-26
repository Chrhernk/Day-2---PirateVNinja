#include<iostream>
#include <fstream>
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
void Playthrough2();
void FightthePirate1();
void FighttheNinja1();
void FightBoth1();
void FightthePirate2();
void FighttheNinja2();
void FightBoth2();
// Global String and Classes for easy Passing through.
std::string PlayerName;
ClassPirate Player1;
ClassNynja Player2;

// main Function
int main() 
{
	
	srand((int)time(NULL));// seeder for Random Number Generator
	DisplayIntro();//Displays the intro
	GamePlay(); // Moving to the next function
	return 0;//returns 0
}
void DisplayIntro()//introduction function
{
	std::cout << std::endl << "Welcome into the world of Pirates Versus Ninjas!" << std::endl << std::endl;
	std::cout << "Prepare for the war of a lifetime!!!" << std::endl;
	std::cout << "This world is in a war to see who is either the most powerful, or who may live the longest to kill the others!";
	std::cout << " After you create your character, you must kill an opponant of your choice to escape!";

	std::cout << "\n\n\n\n\t ***HOW TO PLAY*** \n\n\t";
	std::cout << "\n\n 1. Choose the options you want to play out \n\n";
	std::cout << "\n\n 2. Have fun with it, You could roll a three sided die! \n\n";
	std::cout << "\n\n 3. Dont be afraid to lose! It happens, sometimes you have a bad roll!\n\n";
	std::cout << "\n\n \n\n";
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
	std::cout << "A rough and Ready Pirate [1]? Or a sneaky, lithe Ninja [2]? Choose [3] to re-read the message!\n\n";
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
	Player1.SetName(PlayerName);
	std::cout << "Welcome to the deck " << Player1.GetName() << "\n" << std::endl;
	std::cout << "\nHere are your stats!\n";
	Player1.DisplayStats();
	Playthrough();
}

void NinjaPlay() // Creating the Ninja Playthrough
{
	Player2.SetName(PlayerName);
	std::cout << " You are a Ninja! \n";
	std::cout << "Welcome to the Sanctuary " << Player2.GetName() << std::endl;
	std::cout << "Here are your stats!";
	Player2.DisplayStats();
	Playthrough2();
}

void Playthrough() // Playthrough 1 - A pritate Playthrough!, with a switch statement to decide what you're fighting
{
	int PlayerChoice;
	std::cout << " Lets begin! You are in an arena, with the choice to make of who you face" << std::endl;
	std::cout << " For a Pirate, Choose [1]\n";
	std::cout <<  " For a Ninja, Choose [2]\n";
	std::cout <<     " For Both, Choose [3]\n";
	std::cin >> PlayerChoice;
	switch (PlayerChoice) {
	case 1:
		std::cout << "You have chosen to fight the Pirate!";
		FightthePirate1();
		break;
	case 2:
		std::cout << "You have chosen to fight the Ninja!";
		FighttheNinja1();
		break;
	case 3:
		std::cout << "You have chosen to fight Both at once!";
		FightBoth1();
		break;
	}
}


void FightthePirate1() // Pirate v Pirate
{
	int PlayerChoice;
	ClassPirate PirateNPC;

	std::cout << "This is your Enemy!\n\n";

	PirateNPC.DisplayStats();
	do {
		std::cout << "What would you like to do?\n\n";
		std::cout << " HEAL? [1]\n"; // Heal Yourself
		std::cout << " ATTACK? [2]\n"; // Attack the enemy(s)
		std::cout << " CHECK? [3]\n"; // Check Both HP
		std::cin >> PlayerChoice;
		switch (PlayerChoice) {

		case 1:
			std::cout << "You have chosen to Heal yourself!\n";

			Player1.Heal(10); // Healing Function

			break;

		case 2:
			std::cout << "You have chosen to Attack!\n";

			PirateNPC.TakeDamage(Player1.Attack()); // Reduces the Enemy Health by the ammount returned from Player1.Attack()

			break;

		case 3:
			std::cout << "You have chosen to Check!\n\n"; // you can check the health levels

			std::cout << Player1.GetName() << " : YOU HAVE " << Player1.GetHealth() << " HP"; // Gives Player their health
			std::cout << "" << std::endl;
			std::cout << " ENEMY HAS " << PirateNPC.GetHealth() << " HP\n"; // Shows the enemies health

			break;
		}
		if (PirateNPC.GetHealth() > 0) // while the pirate is alive, it can act
		{
			int NPCCHOICE;
			NPCCHOICE = rand() % 3; // Random Choice generator for Enemy, With the same options from above
			switch (NPCCHOICE) {

			case 0:
				std::cout << "Enemy has chosen to Heal!\n";

				PirateNPC.Heal(10); // Heals the Pirate

				break;

			case 1:
				std::cout << "Enemy has chosen to Attack!\n";

				Player1.TakeDamage(PirateNPC.Attack()); //Reduces Player health by NPC attack

				break;

			case 2:
				std::cout << "Enemy has chosen to Check!\n\n"; // Shows both players health

				std::cout << PirateNPC.GetName() << " : YOU HAVE " << PirateNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << Player1.GetName() << " HAS " << Player1.GetHealth() << " HP\n";

				break;
			}
		}
	} while (PirateNPC.GetHealth() > 0 && Player1.GetHealth() > 0); // While both Health bars are above 0, Will play

	if (Player1.GetHealth() <= 0)
	{
		std::cout << "YOU HAVE DIED!"; // Shows only if the Player died

		std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
		WinLoss << "You Lost! Here are your Stats at the end of the battle!\n\n";
		Player1.WriteStattoFile(&WinLoss);
		WinLoss << "\n\n";
		PirateNPC.WriteStattoFile(&WinLoss);
		WinLoss.close();
	}
	if (PirateNPC.GetHealth() <= 0)
	{
		std::cout << " ENEMY PIRATE DIED!"; // Shows when the Pirate dies

		std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
		WinLoss << "You won! Here are your Stats at the end of the battle!\n\n";
		Player1.WriteStattoFile(&WinLoss);
		WinLoss << "\n\n";
		PirateNPC.WriteStattoFile(&WinLoss);
		WinLoss.close();
	}
}
void FighttheNinja1() // For if you want to fight a Ninja as a Pirate, Carries the same Options as above
{
	ClassNynja NinjaNPC;
	int PlayerChoice;

	NinjaNPC.DisplayStats(); 
	do {
		std::cout << "What would you like to do?\n\n";
		std::cout << " HEAL? [1]\n"; // Heals Player
		std::cout << " ATTACK? [2]\n"; // Attacks enemies
		std::cout << " CHECK? [3]\n"; // Checks both health
		std::cin >> PlayerChoice;
		switch (PlayerChoice) {

		case 1:
			std::cout << "You have chosen to Heal yourself!\n";

			Player1.Heal(10); // Heals player 10 points

			break;

		case 2:
			std::cout << "You have chosen to Attack!\n";

			NinjaNPC.TakeDamage(Player1.Attack()); // attacks enemies for the return ammount of the Players attack

			break;

		case 3:
			std::cout << "You have chosen to Check!\n\n"; // checks the Players and enemies health

			std::cout << Player1.GetName() << " : YOU HAVE " << Player1.GetHealth() << " HP";
			std::cout << "" << std::endl;
			std::cout << " ENEMY HAS " << NinjaNPC.GetHealth() << " HP\n";

			break;
		}
		if (NinjaNPC.GetHealth() > 0) // if the Ninjas health is above zero, it is allowed to act
		{
			int NPCCHOICE;
			NPCCHOICE = rand() % 3;
			switch (NPCCHOICE) {

			case 0:
				std::cout << "Enemy has chosen to Heal!\n";// enemy can heal

				NinjaNPC.Heal(10);

				break;

			case 1:
				std::cout << "Enemy has chosen to Attack!\n"; // enemy can attack

				Player1.TakeDamage(NinjaNPC.Attack());

				break;

			case 2:
				std::cout << "Enemy has chosen to Check!\n\n"; // enemy can check

				std::cout << NinjaNPC.GetName() << " : YOU HAVE " << NinjaNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << Player1.GetName() << " HAS " << Player1.GetHealth() << " HP\n";

				break;
			}
		}
	} while (NinjaNPC.GetHealth() > 0 && Player1.GetHealth() > 0); // while the player, and the Enemy are alive, it loops
	if (Player1.GetHealth() <= 0) // when player dies, this prints
	{
		std::cout << "YOU HAVE DIED!";

		std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
		WinLoss << "You Lost! Here are your Stats at the end of the battle!\n\n";
		Player1.WriteStattoFile(&WinLoss);
		WinLoss << "\n\n";
		NinjaNPC.WriteStattoFile(&WinLoss);
		WinLoss.close();
	}
	if (NinjaNPC.GetHealth() <= 0) // when enemy died, this prints
	{
		std::cout << " ENEMY PIRATE DIED!";

		std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
		WinLoss << "You Won! Here are your Stats at the end of the battle!\n\n";
		Player1.WriteStattoFile(&WinLoss);
		WinLoss << "\n\n";
		NinjaNPC.WriteStattoFile(&WinLoss);
		WinLoss.close();
	}

}
void FightBoth1() // while the Player is a pirate, they can fight both
{
	int PlayerChoice;

	ClassNynja NinjaNPC;
	ClassPirate PirateNPC;

	PirateNPC.DisplayStats();
	NinjaNPC.DisplayStats();

	do {
		std::cout << "What would you like to do?\n\n";
		std::cout << " HEAL? [1]\n";
		std::cout << " ATTACK? [2]\n";
		std::cout << " CHECK? [3]\n";
		std::cin >> PlayerChoice;
		switch (PlayerChoice) {

		case 1:
			std::cout << "You have chosen to Heal yourself!\n"; // we can heal

			Player1.Heal(50);

			break;

		case 2:
			std::cout << "You have chosen to Attack!\n"; // we can attack

			NinjaNPC.TakeDamage(Player1.Attack());
			PirateNPC.TakeDamage(Player1.Attack());

			break;

		case 3:
			std::cout << "You have chosen to Check!\n\n"; // we can check

			std::cout << Player1.GetName() << " : YOU HAVE " << Player1.GetHealth() << " HP";
			std::cout << "" << std::endl;
			std::cout << " ENEMY NINJA HAS " << NinjaNPC.GetHealth() << " HP\n";
			std::cout << "" << std::endl;
			std::cout << " ENEMY PIRATE HAS " << PirateNPC.GetHealth() << " HP\n";

			break;
		}
		if (NinjaNPC.GetHealth() > 0) // while alive, they can act
		{
			int NPCCHOICE;
			NPCCHOICE = rand() % 3;
			switch (NPCCHOICE) {

			case 0:
				std::cout << "Enemy has chosen to Heal!\n"; // enemy can heal

				NinjaNPC.Heal(10);

				break;

			case 1:
				std::cout << "Enemy has chosen to Attack!\n"; // enemy can attack

				Player1.TakeDamage(NinjaNPC.Attack());

				break;

			case 2:
				std::cout << "Enemy has chosen to Check!\n\n"; // enemy can check

				std::cout << NinjaNPC.GetName() << " : YOU HAVE " << NinjaNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << PirateNPC.GetName() << " : YOU HAVE " << PirateNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << Player1.GetName() << " HAS " << Player1.GetHealth() << " HP\n";

				break;
			}
		}
		if (PirateNPC.GetHealth() > 0)// while alive, the Pirate can act
		{
			int NPCCHOICE2;
			NPCCHOICE2 = rand() % 3;
			switch (NPCCHOICE2) {

			case 0:
				std::cout << "Enemy has chosen to Heal!\n"; // enemy can heal

				PirateNPC.Heal(10);

				break;

			case 1:
				std::cout << "Enemy has chosen to Attack!\n"; // enemy can attack

				Player1.TakeDamage(PirateNPC.Attack());

				break;

			case 2:
				std::cout << "Enemy has chosen to Check!\n\n"; // enemy can check

				std::cout << NinjaNPC.GetName() << " : YOU HAVE " << NinjaNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << PirateNPC.GetName() << " : YOU HAVE " << PirateNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << Player1.GetName() << " HAS " << Player1.GetHealth() << " HP\n";

				break;
			}
		}

		if (Player1.GetHealth() <= 0)
		{
			std::cout << "YOU HAVE DIED!"; // when the player dies, this is printed

			std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
			WinLoss << "You Lost! Here are your Stats at the end of the battle!\n\n";
			Player1.WriteStattoFile(&WinLoss);
			WinLoss << "\n\n";
			NinjaNPC.WriteStattoFile(&WinLoss);
			WinLoss << "\n\n";
			PirateNPC.WriteStattoFile(&WinLoss);
			WinLoss.close();

		}
		if (PirateNPC.GetHealth() <= 0 && NinjaNPC.GetHealth() <=0)
		{
			std::cout << "ENEMIES DIED!"; // when the enemy dies, it pritns this

			std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
			WinLoss << "You Lost! Here are your Stats at the end of the battle!\n\n";
			Player1.WriteStattoFile(&WinLoss);
			WinLoss << "\n\n";
			NinjaNPC.WriteStattoFile(&WinLoss);
			WinLoss << "\n\n";
			PirateNPC.WriteStattoFile(&WinLoss);
			WinLoss.close();
		}
		


	} while ((NinjaNPC.GetHealth() > 0 || PirateNPC.GetHealth() > 0) && Player1.GetHealth() > 0);// while either enemy is alive, and the player is alive, it continues
}
void Playthrough2()
{
	// This function is if the Player chooses to play a ninja, and lets them choose who they want to fight

	int PlayerChoice;
	std::cout << " Lets begin! You are in an arena, with the choice to make of who you face" << std::endl;
	std::cout << " For a Pirate, Choose [1]\n";
	std::cout << " For a Ninja, Choose [2]\n";
	std::cout << " For Both, Choose [3]\n";
	std::cin >> PlayerChoice;

	switch (PlayerChoice) {

	case 1:
		std::cout << "You have chosen to fight the Pirate!";
		FightthePirate2();
		break;

	case 2:
		std::cout << "You have chosen to fight the Ninja!";
		FighttheNinja2();
		break;

	case 3:
		std::cout << "You have chosen to fight Both at once!";
		FightBoth2();
		break;
	}

}


void FightthePirate2() // We fight a Pirate as a ninja
{
	int PlayerChoice;
	ClassPirate PirateNPC;

	std::cout << "This is your Enemy!\n\n";

	PirateNPC.DisplayStats();
	do {
		std::cout << "What would you like to do?\n\n";
		std::cout << " HEAL? [1]\n";
		std::cout << " ATTACK? [2]\n";
		std::cout << " CHECK? [3]\n";
		std::cin >> PlayerChoice;
		switch (PlayerChoice) {

		case 1:
			std::cout << "You have chosen to Heal yourself!\n"; // we heal

			Player2.Heal(10);

			break;

		case 2:
			std::cout << "You have chosen to Attack!\n"; // We attack enemy

			PirateNPC.TakeDamage(Player2.Attack());

			break;

		case 3:
			std::cout << "You have chosen to Check!\n\n"; // we check health levels

			std::cout << Player2.GetName() << " : YOU HAVE " << Player2.GetHealth() << " HP";
			std::cout << "" << std::endl;
			std::cout << " ENEMY HAS " << PirateNPC.GetHealth() << " HP\n";

			break;
		}
		if (PirateNPC.GetHealth() > 0) // thile the Pirate is alive, it can act
		{
			int NPCCHOICE;
			NPCCHOICE = rand() % 3;
			switch (NPCCHOICE) {

			case 0:
				std::cout << "Enemy has chosen to Heal!\n"; // enemy heals

				PirateNPC.Heal(10);

				break;

			case 1:
				std::cout << "Enemy has chosen to Attack!\n"; // enemy attacks us

				Player2.TakeDamage(PirateNPC.Attack());

				break;

			case 2:
				std::cout << "Enemy has chosen to Check!\n\n"; // enemy can check health

				std::cout << PirateNPC.GetName() << " : YOU HAVE " << PirateNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << Player2.GetName() << " HAS " << Player2.GetHealth() << " HP\n";

				break;
			}
		}
	} while (PirateNPC.GetHealth() > 0 && Player2.GetHealth() > 0); // while both are alive, it runs
	if (Player2.GetHealth() <= 0) // if the Player is dead, This prints
	{
		std::cout << "YOU HAVE DIED!";
		std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
		WinLoss << "You Lost! Here are your Stats at the end of the battle!\n\n";
		Player2.WriteStattoFile(&WinLoss);
		WinLoss << "\n\n";
		PirateNPC.WriteStattoFile(&WinLoss);
		WinLoss.close();
	}
	if (PirateNPC.GetHealth() <= 0) // If the pirate dies, This prints
	{
		std::cout << " ENEMY PIRATE DIED!";
		std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
		WinLoss << "You Won! Here are your Stats at the end of the battle!\n\n";
		Player2.WriteStattoFile(&WinLoss);
		WinLoss << "\n\n";
		PirateNPC.WriteStattoFile(&WinLoss);
		WinLoss.close();
	}
}
void FighttheNinja2() // When the Player is a ninja, And they attack a Ninja
{
	ClassNynja NinjaNPC;
	int PlayerChoice;

	NinjaNPC.DisplayStats();
	do {
		std::cout << "What would you like to do?\n\n";
		std::cout << " HEAL? [1]\n";
		std::cout << " ATTACK? [2]\n";
		std::cout << " CHECK? [3]\n";
		std::cin >> PlayerChoice;
		switch (PlayerChoice) {

		case 1:
			std::cout << "You have chosen to Heal yourself!\n"; // you can heal

			Player2.Heal(10);

			break;

		case 2:
			std::cout << "You have chosen to Attack!\n"; // You can attack

			NinjaNPC.TakeDamage(Player2.Attack());

			break;

		case 3:
			std::cout << "You have chosen to Check!\n\n"; // you can check the health levels

			std::cout << Player2.GetName() << " : YOU HAVE " << Player1.GetHealth() << " HP";
			std::cout << "" << std::endl;
			std::cout << " ENEMY HAS " << NinjaNPC.GetHealth() << " HP\n";

			break;
		}
		if (NinjaNPC.GetHealth() > 0) // while the Ninja is alive, It can act
		{
			int NPCCHOICE;
			NPCCHOICE = rand() % 3;// random number generator chooses the action the NPC takes
			switch (NPCCHOICE) {

			case 0:
				std::cout << "Enemy has chosen to Heal!\n"; // enemy can heal

				NinjaNPC.Heal(10);

				break;

			case 1:
				std::cout << "Enemy has chosen to Attack!\n"; // enemy can attack us

				Player2.TakeDamage(NinjaNPC.Attack());

				break;

			case 2:
				std::cout << "Enemy has chosen to Check!\n\n"; // enemy can check our health

				std::cout << NinjaNPC.GetName() << " : YOU HAVE " << NinjaNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << Player2.GetName() << " HAS " << Player2.GetHealth() << " HP\n";

				break;
			}
		}
	} while (NinjaNPC.GetHealth() > 0 && Player2.GetHealth() > 0); // while the ninja, and the Player is alive, it runs

	if (Player2.GetHealth() <= 0) // if player is dead, this prints
	{
		std::cout << "YOU HAVE DIED!";
		std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
		WinLoss << "You Lost! Here are your Stats at the end of the battle!\n\n";
		Player2.WriteStattoFile(&WinLoss);
		WinLoss << "\n\n";
		NinjaNPC.WriteStattoFile(&WinLoss);
		WinLoss.close();
	}
	if (NinjaNPC.GetHealth() <= 0) // if Ninja Died, It prints this to the file
	{
		std::cout << " ENEMY NINJA DIED!";
		std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
		WinLoss << "You Won! Here are your Stats at the end of the battle!\n\n";
		Player2.WriteStattoFile(&WinLoss);
		WinLoss << "\n\n";
		NinjaNPC.WriteStattoFile(&WinLoss);
		WinLoss.close();
	}
}
void FightBoth2()
{
	int PlayerChoice;

	ClassNynja NinjaNPC;
	ClassPirate PirateNPC;

	PirateNPC.DisplayStats();
	NinjaNPC.DisplayStats();

	do {
		std::cout << "What would you like to do?\n\n";
		std::cout << " HEAL? [1]\n";
		std::cout << " ATTACK? [2]\n";
		std::cout << " CHECK? [3]\n";
		std::cin >> PlayerChoice;
		switch (PlayerChoice) {

		case 1:
			std::cout << "You have chosen to Heal yourself!\n"; // You can heal yourself

			Player1.Heal(50);

			break;

		case 2:
			std::cout << "You have chosen to Attack!\n"; // you can attack both enemies

			NinjaNPC.TakeDamage(Player2.Attack());
			PirateNPC.TakeDamage(Player2.Attack());

			break;

		case 3:
			std::cout << "You have chosen to Check!\n\n"; // you can check health levels

			std::cout << Player2.GetName() << " : YOU HAVE " << Player1.GetHealth() << " HP";
			std::cout << "" << std::endl;
			std::cout << " ENEMY NINJA HAS " << NinjaNPC.GetHealth() << " HP\n";
			std::cout << "" << std::endl;
			std::cout << " ENEMY PIRATE HAS " << PirateNPC.GetHealth() << " HP\n";

			break;
		}
		if (NinjaNPC.GetHealth() > 0)
		{
			int NPCCHOICE;
			NPCCHOICE = rand() % 3;
			switch (NPCCHOICE) {

			case 0:
				std::cout << "Enemy has chosen to Heal!\n"; // Enemy can heal themselves

				NinjaNPC.Heal(10);

				break;

			case 1:
				std::cout << "Enemy has chosen to Attack!\n"; // Enemy attacks player

				Player1.TakeDamage(NinjaNPC.Attack());

				break;

			case 2:
				std::cout << "Enemy has chosen to Check!\n\n"; // enemy can check Health Levels

				std::cout << NinjaNPC.GetName() << " : YOU HAVE " << NinjaNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << PirateNPC.GetName() << " : YOU HAVE " << PirateNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << Player2.GetName() << " HAS " << Player2.GetHealth() << " HP\n";

				break;
			}
		} // if the Ninja is dead, it cant act
		if (PirateNPC.GetHealth() > 0)
		{
			int NPCCHOICE2;
			NPCCHOICE2 = rand() % 3; // Random number generator able to choose what the enemy does
			switch (NPCCHOICE2) {

			case 0:
				std::cout << "Enemy has chosen to Heal!\n"; // enemy Can heal themselves

				PirateNPC.Heal(10);

				break;

			case 1:
				std::cout << "Enemy has chosen to Attack!\n"; // enemy can attack us the player

				Player2.TakeDamage(PirateNPC.Attack());

				break;

			case 2:
				std::cout << "Enemy has chosen to Check!\n\n"; // enemy can check health levels

				std::cout << NinjaNPC.GetName() << " : YOU HAVE " << NinjaNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << PirateNPC.GetName() << " : YOU HAVE " << PirateNPC.GetHealth() << " HP";
				std::cout << "" << std::endl;
				std::cout << Player2.GetName() << " HAS " << Player2.GetHealth() << " HP\n";

				break;
			}
		} // Of the Pirate is dead, it cant act.

		if (Player2.GetHealth() <= 0) // if you died, the File output says you lost!
		{
			std::cout << "YOU HAVE DIED!";

			std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
			WinLoss << "You Lost! Here are your Stats at the end of the battle!\n\n";
			Player1.WriteStattoFile(&WinLoss);
			WinLoss << "\n\n";
			PirateNPC.WriteStattoFile(&WinLoss);
			WinLoss << "\n\n";
			NinjaNPC.WriteStattoFile(&WinLoss);
			WinLoss.close();
			
		}
		if (PirateNPC.GetHealth() <= 0 && NinjaNPC.GetHealth() <= 0) // When both enemies are dead, it prints the output
		{
			std::cout << " ENEMIES DIED!";

			std::ofstream WinLoss("WinLossFun.txt", std::ofstream::app);
			WinLoss << "You Won! Here are your Stats at the end of the battle!\n\n";
			Player1.WriteStattoFile(&WinLoss);
			WinLoss << "\n\n";
			PirateNPC.WriteStattoFile(&WinLoss);
			WinLoss << "\n\n";
			NinjaNPC.WriteStattoFile(&WinLoss);
			WinLoss.close();
		}


	} while ((NinjaNPC.GetHealth() > 0 || PirateNPC.GetHealth() > 0) && Player2.GetHealth() > 0); // while any of them are alive, It continues
} 

