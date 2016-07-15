#include <iostream>;
using namespace std;
#include <string>;
#include <math.h>;
#include <cstdlib>
#include <ctime>;

long double a, b, c, *variable;
long double *values[] = { &a, &b, &c };

void changeValue(long double *value) {
	*value = *value * 2;
}

void main() {
	a = 1;
	while (true) {
		srand(time(NULL));
		changeValue(values[round(rand() % 2)]);
		cout << a << endl << b << endl << c << endl;
	}
}