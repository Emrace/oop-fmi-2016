#include<iostream>
using namespace std;

const int SPEED_LIGHT = 299792;

struct Planet
{
	char name[32];
	unsigned long long int distance;
	double diameter;
	double mass;
};

void create_planet(Planet &p)
{
	char n[32]; 

	cout << "name on planet: "; cin >> n;
	strcpy(p.name, n);
	cout << "distance to the sun: ";cin >> p.distance;
	cout << "diameter of the planet: "; cin >> p.diameter;
	cout << "mass of the planet: "; cin >> p.mass;
	cout << endl;
}

void print_planet(const Planet& p)
{
	cout << "name on planet: " << p.name << endl;
	cout << "distance to the sun: " << p.distance << endl;
	cout << "diameter of the planet: " << p.diameter << endl;
	cout << "mass of the planet: " << p.mass << endl;
	cout << endl;
}

double max_diameter(int n, Planet d[])
{
	Planet pl;
	for (int i = 0; i <= n-2; i++)
	{
		int k = i;
		//double max = d[i].diameter;
		
		pl = d[i];
		//pl.diameter = d[i].diameter;
		for (int j = i+1; j <= n-1; j++)
		{
			if (d[j].diameter > pl.diameter)
			{
				//pl.diameter = d[j].diameter;
				pl = d[j];
				k = j;
			}
		}
		cout << " name: " << pl.name << endl;
		cout << " diameter: ";
		return pl.diameter;
	}	
}

double min_mass(int n, Planet m[])
{
	Planet pl;
	for (int i = 0; i <= n - 2; i++)
	{
		int k = i;
		pl.mass = m[i].mass;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (m[j].mass < pl.mass)
			{
				pl.mass = m[j].mass;
				//pl = m[j];
				k = j;
			}
		}
		pl = m[k];

		cout <<" name: "<< pl.name <<endl;
		cout <<" mass: ";
		return pl.mass;
	}
}

double speed_of_light(Planet& s)
{
	double speed;
	speed = s.distance / SPEED_LIGHT;
	return speed;
}

Planet max_sun_light(int n, Planet l[])
{
	Planet pl;
	for (int i = 0; i <= n-2; i++)
	{
		int k = i;
		double max = speed_of_light(l[i]);
		for (int j = i+1; j <= n-1; j++)
		{
			if (speed_of_light(l[j]) > max)
			{
				max = speed_of_light(l[j]);
				k = j;
				pl = l[j];
			}
		}		
		return pl;
	}
}

Planet min_sun_light(int n, Planet l[])
{
	Planet pl;
	for (int i = 0; i <= n - 2; i++)
	{
		int k = i;
		double min = speed_of_light(l[i]);
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (speed_of_light(l[j]) < min)
			{
				min = speed_of_light(l[j]);
				k = j;
				pl = l[j];
			}
		}
		return pl;
	}
}

int main()
{
	Planet P[10];
	Planet planeta;
	int n;
	do
	{
		cout << "Number of planets: ";
		cin >> n;
	} while (n < 1 || n > 10);

	for (int i = 0; i <= n-1; i++)
	{
		create_planet(P[i]);
	}

	/*for (int i = 0; i <= n-1; i++)
	{
		print_planet(P[i]);
	}*/

	cout << "\n The planet with the largest diameter: \n";
	double diameter_planet = max_diameter(n, P);
	cout << diameter_planet << endl;

	cout << "\n The planet with the small mass: \n";
	double mass_planet = min_mass(n, P);
	cout << mass_planet << endl;
	
	cout << "\n The planet that is farthest from the sun: \n";
	planeta = max_sun_light(n, P);
	print_planet(planeta);
	
	cout << "\n The planet that is closest to the sun: \n";
	planeta = min_sun_light(n, P);
	print_planet(planeta);

	return 0;
}

//you don't need 2 loops when searching for a max/min element -8pts
// 32 pts