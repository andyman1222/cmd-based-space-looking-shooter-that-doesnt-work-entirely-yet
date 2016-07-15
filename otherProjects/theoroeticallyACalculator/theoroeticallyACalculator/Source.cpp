using namespace std;
#include <iostream>;
#include <string>;
#include <math.h>;
#include <cstdlib>
#include <ctime>;


void main() {
	system("cls");
	cout << "what is the initial price? $";
	float price;
	cin >> price;
	cin.ignore(1000, '\n');
	cout << "How much tip? %";
	float tip;
	cin >> tip;
	cin.ignore(1000, '\n');
	srand(time(NULL));
	float salesTax = (rand()%100);
	cout << "Today the sales tax is " << salesTax << "%." << endl;
	float total = price + (tip * price * .01) + (salesTax * price * .01);
	cout << "Your final total is $" << total << "!";
}