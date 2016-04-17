#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct Planet
{
private :
	string name;
	double distance;
	double diameter;
	double mass;
public:
	
	double getDistance()
	{
		return distance;
	}
	double getDiameter()
	{
		return diameter;
	}
	double getMass()
	{
		return mass;
	}
	void read()
	{
		cout << "name:";
		cin >> name;
		cout << " distance:" ;
		cin >> distance;
		cout << " diameter:" ;
		cin >> diameter;
		cout << " mass:";
		cin >> mass;

	}
	void print()
	{
		cout << "name:" << name << endl;
		cout << " distance:" << distance << endl;
		cout << " diameter:" << diameter << endl;
		cout << " mass:" << mass << endl;
	}
	double timeSec()
	{
		const int C = 299792;
		double sec;
		sec = distance / C;
		return sec;


	}
};
int main()
{
	Planet planets[3];
	for (int i = 0; i < 3; i++)
	{
		planets[i].read();
	}
	for (int i = 0; i < 3; i++)
	{
		planets[i].print();
	}
	double PlanetMaxDiameter;
	double PlanetMinMass;
	double PlanetLast;
	PlanetMaxDiameter = planets[0].getDiameter();
	PlanetMinMass = planets[0].getMass();
	PlanetLast = planets[0].timeSec();
		for (int i = 0; i <3 ; i++)
		{
			if (PlanetMaxDiameter < planets[i].getDiameter())
			{
				PlanetMaxDiameter = planets[i].getDiameter();
			}
			if (PlanetMinMass > planets[i].getMass())
			{
				PlanetMinMass = planets[i].getMass();
			}
			if (PlanetLast < planets[i].timeSec())
			{
				PlanetLast = planets[i].timeSec();
			}
		}
	cout << "Biggest Planet: " << PlanetMaxDiameter << endl;
	cout << "Smallest Mass: " << PlanetMinMass << endl;
	cout << "Last Planet:" << PlanetLast << endl;
	system("pause");
	return 0;
}
//40 pts