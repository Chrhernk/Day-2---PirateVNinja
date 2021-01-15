#include<iostream>    
#include <time.h>       /* time */

int RandomRoll() {


	int DieRoll; // Integer


	DieRoll = rand() % 100 + 1; // Random Generator

	return DieRoll; // Returns the Rolled Int
}