#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// imah problem s enum yn {yes, no}; ?

struct Fruit {
	char name[32];
	string color;
	bool annual;
	bool perennial;
	bool tropical;


	void input() { 
		cout << "Enter fruit's name: ";
		cin >> name;
		cout << "Enter fruit's color: ";
		cin >> color;
		cout << "1 for Yes, 0 for No :" << endl;
		cout << "Is the fruit annual? : ";
		cin >> annual;
		cout << "Is the fruit perennial? : ";
		cin >> perennial;
		cout << "Is the fruit tropical? : ";
		cin >> tropical;
	}

	void print() { 
		cout << " (" << name << ", " << color <<
			", " << annual << ", " << perennial <<
			", " << tropical << ") " << endl;
	}
};

	void inputFruits(Fruit fruits[], int n) { 
		for (int i = 0; i < n; i++) {
			fruits[i].input();
		}
	}

	void printFruits(Fruit fruits[], int n) { 
		for (int i = 0; i < n; i++) {
			fruits[i].print();
		}
	}

	int numberOfAnnualBronwFruits(Fruit fruits[], int n) {
		int numberOfAnnualBrown = 0;
		for (int i = 0; i < n; i++) {
			if (fruits[i].annual == true && fruits[i].color == "brown")
				numberOfAnnualBrown++;
		}
			return numberOfAnnualBrown;
		
	}

	int numberOfPerennialTropicalFruits(Fruit fruits[], int n) { 
		int numberOfPerennialTropical = 0;
		for (int i = 0; i < n; i++) {
			if (fruits[i].tropical == true && fruits[i].perennial == true)
				numberOfPerennialTropical++;
		}
		    return numberOfPerennialTropical;
	}

	void printAnnualBrown(Fruit fruits[], int n) {
		for (int i = 0; i < n; i++) {
			if (fruits[i].annual == true && fruits[i].color == "brown")
				fruits[i].print();
		}
	}

	void printPerennialTropical(Fruit fruits[], int n) {
		for (int i = 0; i < n; i++) {
			if (fruits[i].perennial == true && fruits[i].tropical == true)
				fruits[i].print();
		}
	}

int main()
{
	system("PAUSE");
	return 0;
}

// 35 pts