/*
File created by Lizaveta Tarasova on 6/24/2022 as part of the Capstone project for CSC 161
*/

#include <iostream>
#include <string>
#include "Game.h"
#include "Grid.h"
#include "Ship.h"
#include "Player.h"
#include "Robot.h"
#include "estd/AnsiEscape.hpp"
#include "GridEditor.h"
#include "GridGenerator.h"
#include <ctime> 
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    cout << estd::resizeWindow(101,30);
	cout << estd::moveCursor(0, 0);
	cout << estd::clearAfterCursor;
	GridEditor editor;
	GridGenerator generator;
	//cteates objects of classes Game, Player, and Robot
	//and variables to store the coordinates to shoot
	Game g;
	Player p;
	int xp = 0, yp = 0;
	Robot r;
	int xr, yr;

	//creates variables to store whose turn it is to shoot
	bool userTurn = true;
	bool robotTurn = false;

	//asks the name of the user and cleans the screen
	p.askName();
	cout << estd::moveCursor(0, 0);
	cout << estd::clearAfterCursor;
	cin.ignore();

	string choice;
	cout << "Please, choose the mode to play: " << endl;
	cout << "1. Administrator (will show the robot's ships)" << endl;
	cout << "2. Player (regular game)" << endl;
	while (choice != "1" || choice != "2") { //Iteration until the user inputs the valid value
		getline(cin, choice);
		if (choice == "1")
			generator.setIsPlayer(false);
		else if (choice == "2")
			generator.setIsPlayer(true);
		else cout << "Invalid input. Please, try again" << endl;
		if (choice == "1" || choice == "2")
			break;
	}

	cout << estd::moveCursor(0, 0);
	cout << estd::clearAfterCursor;

	srand(time(0));

	//prints the rules of the game
	cout << estd::moveCursor(2, 15);
	g.printRules();
	
	//randomly places robot's ships and then lets the user to place his ships

	generator.placeShipsRandomly();

	editor.placeShip(4);
	editor.placeShip(3);
	editor.placeShip(3);
	editor.placeShip(2);
	editor.placeShip(2);
	editor.placeShip(2);
	editor.placeShip(1);
	editor.placeShip(1);
	editor.placeShip(1);
	editor.placeShip(1);

	cout << estd::moveCursor(2, 15);
	cout << estd::clearAfterCursor;
	//cin.ignore();

	//while not all user's or robot's ships are hit alternates between user's and robot's moves
	//asks the user to input coordinates, and prints an appropriate message if the input is ivalid
	//lets the robot to shoot randomly
	//stores the coordinates that had already been shooted and does not let to shoot at them one more time
	while (!(generator.IfAllHit()) && !(editor.IfAllHit()))
	{
		while (userTurn)
		{
			cout << estd::moveCursor(2, 15);
			cout << estd::clearAfterCursor;
			do
			{
				while (true) {
					try {
						p.askCoordinates(xp, yp);
						break;
					}
					catch (int i)
					{
						cout << estd::moveCursor(2, 15);
						cout << estd::clearAfterCursor;
						if (i == 1) cout << "Invalid input. Please enter only 1 number and 1 letter." << endl;
						if (i == 2) cout << "Invalid input. Please enter number from 0 to 9." << endl;
						if (i == 3) cout << "Invalid input. Please enter letter from A to J." << endl;
					}
				}
				cout << estd::moveCursor(2, 15);
				cout << estd::clearAfterCursor;
				this_thread::sleep_for(chrono::milliseconds(500));
			} while (p.isRepeat(xp, yp));

			if (!generator.checkHit(xp, yp))
			{
				userTurn = false;
				robotTurn = true;
			}
			generator.shootTheRobot(xp, yp);
			p.addToRepeat(xp, yp);
			generator.updateGrid();
			if (generator.IfAllHit()) break;
		}

		while (robotTurn)
		{
			this_thread::sleep_for(chrono::milliseconds(500));
			do
			{
				xr = r.generateXCoordinate();
				yr = r.generateYCoordinate();
			} while (r.isRepeat(xr, yr));

			if (!editor.checkHit(xr, yr))
			{
				robotTurn = false;
				userTurn = true;

			}
			editor.shootTheUser(xr, yr);
			r.addToRepeat(xr, yr);
			editor.updateGrid();
			if (editor.IfAllHit()) break;
		}
	}

	//prints the winner depending on who sunk all the opponent's ships
	cout << estd::moveCursor(2, 15);
	if (editor.IfAllHit())
	g.printWinner("Robot");
	else g.printWinner(p.getName());
	return 0;
}

