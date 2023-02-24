/*
File created by Lizaveta Tarasova on 6/24/2022 as part of the Capstone project for CSC 161
*/

#pragma once
#include <iostream>

using namespace std;

class Ship
{
public:
	// This constructor creates a ship based on the provided length of the ship (size) its orientation (isVertical) and (x) and (y) positions.
	Ship(int size, bool isVertical, bool isPlaced, int x, int y);
	Ship(int size, bool isVertical, int x, int y);
	~Ship();
	// This function returns the x coordinate of the start of the ship
	int getXPosition();
	// This function returns the y coordinate of the start of the ship
	int getYPosition();
	// This function returns the ship length
	int getShipSize();
	// This function returns true only if the ship is positioned vertically
	bool getIsVertical();
	// This function returns true only if the ship is placed
	bool getIsPlaced();
	//This function sets the value of y coordinate of the start of the ship
	void setYPosition(int y);
	//This function sets the value of x coordinate of the start of the ship
	void setXPosition(int x);
	//This function sets the value of ship size
	void setShipSize(int size);
	//This function sets the value of the orientation of the ship (true if the orientation is vertical)
	void setIsVertical(bool isVertical);
	//This function sets the value of the state of the ship (true if the state is placed)
	void setIsPlaced(bool isPlaced);
	//This function does not let the ship move out of bounds of the grid
	void forceShipInBounds();

	

private:
	int shipSize;
	bool isVertical;
	bool isSunk;
	int xPosition; //position of the first cell
	int yPosition; //position of the first cell
	bool isPlaced;
};
