/*
File created by Lizaveta Tarasova on 6/24/2022 as part of the Capstone project for CSC 161
*/

#pragma once
#include <iostream>

using namespace std;

//This class is not used yet and is not complete
class Player 
{
public:
	//asks the user to input the coordinates to shoot and checks if they are valid
	void askCoordinates(int& x, int& y);
	//asks the user's name
	void askName();
	//returns the user's name
	string getName();
	//updates the array, adding the coordinates that had already been shooted
	void addToRepeat(int x, int y);
	//checks if the coordinates had already been shooted
	bool isRepeat(int x, int y);
	Player();
	~Player();

private:
	//variable to store the user's name
	string name;
	//array to store which coordinates had already been shooted
	int repeatArr[10][10] = {};
};