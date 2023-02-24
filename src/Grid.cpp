/*
File created by Lizaveta Tarasova on 6/29/2022 as part of the Capstone project for CSC 161
*/

#include <iostream>
#include "Grid.h"
#include "Ship.h"
#include "estd/AnsiEscape.hpp"


using namespace std;

//checks if the cell is located inside of the grid, then checks if the cell or 8 cells around it have already placed ship

bool Grid::checkElement(int x, int y)
{
	if (!(x < 10 && y < 10 && x >= 0 && y >= 0)) {
		return true;
	}
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i < 10 && j < 10 && i >= 0 && j >= 0 && grid[i][j] != ' ')
			{
				return true;
			}
		}
	}
	return false;
}

//declaring the variables to underline displayed text (to divide the cells of the grid)
const string underline = "\033[4m";
const string stopUnderline = "\033[24m";


//prints the grid and fills it with different symbols 
//(# if there is a ship, "space" if there are no ships, and | is to divide the cells of the grid)

void Grid::print(int x, int y)
{
	cout << estd::moveCursor(x, y);

	cout << underline;

	cout << " |A|B|C|D|E|F|G|H|I|J|";

	for (int i = 0; i < 10; i++)
	{
		cout << estd::moveCursor(x, y + i + 1);
		cout << i << "|";

		for (int j = 0; j < 10; j++)
		{
		if (grid[i][j] == '+')
			{
			cout << estd::setTextColor(200, 0, 200);
			cout << "#";
			cout << estd::setTextColor(200, 200, 200);
			cout << "|";
			}
		 else if (grid[i][j] == '@')
			{
				cout << estd::setTextColor(0, 255, 0);
				cout << "#";
				cout << estd::setTextColor(200, 200, 200);
				cout << "|";
			}
		 else if (grid[i][j] == 'X')
		{
			cout << estd::setTextColor(255, 0, 0);
			cout << "X";
			cout << estd::setTextColor(200, 200, 200);
			cout << "|";
		}
		 else if (grid[i][j] == 'O')
		{
			cout << estd::setTextColor(0, 190, 200);
			cout << "O";
			cout << estd::setTextColor(200, 200, 200);
			cout << "|";
		}
			else cout << " " << "|";
		}

	}

	cout << stopUnderline;

}

// This function is for the robot's grid. It displays a grid at the given coordinates without showing the ships
void Grid::securePrint(int x, int y)
{
	cout << estd::moveCursor(x, y);

	cout << underline;

	cout << " |A|B|C|D|E|F|G|H|I|J|";

	for (int i = 0; i < 10; i++)
	{
		cout << estd::moveCursor(x, y + i + 1);
		cout << i << "|";

		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j] == 'X')
			{
				cout << estd::setTextColor(255, 0, 0);
				cout << "X";
				cout << estd::setTextColor(200, 200, 200);
				cout << "|";
			}
			else if (grid[i][j] == 'O')
			{
				cout << estd::setTextColor(0, 190, 200);
				cout << "O";
				cout << estd::setTextColor(200, 200, 200);
				cout << "|";
			}
			else cout << " " << "|";
		}

	}

	cout << stopUnderline;

}

//clears the grid

void Grid::clearGrid() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			grid[i][j] = ' ';
}

//checks if the ship can be placed. If it cannot be placed, throws an exeption. Otherwise, creates pointers for the ship

void Grid::mapShips()
{
	bool isIntersects = false;
	clearGrid();
	for (int i = 0; i < 10; i++)
	{
		if (ships[i] != nullptr)
		{
			int size = ships[i]->getShipSize();
			ships[i]->forceShipInBounds();

			for (int t = 0; t < size; t++)
			{
				int x = ships[i]->getXPosition();
				int y = ships[i]->getYPosition();

				if (ships[i]->getIsVertical()) x += t;
				else y += t;

				if (checkElement(x, y))
				{
					isIntersects = true;
				}
			}

			for (int t = 0; t < size; t++)
			{
				int x = ships[i]->getXPosition();
				int y = ships[i]->getYPosition();

				if (ships[i]->getIsVertical()) x += t;
				else y += t;

				if (ships[i]->getIsPlaced())
					grid[x][y] = '@';
				else grid[x][y] = '+';


			}
		}
	}
	if (isIntersects)
		throw 1;
}

//checks if the cell has ship

bool Grid::hasShip(int x, int y)
{
	if (x < 10 && y < 10 && x >= 0 && y >= 0 && grid[x][y] == '@')
	{
		return true;
	}
	return false;
}


// this function tries to hit a cell, if there was a ship in the cell it will mark it as hit and return true
bool Grid::hit(int x, int y)
{
	if (hasShip(x, y))
	{
	grid[x][y] = 'X';
	return true;
	}
	else
	{
	grid[x][y] = 'O';
	return false;
	}
}

// This function tests if all the ships on the grid were hit 
bool Grid::checkIfAllHit()
{
	bool allHit = true;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j] == '@') allHit = false;
		}
	}
	return allHit;
}

Grid::Grid()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			grid[i][j] = ' ';
		}

	}
	ships = new Ship*[10]();
	for (int i = 0; i < 10; i++)
	{
		ships[i] = nullptr;
	}
}

Grid::~Grid()
{
	for (int i = 0; i < 10; i++)
	{
		if(ships[i] != nullptr)
		delete ships[i];
	}
	
	delete ships;
}
