#include <fstream>
#include <iostream>
#include <conio.h>

#include "start.h"
#include "cursor.h"

using namespace std;

Start::Start()
{
	ifstream file1;
	file1.open(TITLE);
	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {
			file1 >> noskipws >> back[row][col];
		}
		char garbage;
		file1 >> garbage;
	}
	file1.close();

	ifstream file2;
	file2.open(ABOUT);
	for (int row = 0; row < ABOUTH; row++) {
		for (int col = 0; col < ABOUTW; col++) {
			file2 >> noskipws >> about[row][col];
		}
		char garbage;
		file2 >> garbage;
	}
	file2.close();

	ifstream file3;
	file3.open(DIFF);
	for (int row = 0; row < DIFFH; row++) {
		for (int col = 0; col < DIFFW; col++) {
			file3 >> noskipws >> diff[row][col];
		}
		char garbage;
		file3 >> garbage;
	}
	file2.close();
}

void Start::display()
{
	goto00();
	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {
			cout << back[row][col];
		}
		cout << endl;
	}
	gotoxy(7, 9 + 2 * choice);
	cout << lselector << lselector;
	gotoxy(16, 9 + 2 * choice);
	cout << rselector << rselector;
	gotoxy(10, 9 + 2 * choice);	//cursor position
}

void Start::choose(int move)
{
	choice = choice + move + 6;
	choice = choice % 6;
}

void Start::displayabout()
{
	if (aboutstate == 0) {
		for (int row = 0; row < ABOUTH; row++) {
			gotoxy(20, 12 + row);
			for (int col = 0; col < ABOUTW; col++) {
				cout << about[row][col];
			}
		}
		aboutstate = 1;
	}
	else {
		display();
		aboutstate = 0;
	}
	
}

//return 1 if choose to start, else 0
int Start::displaydifficulty()
{
	if (difstate == 0) {
		for (int row = 0; row < DIFFH; row++) {
			gotoxy(20, 8 + 2 * choice + row);
			for (int col = 0; col < DIFFW; col++) {
				cout << diff[row][col];
			}
		}
		int checkq = 0;
		int checkstart = 0;
		while (!checkq && !checkstart) {
			while (_kbhit() != 0) {
				char ch = _getch();
				if (ch == 'd' || ch == 'D') {		//right
					difficulty += 1;
					difficulty = difficulty % 3;
					if (difficulty == 0) {
						gotoxy(20, 9 + 2 * choice);
						cout << "| > Easy < / * Normal   / * Hard   |";
						gotoxy(24, 9 + 2 * choice);
					}
					else if (difficulty == 1) {
						gotoxy(20, 9 + 2 * choice);
						cout << "| * Easy   / > Normal < / * Hard   |";
						gotoxy(35, 9 + 2 * choice);
					}
					else {
						gotoxy(20, 9 + 2 * choice);
						cout << "| * Easy   / * Normal   / > Hard < |";
						gotoxy(48, 9 + 2 * choice);
					}
				}
				else if (ch == 'a' || ch == 'A') {	//left
					difficulty += 2;
					difficulty = difficulty % 3;
					if (difficulty == 0) {
						gotoxy(20, 9 + 2 * choice);
						cout << "| > Easy < / * Normal   / * Hard   |";
						gotoxy(24, 9 + 2 * choice);
					}
					else if (difficulty == 1) {
						gotoxy(20, 9 + 2 * choice);
						cout << "| * Easy   / > Normal < / * Hard   |";
						gotoxy(35, 9 + 2 * choice);
					}
					else {
						gotoxy(20, 9 + 2 * choice);
						cout << "| * Easy   / * Normal   / > Hard < |";
						gotoxy(48, 9 + 2 * choice);
					}
				}
				else if (ch == ' ' || ch == 13) {	//space or enter
					checkstart = 1;
					break;
				}
				else if (ch == 27) {				//Esc
					display();
					difstate = 0;
					difficulty = -1;
					checkq = 1;
					break;
				}
			}
		}
		if (checkstart == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		display();
		difstate = 0;
	}
	
}
