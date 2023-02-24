/*
File created by Lizaveta Tarasova on 7/20/2022 as part of the Capstone project for CSC 161
*/

#include <iostream>
#include "Game.h"

using namespace std;

//The function to print the rules of the game
void Game::printRules()
{
	cout << "*********RULES OF THE GAME: *********" << endl << endl;
	cout << "1) To move ship use ARROW keys, to rotate use the SPACE key, to swith to the next ship use ENTER key." << endl << endl;
	cout << "2) The objective of Battleship is to sink all of the robot's ships before he sinks all of your ships." << endl;
	cout << "3) The rigth board is robot's. You will shoot at this board by inputting the coordinates " << endl << " (first - 1 number, second - 1 letter)" << endl;
	cout << "4) The symbol 'O' means that you missed, the symbol 'X' means that you hit the robot's ship." << endl;
	cout << "5) If you hit the robot's ship, you have one more attempt to shoot." << endl;
	cout << "6) The ships can only be placed vertically or horizontally." << endl;
	cout << "7) No part of a ship may hang off the edge of the board." << endl;
	cout << "8) Ships may not overlap each other. No ships may be placed on another ship." << endl;
	cout << "9) As soon as all of one player's ships have been sunk, the game ends." << endl;
}
//The function to print the winner
void Game::printWinner(string s)
{
	cout << s << " won!" << endl << endl;
}
