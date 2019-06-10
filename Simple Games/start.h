#define WIDTH 75
#define HEIGHT 25
#define ABOUTW 45
#define ABOUTH 8
#define DIFFW 36
#define DIFFH 3
#define TITLE "resource/title.txt"
#define ABOUT "resource/about.txt"
#define DIFF "resource/difficulty.txt"
class Start {
private:
	char back[HEIGHT][WIDTH] = { 0 };
	char about[ABOUTH][ABOUTW] = { 0 };
	char diff[DIFFH][DIFFW] = { 0 };
	char lselector = { '>' };
	char rselector = { '<' };
public:
	int choice = 0;
	int difficulty = -1;
	int aboutstate = 0;
	int difstate = 0;
	Start();
	void display();
	void choose(int move);
	void displayabout();
	int displaydifficulty();
};