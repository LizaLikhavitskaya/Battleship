/*
File created by Lizaveta Tarasova on 6/30/2022 as part of the Capstone project for CSC 161
*/

#pragma once
#include <iostream>
#include "Grid.h"

using namespace std;

//class that will be used by the user to edit a grid configuration and place ships on the grid
class GridEditor :public Grid
{
public:
	//places a ship of the provided length (s)
	void placeShip(int s);
	//shoots at the user's grid at the provided coordinates (x, y)
	void shootTheUser(int x, int y);
	//updates the grid (prints with all new changes)
	void updateGrid();
	//checks if the ship was hit
	bool checkHit(int x, int y);
	//checks if all the ships on the grid were hit
	bool IfAllHit();
private:
	int numShips = 0;
};