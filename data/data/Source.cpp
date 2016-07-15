#include <iostream>;
#include <string>;
#include <array>;
using namespace std;

class user {
public:
	string name, food;
	float shoe;
	user(string nameIn, string foodIn, float shoeIn) {
		name = nameIn;
		food = foodIn;
		shoe = shoeIn;
	};
};

user cliffhanger = user("cliffhanger", "watermelon", 8.5);
user krabs = user("krabs", "noodles", 9.5);
user kitkat = user("kitkat", "cheesecake", 8);
user zazu = user("zazu", "orange", 11);
user apollo = user("apollo", "pepperoini pizza", 11.5);
user seven = user("7", "creme burlee", 12);
user glados = user("glados", "pasta", 8.5);
user brain = user("the brain", "steak", 9);
user captainA = user("captain america", "watermelon", 10.5);

user *objectList[] = { &cliffhanger, &krabs, &kitkat, &zazu, &apollo, &seven, &glados, &brain, &captainA };

void sql() {
	
}

void main() {
	string name, food;
	float shoe;
	for (int i = 0; i <= 8; i++) {
		name = objectList[i]->name;
		food = objectList[i]->food;
		shoe = objectList[i]->shoe;
		cout << "name: " + name + "\nfood: " + food + "\nshoe: " << shoe << endl << endl;
	}

	
	while(1){}
}