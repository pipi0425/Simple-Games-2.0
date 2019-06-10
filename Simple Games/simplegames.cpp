#include <iostream>
#include <conio.h>

#include "start.h"
#include "cursor.h"

using namespace std;

int main(int argc, char * argv[]) {
	int checkquit = 0;
	int checkstart = 0;
	Start newstart;
	newstart.display();
	while (checkquit != 1 && checkstart != 1) {
		while (_kbhit() != 0) {
			char ch = _getch();
			if (ch == 'w' || ch == 'W') {		//up
				newstart.choose(-1);
				newstart.display();
			}
			else if (ch == 's' || ch == 'S') {	//down
				newstart.choose(1);
				newstart.display();
			}
			else if (ch == 13 || ch == ' ') {	//enter or space
				if (newstart.choice == 5) {		//quit
					checkquit = 1;
					break;
				}
				else if (newstart.choice == 4) {//about
					newstart.displayabout();
				}
				else {							//difficulty
					checkstart = newstart.displaydifficulty();
				}
			}
		}
	}
	if (checkquit == 1) {
		cls();
		return 0;
	}
	else if (checkstart == 1) {
		cls();
		cout << "Starting Game " << newstart.choice << " with difficulty " << newstart.difficulty;
		return 0;
	}
	
}