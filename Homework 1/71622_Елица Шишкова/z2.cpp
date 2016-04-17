#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const double C = 299792;
struct Planet {
private:
	string name;
    double distance;
	double diameter; 
	double mass;
public:
	void read();
	void print();
	double secondsLightPlanetToSun();
	double getDiameter();
	double getMass();
	string getName();

};

void Planet::read()
{
	cout << "Name:"; 
	cin >> name;
	cout << "Distance to Sun:";
	cin >> distance;
	cout << "Diameter:";
	cin >> diameter;
	cout << "Mass:";
	cin >> mass;

};
void Planet::print(){
	cout << "Name:" << name << "   " << "Distance to Sun:" << setprecision(15) <<distance 
		<< "   " << "Diameter:" << setprecision (15) << diameter << "   " << "Mass:" << setprecision (15) << mass << endl;
}
double Planet::secondsLightPlanetToSun()
{
	return distance/C;
}
double Planet::getDiameter()
{
	return diameter;
}
double Planet::getMass()
{
	return mass;
}
string Planet::getName()
{
	return name;
}
int main()
{
	int n;
	do{
		cout << "Enter number of planets between 1 and 8:";
		cin >> n;
	} while (n<1 || n>8);
	Planet allPlanets[8];
	for (int i = 0; i < n; i++)
	{
		allPlanets[i].read();
	}
	for (int i = 0; i < n; i++)
	{
		allPlanets[i].print();
	}
	double largestDiameter = allPlanets[0].getDiameter();
	string largestDiameterName = allPlanets[0].getName();
	double smallestMass = allPlanets[0].getDiameter();
	string smallestMassName = allPlanets[0].getName();
	double slowDistSun = allPlanets[0].secondsLightPlanetToSun();
	string slowDistSunName = allPlanets[0].getName();
	for (int i = 0; i < n; i++)
	{
		if (allPlanets[i].getDiameter() > largestDiameter) {
			largestDiameter = allPlanets[i].getDiameter();
			largestDiameterName = allPlanets[i].getName();
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (allPlanets[i].getMass() < smallestMass)
		{
			smallestMass = allPlanets[i].getMass();
			smallestMassName = allPlanets[i].getName();
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (allPlanets[i].secondsLightPlanetToSun() > slowDistSun)
		{
			slowDistSun = allPlanets[i].secondsLightPlanetToSun();
			slowDistSunName = allPlanets[i].getName();
		}
	}
	cout << "Planet with largest diameter:"<< largestDiameterName << " - " << largestDiameter << endl;
	cout << "Smallest mass:" << smallestMassName << " - " << smallestMass << endl;
	cout << "The planet that will have light last: " << slowDistSunName << " - " << slowDistSun << endl;
	system("Pause"); 
	return 0;
}

// 40 pts