/*
File created by Lizaveta Tarasova on 6/29/2022 as part of the Capstone project for CSC 161
*/

#include <iostream>

#include "Ship.h"

using namespace std;

// This constructor creates a ship based on the provided length of the ship (size) its orientation (isVertical) and (x) and (y) positions
Ship::Ship(int size, bool isVertical, bool isPlaced, int x, int y)
{
	shipSize = size;
	this->isVertical=isVertical;
	this->isPlaced = isPlaced;
	xPosition=x;
	yPosition=y;
}

Ship::Ship(int size, bool isVertical, int x, int y):Ship(size, isVertical, false, x, y )
{

}

Ship::~Ship(){}

//This function sets the value of the state of the ship (true if the state is placed)
void Ship::setIsPlaced(bool isPlaced)
{
	this->isPlaced = isPlaced;
}

//This function does not let the ship move out of bounds of the grid
void Ship::forceShipInBounds() 
{
	if (xPosition < 0) xPosition = 0;
	if (yPosition < 0) yPosition = 0;
	int endX = xPosition;
	int endY = yPosition;
	if (isVertical) endX += shipSize - 1;
	else endY += shipSize - 1;
	if (endX > 9) xPosition += 9 - endX;
	if (endY > 9) yPosition += 9 - endY;
}

//This function sets the value of y coordinate of the start of the ship
void Ship::setYPosition(int y)
{
	yPosition = y;
}

//This function sets the value of x coordinate of the start of the ship
void Ship::setXPosition(int x)
{
	xPosition = x;
}

//This function sets the value of ship size
void Ship::setShipSize(int size)
{
	shipSize = size;
}

//This function sets the value of the orientation of the ship (true if the orientation is vertical)
void Ship::setIsVertical(bool isVertical)
{
	this->isVertical = isVertical;
}

// This function returns the x coordinate of the start of the ship
int Ship::getXPosition()
{
	return xPosition;
}

// This function returns the y coordinate of the start of the ship
int Ship::getYPosition()
{
	return yPosition;
}

// This function returns the ship length
int Ship::getShipSize()
{
	return shipSize;
}

// This function returns true only if the ship is positioned vertically
bool Ship::getIsVertical()
{
	return isVertical;
}

// This function returns true only if the ship is placed
bool Ship::getIsPlaced()
{
	return isPlaced;
}