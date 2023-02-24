/*
File created by Lizaveta Tarasova on 6/24/2022 as part of the Capstone project for CSC 161
*/

#pragma once
#include <iostream>

using namespace std;

// This class will contain the logic for the oponent of the human player
class Robot
{
public:
	//ranmdomly generates the x coordinate to shoot
	int generateXCoordinate();
	//ranmdomly generates the y coordinate to shoot
	int generateYCoordinate();
	//updates the array, adding the coordinates that had already been shooted
	void addToRepeat(int x, int y);
	//checks if the coordinates had already been shooted
	bool isRepeat(int x, int y);

	Robot();
	~Robot();

private:
	//array to store which coordinates had already been shooted
	int repeatArr[10][10] = {};
};
