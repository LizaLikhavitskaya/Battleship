/*
File created by Lizaveta Tarasova on 6/30/2022 as part of the Capstone project for CSC 161
*/

#include <iostream>
#include "Grid.h"
#include "Ship.h"
#include "estd/AnsiEscape.hpp"
#include "GridEditor.h"
#include "GridGenerator.h"

using namespace std;


//places ship with the help of arrow and space keys
void GridEditor::placeShip(int len)
{
	print(10, 2);

	Ship* s = new Ship(len, true, 0, 0);
	ships[numShips] = s;

	try {
		mapShips();
	}
	catch (int s)
	{
		cout << estd::moveCursor(0, 13);
		cout << "Error " << s << ": The ship can not be placed here. Please, move the ship." << endl;
	}
	print(10, 2);

	while (true) {
		char c = estd::getArrowKeyPress();
		if (c == ' ')
		{
			if (s->getIsVertical())
				s->setIsVertical(false);
			else s->setIsVertical(true);
		}

		if (c == 'L')
		{
			s->setYPosition(s->getYPosition() - 1);
		}

		if (c == 'R')
		{
			s->setYPosition(s->getYPosition() + 1);
		}

		if (c == 'D')
		{
			s->setXPosition(s->getXPosition() + 1);
		}

		if (c == 'U')
		{
			s->setXPosition(s->getXPosition() - 1);
		}
			
		cout << estd::moveCursor(0, 13);
		cout << estd::clearLineAfterCursor;

		try {
			mapShips();

			if (c == 'E')
			{
				s->setIsPlaced(true);
				mapShips();
				print(10, 2);
				numShips++;
				return;
			}
		}
		catch (int s)
		{
			cout << estd::moveCursor(0, 13);
			cout << "Error " << s << ": The ship can not be placed here. Please, move the ship." << endl;
		}
		print(10, 2);
		
	}
}

//shoots at the user's grid at the provided coordinates (x, y)
void GridEditor::shootTheUser(int x, int y)
{
	hit(x, y);
}

//updates the grid (prints with all new changes)
void GridEditor::updateGrid()
{
	print(10, 2);
}

//checks if the ship was hit
bool GridEditor::checkHit(int x, int y)
{
	return hasShip(x, y);
}

//checks if all the ships on the grid were hit
bool  GridEditor::IfAllHit()
{
	return checkIfAllHit();
}
