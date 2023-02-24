/*
File created by Lizaveta Tarasova on 7/19/2022 as part of the Capstone project for CSC 161
*/

#include <iostream>
#include "Grid.h"
#include "Ship.h"
#include "GridGenerator.h"
#include "estd/AnsiEscape.hpp"
#include <ctime> 
#include <cstdlib>

using namespace std;

//The function places all the ships randomly

void GridGenerator::placeShipsRandomly()
{
	if (getIsPlayer()) securePrint(50, 2);
	else print(50, 2);

	int randomX = 0;
	int randomY = 0;
	bool randomOrientation = true;
	int length = 0;

		randomX = rand() % 10;
		randomY = rand() % 10;
		randomOrientation = rand() % 2;

		switch (numShips)
		{
		case 0: length = 4;
			break;
		case 1: length = 3;
			break;
		case 2: length = 3;
			break;
		case 3: length = 2;
			break;
		case 4: length = 2;
			break;
		case 5: length = 2;
			break;
		case 6: length = 1;
			break;
		case 7: length = 1;
			break;
		case 8: length = 1;
			break;
		case 9: length = 1;
			break;
		default: return;
		}

		Ship* s = new Ship(length, randomOrientation, randomX, randomY);
		ships[numShips] = s;
	

LOOP:
	try {
		mapShips();
	}
	catch (int str)
	{
		int randomSide = 0;
		randomSide = rand() % 4;

		switch (randomSide)
		{
		case 0: s->setYPosition(s->getYPosition() - 1);
			break;
		case 1: s->setYPosition(s->getYPosition() + 1);
			break;
		case 2: s->setXPosition(s->getXPosition() - 1);
			break;
		case 3: s->setXPosition(s->getXPosition() + 1);
			break;
		}

		goto LOOP;
	}

	s->setIsPlaced(true);
	mapShips();
	numShips++;

	placeShipsRandomly();

	if (getIsPlayer()) securePrint(50, 2);
	else print(50, 2);
}

//shoots at the robot's grid at the provided coordinates (x, y)
void GridGenerator::shootTheRobot(int x, int y)
{
	hit(x, y);
}

//updates the grid (prints with all new changes)
void GridGenerator::updateGrid()
{
	if (getIsPlayer()) securePrint(50, 2);
	else print(50, 2);
}

//checks if the ship was hit
bool GridGenerator::checkHit(int x, int y) {return hasShip(x, y);}

//checks if all the ships on the grid were hit
bool GridGenerator::IfAllHit() {return checkIfAllHit();}

//sets the variable to store the mode
void GridGenerator::setIsPlayer(bool choice) {isPlayer = choice;}

// returns the variable to store the mode
bool GridGenerator::getIsPlayer() {return isPlayer;}
