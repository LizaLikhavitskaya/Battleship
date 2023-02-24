/*
File created by Lizaveta Tarasova on 7/4/2022 as part of the Capstone project for CSC 161
*/

#include <iostream>
#include <string>
#include "Player.h"
#include "estd/AnsiEscape.hpp"

using namespace std;

//converts letter coordinates to number coordinates
int lettersToNumbers(char letter)
{
    switch (letter)
    {
    case 'A': return 0;
    case 'a': return 0;

    case 'B': return 1;
    case 'b': return 1;

    case 'C': return 2;
    case 'c': return 2;

    case 'D': return 3;
    case 'd': return 3;

    case 'E': return 4;
    case 'e': return 4;

    case 'F': return 5;
    case 'f': return 5;

    case 'G': return 6;
    case 'g': return 6;

    case 'H': return 7;
    case 'h': return 7;

    case 'I': return 8;
    case 'i': return 8;
        
    case 'J': return 9;
    case 'j': return 9;
    
    default: return 10;

    }
}

//asks the user to input the coordinates to shoot and checks if they are valid
void Player::askCoordinates(int &x, int &y)
{
	string coordinates;
	cout << "Please, enter the coordinates to shoot (one number from 0 to 9 and one letter from A to J): " << endl;
	getline(cin, coordinates);
	if (coordinates.length() != 2) throw 1;
	char xCoordinate = coordinates[0];
	char yCoordinate = coordinates[1];
	if ((xCoordinate - 48) < 0 || (xCoordinate - 48) > 9) throw 2;
	x = xCoordinate - 48;
	y = lettersToNumbers(yCoordinate);
	if (y == 10) throw 3;
}

	//functions to receieve the player's name
	void Player::askName()
	{
		cout << "Please, enter your name: " << endl;
		cin >> name;
	}

	//returns the user's name
	string Player::getName()
	{
		return name;
	}

	//updates the array, adding the coordinates that had already been shooted
	void Player::addToRepeat(int x, int y)
	{
		repeatArr[x][y] = 1;
	}

	//checks if the coordinates had already been shooted
	bool Player::isRepeat(int x, int y)
	{
		if (repeatArr[x][y] == 1) return true;
		else return false;
	}

	Player::Player()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				repeatArr[i][j] = 0;
			}

		}
	}

	Player::~Player()
	{

	}

