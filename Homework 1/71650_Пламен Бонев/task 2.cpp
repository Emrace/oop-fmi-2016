#include <iostream>
#include <string>

using namespace std;

struct Planet
{
	string name;
	double distance;
	double diameter;
	double mass;

	void read(string _name, double _distance, double _diameter, double _mass)
	{
		name = _name;
		distance = _distance;
		diameter = _diameter;
		mass = _mass;
	}

	void print()
	{
		cout << "Name :" << name << endl << "Distance :" << distance << endl << "Diameter :" << diameter << endl << "Mass :" << mass << endl << endl;
	}

	double lightDistance()
	{
		const int c = 299792;

		return distance / c;
	}
};

	int main()
	{
		Planet test[5];
		test[0].read("Earth", 12313423, 1231123231, 1231574241);
		test[1].read("Venus", 6521436571, 1231238172938, 182379128371);
		test[2].read("Jupiter", 128736128123, 176235761253761, 128976736182);
		test[3].read("Mars", 123123412, 14164357, 9817653421);
		test[4].read("Neptune", 8798712372, 8287341, 987263472);

		for (int i = 0; i < 5; i++)
		{
			test[i].print();
		}

		double maxDiameter = 0;
		for (int i = 0; i < 5; i++)
		{
			if (test[i].diameter > maxDiameter)
				maxDiameter = test[i].diameter;
		}

		double minMass = test[0].mass;
		for (int i = 0; i < 5; i++)
		{
			if (minMass > test[i + 1].mass)
				minMass = test[i].mass;
		}

		double maxLightDistance = 0;
		for (int i = 0; i < 5; i++)
		{
			test[i].lightDistance();
			if (test[i].lightDistance() > maxLightDistance)
				maxLightDistance = test[i].lightDistance();
		}

		cout << "Max diameter: " << maxDiameter << endl;
		cout << "Min mass: " << minMass << endl;
		cout << "Max light distance: " << maxLightDistance << endl;

		system("PAUSE");
		return 0;
	}
//40 pts