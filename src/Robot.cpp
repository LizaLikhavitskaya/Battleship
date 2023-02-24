/*
File created by Lizaveta Tarasova on 7/19/2022 as part of the Capstone project for CSC 161
*/

#include <iostream>
#include "estd/AnsiEscape.hpp"
#include "Robot.h"
#include <ctime> 
#include <cstdlib>

using namespace std;

//ranmdomly generates the x coordinate to shoot
int Robot::generateXCoordinate()
{
	int x = rand() % 10;
	return x;
}

//ranmdomly generates the y coordinate to shoot
int Robot::generateYCoordinate()
{
	int y = rand() % 10;
	return y;
}

//updates the array, adding the coordinates that had already been shooted
void Robot::addToRepeat(int x, int y)
{
	repeatArr[x][y] = 1;
}

//checks if the coordinates had already been shooted
bool Robot::isRepeat(int x, int y)
{
	if (repeatArr[x][y] == 1) return true;
	else return false;
}

Robot::Robot()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			repeatArr[i][j] = 0;
		}

	}
}

Robot::~Robot()
{

}
