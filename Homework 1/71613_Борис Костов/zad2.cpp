#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int C = 299792;

struct Planet {
	string name;
	double distance;
	double diameter;
	double mass;

	void read() {
		cout << "Type the name: ";
		cin >> name;
		cout << "Type the distance: ";
		cin >> distance;
		cout << "Type the diameter: ";
		cin >> diameter;
		cout << "Type the mass: ";
		cin >> mass;
	}

	void print() {
		cout << "(" << name << ", " << distance 
			<< "," << diameter
			<< ", " << mass << ") " << endl;
	}

	double toSeconds() {
		return distance / C;
	}
};


int main()
{
	Planet planets[50];
	int counter;
	cout << "Type the number: ";
	cin >> counter;

	for (int i = 0; i < counter; i++)
	{
		planets[i].read();
	}

	for (int i = 0; i < counter; i++)
	{
		planets[i].print();
	}

	string PlD; 
	double maxDiameter = planets[0].diameter;
	for (int m = 1; m < counter; m++)
	{
		if (planets[m].diameter > planets[0].diameter)
			maxDiameter = planets[m].diameter;
		PlD = planets[m].name;
	}
	cout << "Max diameter: " << PlD << endl;

	string PlM;
	double minMass = planets[0].mass;
	for (int k = 1; k < counter; k++)
	{
		if (planets[k].mass < planets[0].mass)
			minMass = planets[k].mass;
		PlM = planets[k].name;
	}
	cout << "Min mass: " << PlM << endl;

	string PlLight;
	double minLight = planets[0].toSeconds();
	for (int n = 1; n < counter; n++)
	{
		if (planets[n].toSeconds() > planets[0].toSeconds())
			minLight = planets[n].toSeconds();
		PlLight = planets[n].name;
	}
	cout << "The last planet: " << PlLight << endl;


	system("PAUSE");
	return 0;
}
//40 pts