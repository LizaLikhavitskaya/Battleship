/*
File created by Lizaveta Tarasova on 6/24/2022 as part of the Capstone project for CSC 161
*/

#pragma once
#include <iostream>
#include "Ship.h"

using namespace std;

//This class represents a grid that the games will use.
class Grid
{
public:
	Grid();
	~Grid();
	// This function displays a grid at the given coordinates
	void print(int x, int y);
	// This function is for the robot's grid. It displays a grid at the given coordinates without showing the ships
	void securePrint(int x, int y);
	// this function tests if a cell contains a ship, if there was a ship in the cell it will NOT mark it as hit and return true
	bool hasShip(int x, int y);
	// this function tries to hit a cell, if there was a ship in the cell it will mark it as hit and return true
	bool hit(int x, int y);
	// This function tests if a cell is capable of placing a ship
	bool checkElement(int x, int y);
	// This function tests if all the ships on the grid were hit 
	bool checkIfAllHit();
	//This function maps all ships to the grid.
	void mapShips();


//TODO: make private
protected: //TODO: make private
	//Ship* grid[10][10] = {};
	char grid[10][10] = {};
	Ship** ships;
	void clearGrid();
};

