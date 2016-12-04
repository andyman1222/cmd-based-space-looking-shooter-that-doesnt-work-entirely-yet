#include <iostream>;
#include <string>;
#include <Windows.h>;
#include <thread>;
#include <ctime>;
#include <math.h>;
#include <cstdlib>;
using namespace std;

//constant functions

thread outputThread, cutscene, mainMenuThread, devThread, playListenThread;

void closeProgram() {
	outputThread.detach();
	cutscene.detach();
	mainMenuThread.detach();
	devThread.detach();
	playListenThread.detach();
	printf("close terminal window now!");
	system("exit");
	terminate();
	exit(0);
}

int listen() {
	try {
		int i;
		for (i = 0; i <= 1000; i++) {
			if (GetAsyncKeyState(i))
			{
				return i;
			}
		}
		if (i == 1001) {
			return NULL;
		}
	}
	catch (exception e) {

	}
}

string lines[30];

int sleepTime = 100;

void printScreen() {
	try {
		
		while (1) {
			for (int i = 0; i <= 29; i++) {
				string currentLine = lines[i];
				printf(currentLine.c_str());
				printf("\n");
			}
			Sleep(sleepTime);
			system("cls");
		}
	}
	catch (exception e) {
		
	}
}

void clearScreen() {
	for (int i = 0; i <= 29; i++) {
		lines[i] = "";
	}
}

int windowLength = 120;

//key actions
bool cutScene = true;
void skipCutScene() {
	Sleep(2000);
	while (cutScene) {
		if (listen() != NULL) {
			cutScene = false;
		}
	}
}

bool devMode = 0;
void dev() {
	try {
		while (1) {
			if (devMode) {
				cout << listen();
			}
		}
	}
	catch (exception e) {

	}
}
bool playing = false;
bool menu = false;
void menuButtons() {
	try {
		while (menu) {
			if (listen() == 50) {
				menu = false;
				closeProgram();
			}
			else if (listen() == 49) {
				menu = false;
				playing = true;
			}
			else if (listen() == 51) {
				if (devMode) {
					devMode = 0;
				}
				else {
					devMode = 1;
				}
				Sleep(100);

			}
		}
	}
	catch (exception e) {

	}
}

//gameplay elements

int playerx, playery;

void playerRender() {
	while (playing) {
		string playerLocation = "";
		for (int i = 1; i <= playerx; i++) {
			playerLocation.append(" ");
		}
		playerLocation.append("|.|");
		lines[29] = playerLocation;
	}
}

void playListener() {
	playerx = 1;
	while (playing) {
		Sleep(10);
		if ((listen() == 65 || listen() == 37) && playerx >= 1) {
			playerx--;
		}
		else if ((listen() == 68 || listen() == 39) && playerx < 116) {
			playerx++;
		}
	}
}

int mobX[100] = {7};
int mobY[100] = {1};
int directionToMove[100] = {1};
int allMobsALength = 0;
int currentSpot = 0;

//mob class- moves mob and stores data
void move() {
	srand(time(NULL));
	directionToMove[currentSpot] = rand() % 4;
	//if (directionToMove[currentSpot] == 1) {
	//	mobX[currentSpot]++;
	//}
	//else if (directionToMove[currentSpot] == 2) {
	//	mobX[currentSpot]--;
	//}
	//else if (directionToMove[currentSpot] == 3) {
		mobY[currentSpot]++;
	//}
	if (mobY[currentSpot] > 28) {
		mobY[currentSpot] = 1;
	}
	if (mobX[currentSpot] > 116) {
		mobX[currentSpot] = 1;
	}
	if (mobX[currentSpot] < 1) {
		mobX[currentSpot] = 116;
	}
}


//method of creating new mobs easily

//replace value for lines[]
string mobLines[28];

void newMob() {
	allMobsALength++;
	srand(time(NULL));
	mobX[allMobsALength] = rand() % 100;
	mobY[allMobsALength] = 1;
	directionToMove[allMobsALength] = 1;
}

//generate, move mobs
//note: sudo random doesnt random
int yValueOutput = 0;
int xValueOutput = 0;
bool willGenerateMob = 0;
void moveAndRenderMobs() {
	while (playing) {
		for (currentSpot = 0; currentSpot <= allMobsALength; currentSpot++)
		{
			move();
		}

		//sort mobs by x value so appending to lines is easy
		int temp;
		for (int i = 0; i < allMobsALength && allMobsALength != 0; i++)
		{
			for (int j = 1; j < allMobsALength - 1; j++)
			{
				if (mobX[j] < mobX[i])
				{
					temp = mobX[i];
					mobX[i] = mobX[j];
					mobX[j] = temp;
					temp = mobY[i];
					mobY[i] = mobY[j];
					mobY[j] = temp;
				}
			}
		}
		//code similar to player render except it goes mob-by-mob

		
		for (int i = 0; i <= allMobsALength && allMobsALength != -1; i++) {
			lines[yValueOutput].assign("");
			yValueOutput = mobY[i];
			xValueOutput = mobX[i];
			string currentLine = "";
			for (int j = 1; j <= xValueOutput; j++) {
				currentLine = currentLine + " ";
			}
			currentLine = currentLine + "!=!";
			lines[yValueOutput].assign(currentLine);
		}
		srand(time(NULL));
		//new mob- 40% chance
		//willGenerateMob = rand() % 1;
		//if (willGenerateMob = 1 && allMobsALength <= 3) {
			newMob();
		//}
		Sleep(500);
	}
}





void playGame() {
	playing = true;
	playery = 29;
	while (1) {
		
	}
}
//specify what is drawn

void intro() {
	for (int i = 29; i != 0 && cutScene == true; i--) {
		lines[i-2] = " __    __    _       ___   _     ____ _____  ____  _    _____";
		lines[i-1] = "( (`  / /\\  | |\\ /| | |_) | |   | |_   | |  | |_  \\ \\_/  | |";
		lines[i] = "_)_) /_/--\\ |_|   | |_|   |_|__ |_|__  |_|  |_|__ /_/ \\  |_|";
		lines[i+3] = "press any key to contiue (not mouse buttons)";
		Sleep(500);
		lines[i] = "";
		lines[i+3] = "";
	}
}

void mainMenu() {
	try {
		while (menu) {
			lines[1] = "____ ____ __   ___  ____ __   ____      ___  ___  ___  ____ ___    ____ ___  _    ____ ";
			lines[2] = "| __\\|   || \\|\\| _\\ |   || |  | __\\ ___ | .\\ |  \\ | _\\ | __\\|  \\   |  _\\|  \\ |\\/\\ | __\\";
			lines[3] = "| \\__| . ||  \\|[__ \\| . || |__|  ]_|___\\| .<_| . \\[__ \\|  ]_| . \\  | [ \\| . \\|   \\|  ]_";
			lines[4] = "|___/|___/|/\\_/|___/|___/|___/|___/     |___/|/\\_/|___/|___/|___/  |___/|/\\_/|/v\\/|___/";
			lines[10] = "1- play game                               2- exit                                3- enable developer mode";
		}
	}
	catch (exception e) {

	}
}

//sequence

int main() {
	system("color 0a");
	try {
		thread outputThread(printScreen);
		thread cutscene(skipCutScene);
		intro();
		clearScreen();
		cutscene.detach();


		menu = true;
		thread mainMenuThread(menuButtons);
		thread devThread(dev);
		mainMenu();
		clearScreen();
		menu = false;
		mainMenuThread.detach();
		devThread.detach();

		thread playListenThread(playListener);
		thread mobThread(moveAndRenderMobs);
		thread playRenderThread(playerRender);
		sleepTime = 0;
		playGame();
		//playListenThread.detach();
		
		while (1) {
		}
	}
	catch (exception e) {
		if (!devMode) {
			closeProgram();
			return 0;
		}
	}
}