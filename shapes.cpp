// Author:			Joshua Alexander
// Source file:		shapes.cpp
// Description:		Project 3 Shapes
// IDE used:	    Visual Studio 2015

#include <iostream>
#include <cmath>
using namespace std;

int displayMenu();
int getWidth();
void displaySquare(int);
void displayTriangle(int);
void displayUpsideDownTriangle(int);
void displayDiamond(int);

int main()
{
	int selection, width;

	do
	{
		selection = displayMenu();

		switch (selection)
		{
		case 1:
			displaySquare(getWidth());
			break;
		case 2:
			displayTriangle(getWidth());
			break;
		case 3:
			displayUpsideDownTriangle(getWidth());
			break;
		case 4:
			width = getWidth();
			displayTriangle(width);
			displayUpsideDownTriangle(width);
			break;
		case -9:
			cout << "\n   End of Program.\n";
			break;
		default:
			cout << "\n   Invalid Selection.\n\n";
			break;
		}
	} while (selection != -9);
	
	system("pause");
	return 0;
}

int displayMenu()
{
	int sel;

	cout << "\n   Shape Display Menu\n"
		<< "\n     1....Square"
		<< "\n     2....Triangle"
		<< "\n     3....Upside Down Triangle"
		<< "\n     4....Diamond"
		<< "\n    -9....Exit Program"
		<< "\n\n    Make a selection:  ";

	cin >> sel;

	return sel;
}

int getWidth()
{
	int width;
	do
	{
		cout << "    Enter Width: ";
		cin >> width;

		if (width % 2 == 0)
			cout << "\n   Width must be an odd number.\n";

	} while (width % 2 == 0);

	return width;
}

void displaySquare(int width)
{
	int height = width;

	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << " #"; // spaces make output easier to see as a square
		cout << endl;
	}
}

void displayTriangle(int width)
{
	int height = ceil(double(width) / 2), ctr = 1;

	for (int i = 1; i <= height; i++)
	{
		for (int j = height; j >= i; j--)
			cout << " ";

		for (int k = 0; k < ctr; k++)
			cout << "#";

		cout << endl;
		ctr += 2;
	}
}

void displayUpsideDownTriangle(int width)
{
	int height = ceil(double(width) / 2), ctr = width;

	for (int i = 1; i <= height; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " ";

		for (int k = 0; k < ctr; k++)
			cout << "#";

		cout << endl;
		ctr -= 2;
	}
}

void displayDiamond(int x)
{
	cout << endl;
	displayTriangle(x);
	displayUpsideDownTriangle(x);
}