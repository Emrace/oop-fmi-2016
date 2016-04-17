#include<iostream>
#include<string>

using namespace std;

const float lightSpeed = 299.792f; //light speed is given as 299 792 km/s, not 299.792 km/s

struct Planet {
private:
	string name;
	double distance, diameter, mass;
public:
	void setName(string _name) {
		name = _name;
	}
	string getName() {
		return name;
	}
	void setDistance(double _distance) {
		distance = _distance;
	}
	double getDistance() {
		return distance;
	}
	void setDiameter(double _diameter) {
		diameter = _diameter;
	}
	double getDiameter() {
		return diameter;
	}
	void setMass(double _mass) {
		mass = _mass;
	}
	double getMass() {
		return mass;
	}
	void read() {
		cin >> name >> distance >> diameter >> mass;
	}
	void print() {
		cout << name << " " << distance << " " << diameter << " " << mass << endl;
	}
	float timeSunPlanet() {
		return distance / lightSpeed;
	}
};

int main()
{
	int numberPlanetBiggestDiameter = 0;
	int numberPlanetSmallestMass = 0;
	int numberPlanetFarthermost = 0;
	int numberPlanets;
	cin >> numberPlanets;
	Planet *planets = new Planet[numberPlanets];
	for (int i = 0; i < numberPlanets; i++)
	{
		planets[i].read();
	}
	for (int i = 0; i < numberPlanets; i++)
	{
		planets[i].print();
	}
	for (int i = 0; i < numberPlanets; i++)
	{
		if (planets[numberPlanetBiggestDiameter].getDiameter()<planets[i].getDiameter()) {
			numberPlanetBiggestDiameter = i;
		}
	}
	cout << "Planet with the biggest diameter is : " << planets[numberPlanetBiggestDiameter].getName() << endl;
	for (int i = 0; i < numberPlanets; i++)
	{
		if (planets[numberPlanetSmallestMass].getMass()>planets[i].getMass()) {
			numberPlanetSmallestMass = i;
		}
	}
	cout << "Planet with the smallest mass is : " << planets[numberPlanetSmallestMass].getName() << endl;
	for (int i = 0; i < numberPlanets; i++)
	{
		if (planets[numberPlanetFarthermost].timeSunPlanet()<planets[i].timeSunPlanet()) {
			numberPlanetFarthermost = i;
		}
	}
	cout << "The farthermost planet from the Sun is: " << planets[numberPlanetFarthermost].getName() << endl;

	system("pause");
	return 0;
	delete[]planets;
}

//40 pts