/*
File created by Lizaveta Tarasova on 7/19/2022 as part of the Capstone project for CSC 161
*/

#pragma once
#include <iostream>
#include "Ship.h"
#include "Grid.h"

using namespace std;

//class that will be used by the robot to edit a grid configuration and place ships on the grid
class GridGenerator :public Grid
{
public:
	//places all the ships randomly
	void placeShipsRandomly();
	//shoots at the robot's grid at the provided coordinates (x, y)
	void shootTheRobot(int x, int y);
	//checks if the ship was hit
	bool checkHit(int x, int y);
	//updates the grid (prints with all new changes)
	void updateGrid();
	//checks if all the ships on the grid were hit
	bool IfAllHit();
	//sets the variable to store the mode
	void setIsPlayer(bool choice);
	// returns the variable to store the mode
	bool getIsPlayer();

private:
	int numShips = 0;
	bool isPlayer = true;
};