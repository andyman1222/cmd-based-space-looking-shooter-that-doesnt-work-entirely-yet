using namespace std;
#include <iostream>;
#include <string>;
#include <time.h>;
#include <fstream>;

void main() {
	cout << "Wats ur naem? ";
	string naem;
	getline(cin, naem);
	int numbero;
	cout << "Input a number. ";
	cin >> numbero;
	cin.ignore(100000, '\n');
	cout << "Ur naem is supposively " << naem << " and you chose numbero " << numbero << ".";
	ofstream filee;
	filee.open("ursupposivenameandnumber.fileextensionftw", fstream::app);
	string stuff = "\nUr naem is supposively " + naem + " and you chose numbero " + to_string(numbero) + ".";
	filee << stuff;
	filee.close();

}