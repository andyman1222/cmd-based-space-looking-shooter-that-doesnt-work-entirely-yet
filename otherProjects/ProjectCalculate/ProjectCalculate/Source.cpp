#include <iostream>;
#include <string>;
using namespace std;

class calculator {
public:
	float a, b;
	float loop = a;
	float initValue = b;
	float subtraction() {
		return a - b;
	}
	float addition() {
		return a + b;
	}
	float multiplication() {
		return a * b;
	}
	float exponents() {
		loop = b;
		initValue = a;
		for (int i = 1; i < loop; i++) {
			a = a * initValue;
		}
		return a;
	}
	float factorial() {
		for (float x = 1; x < loop; x++) {
			a = a * x;
			system("cls");
			cout << x << endl;
			cout << a << endl;
		}
		return a;
	}
};

calculator mainCalculator = calculator();

void subtraction() {
	cout << endl << endl << "a-b\n\ntype number a." << endl;
	cin >> mainCalculator.a;
	cout << endl << endl << mainCalculator.a << "-b\n\ntype number b." << endl;
	cin >> mainCalculator.b;
	system("cls");
	cout << endl << endl << "answer is " << mainCalculator.subtraction() << endl << endl;
}

void addition() {
	cout << endl << endl << "a+b\n\ntype number a." << endl;
	cin >> mainCalculator.a;
	cout << endl << endl << mainCalculator.a << "+b\n\ntype number b." << endl;
	cin >> mainCalculator.b;
	system("cls");
	cout << endl << endl << "answer is " << mainCalculator.addition() << endl << endl;
}

void multiplication() {
	cout << endl << endl << "a*b\n\ntype number a." << endl;
	cin >> mainCalculator.a;
	cout << endl << endl << mainCalculator.a << "*b\n\ntype number b." << endl;
	cin >> mainCalculator.b;
	system("cls");
	cout << endl << endl << "answer is " << mainCalculator.addition() << endl << endl;
}

void factorial() {
	cout << endl << endl << "a!\n\ntype number a." << endl;
	cin >> mainCalculator.a;
	system("cls");
	cout << endl << endl << "answer is " << mainCalculator.factorial();
}

void exponents() {
	cout << endl << endl << "a^b\n\ntype number a." << endl;
	cin >> mainCalculator.a;
	cout << endl << endl << mainCalculator.a << "^b\n\ntype number b." << endl;
	cin >> mainCalculator.b;
	system("cls");
	cout << endl << endl << "answer is " << mainCalculator.exponents() << endl << endl;
}

void power2() {
	cout << endl << endl << "2^a\n\ntype number a." << endl;
	cin >> mainCalculator.b;
	mainCalculator.a = 2;
	system("cls");
	cout << endl << endl << "answer is " << mainCalculator.exponents() << endl << endl;
}


void main() {
	while (1) {
		
		cout << "\nType subtraction, addition, power of 2, exponents, multiplication, or factorial to do dat operation."<<endl<<endl;
		string inputt;
		getline(cin, inputt);
		if (inputt == "subtraction") {
			subtraction();
			
		}
		else if (inputt == "factorial") {
			factorial();
			
		}
		else if (inputt == "addition") {
			addition();
		}
		else if (inputt == "power of 2") {
			power2();
		}
		else if (inputt == "exponents") {
			exponents();
		}
		else if (inputt == "multiplication") {
			multiplication();
		}
	}
}

