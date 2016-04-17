#include <iostream>
#include <cstring>

using namespace std;
struct Planet
{
	char name[32];
	double distance;
	double diameter;
	double mass;
public:
	Planet(const char* _name = "", double _distance = 0, double _diameter = 0, double _mass = 0)
	{
		strcpy_s(name, _name);
		distance = _distance;
		diameter = _diameter;
		mass = _mass;
	}
	//you don't need a constructor, that's what read is used for
	void read() {
		cout << "Name of the planet: ";
		cin >> name;
		cout << "Distance from the sun: ";
		cin >> distance;
		cout << "Diameter of the planet: ";
		cin >> diameter;
		cout << "Mass of the planet: ";
		cin >> mass;
		cout << endl;
	}
	void print() {
		cout << "Planet " << name << " has: " << endl;
		cout << distance << "km distance from the sun, " << endl;
		cout << diameter << "km diameter and " << endl;
		cout << mass << "tones mass." << endl;
	}

	double lightFromTheSun(int C)
	{
		return distance / C;
	}
};

void readArr(Planet* p, int br)
{
	//i should be in the range [0,n), not [1,n], same for printArr - -0.2 
	for (int i = 1; i <= br; i++){
		p[i].read();
	}
}
void printArr(Planet* p, int br)
{
	for (int i = 1; i <= br; i++){
		p[i].print();
	}
}

void maxDiameter(Planet* p, int br)
{
	int k = 0;
	double max = p[0].diameter;
	for (int i = 0; i < br; i++)
	{
		if (p[i].diameter > max)
		{
			max = p[i].diameter;
			k = i;
		}
	}
	cout << p[k].name;
	cout << max;
}

void minMass(Planet* p, int br)
{
	int k = 0;
	double min = p[0].diameter;
	for (int i = 0; i < br; i++)
	{
		if (p[i].diameter < min)
		{
			min = p[i].diameter;
			k = i;
		}
	}
	cout << p[k].name;
	cout << min;
}

void timeToTravelFromTheSun(Planet* p, int br, int C)
{
	int k = 0;
	double maxTravelTime = 0;
	for (int i = 0; i<br; i++)
	{
		if (p[i].lightFromTheSun(C)>maxTravelTime)
		{
			maxTravelTime = p[i].lightFromTheSun(C);
			k = i;
		}
	}
	cout << p[k].name << " - ";
	cout << maxTravelTime;
}
int main()
{
	const int C = 299792;
	Planet earth;
	earth.read();
	cout << endl;
	earth.print();
	cout << "The light reaches for: " << earth.lightFromTheSun(C) << endl;
	cout << endl;

	int n;
	cout << "Enter number of planets: ";
	cin >> n;
	Planet planet[9]; //your functions won't work for more than 8 planets, you should use some validations - 0.1
	readArr(planet, n);
	cout << endl;
	printArr(planet, n);
	
	cout << "The planet with the biggest diameter is: ";
	maxDiameter(planet, n);
	cout << endl;

	cout << "The planet with the the lightest mass is: ";
	minMass(planet, n);
	cout << endl;

	cout << "The last planet, which the light reaches: ";
	timeToTravelFromTheSun(planet, n, C);
	cout << endl;

	system("pause");
	return 0;
}

// 27/40