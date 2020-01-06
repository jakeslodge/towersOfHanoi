#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
const int numberOfDisks = 3;
const int towerHeight = 3;
const int numberOfTowers = 3;
int disk[numberOfDisks] = { 1,2,3 }; //default 10,20,30
int board[numberOfTowers][numberOfDisks] =
{

	{ disk[0],0,0 },
{ disk[1],0,0 },
{ disk[2],0,0 },

};

void gameSetup()
{
	const int numberOfDisks = 3;
	const int towerHeight = 3;
	const int numberOfTowers = 3;

	int towers[numberOfTowers];
	towers[0] = 0;
	towers[1] = 1;
	towers[2] = 2;
	int poles[towerHeight];
	poles[0] = 0;
	poles[1] = 1;
	poles[2] = 2;
}

void printBoard()
{
	int column = 0;
	cout << endl;
	while (column < 3)
	{
		// testing display array
		for (int row = 0; row < 3; row++)
		{
			cout << board[column][row] << "   ";
		}
		cout << endl;
		column++;
	}



}

int pickupSelectFnc()
{
	int selection = 0;
	cout << "Please Select a tower to move from: 0, 1, 2." << endl;
	cin >> selection;
	return selection;
}

int dropSelectFnc()
{
	int selection = 0;
	cout << "Where would you like to place it: 0, 1, 2." << endl;
	cin >> selection;
	return selection;
}

int pickupCheck(int passedIn)
{
	//cout << disk[2] << endl;
	int testColumn = passedIn; //int that is passed is given to this column

	int count = 0; //counter starts at 2 (3 - 1)
	for (board[count][testColumn]; count < 3; count++) // scans top down through currently selected column
	{
		//cout << count << " "<< testColumn << endl;

		//cout << board[count][testColumn] << "    "<< endl;
		if (board[count][testColumn] != 0)
		{
			return count;
		}

	}

}

int getPickupVal(int a, int b)
{
	int column = a;
	int row = b;
	return board[row][column];
}

int dropScan(int a)
{
	int column = a;
	int count = 2;

	for (board[count][column]; count >= -1; count--)
	{
		//cout << endl << count << " " << column << "  "<< board[count][column];
		if (board[count][column] == 0)
		{
			return count;
		}
	}
	return 666;
}

void moveData(int pickCol, int pickRow, int pickVal, int dropCol, int dropRow)
{
	// will change the value of the empty space;
	board[pickRow][pickCol] = 0;

	board[dropRow][dropCol] = pickVal;

}

bool checkWin()
{
	if (board[0][2] == 1 && board[1][2] == 2 && board[2][2] == 3)
	{
		cout << "Winner, Winner Chicken Dinner";
		return true;
	}
	else {
		return false;
	}
}









int main()
{
	int pickupSelect = 0;
	int dropSelect = 0;
	int dropRow = 0;

	int pickupValue = 0;
	int pickupLocation = 0;

	bool winCheck = false;

	gameSetup();

	cout << "Welcome to my towers of hanoi" << endl;
	while (winCheck == false)
	{

		printBoard();

		pickupSelect = pickupSelectFnc(); // gets the column which the user wants to take from.
		pickupLocation = pickupCheck(pickupSelect); // take the column and sees where values that does not equal 0.
		pickupValue = getPickupVal(pickupSelect, pickupLocation); // goes to that adress and finds out the value there.


		dropSelect = dropSelectFnc(); // asks for where to place it.
									  //cout << endl << dropSelect;

									  //checks if there is an empty slot, if so will return where.
		dropRow = dropScan(dropSelect);

		//outputs where values have been found and will be taken to
		//cout << endl << "At column " << pickupSelect << " position " << pickupLocation << " has found the value " << pickupValue << endl;

		//cout << endl << "At column " << dropSelect << " there is a free slot at position " << dropRow << endl;


		if (board[dropRow + 1][dropSelect] == 0) {
			moveData(pickupSelect, pickupLocation, pickupValue, dropSelect, dropRow);
		}
		else if (board[dropRow + 1][dropSelect] > pickupValue) {
			moveData(pickupSelect, pickupLocation, pickupValue, dropSelect, dropRow);
		}
		else {
			std::cout << "Invalid Move\n";
		}

		winCheck = checkWin();

		//system("CLS");
	}

	string x;
	std::cin >> x;


}