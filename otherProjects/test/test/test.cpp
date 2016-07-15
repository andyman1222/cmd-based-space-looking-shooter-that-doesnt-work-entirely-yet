using namespace std;
#include <iostream>;
#include <string>;
#include <time.h>;

int i, x, space;
void pyramid(int levels) {

	for (i = 1; i <= levels * 2; i += 2) {
		int spaceLoopValue = levels - (i / 2);
		for (space = 1; space <= ceil(spaceLoopValue); space++) {
			cout << " ";
		}
		for (x = 0; x != i; x++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}
void square(int levels) {
	for (i = 1; i <= levels; i++) {
		for (x = 1; x <= levels; x++) {
			cout << "* ";
		}
		cout << endl;
	}
}
void input() {
	string stuff;
	cout << "type something" << endl;
	cin >> stuff;
	cout << stuff;
}

void main() {
	pyramid(3);
	square(10);
	input();
	
	
}
