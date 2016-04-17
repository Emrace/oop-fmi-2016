#include<iostream>
#include<string>
#include<cmath>
const int maxSize = 20;
using namespace std;
struct Planet
{
	string name;
	double distance;
	double diameter;
	double mass;

	void read();
	void print();
	double seconds();
	Planet lastOne(int n, Planet planets[maxSize]);
	Planet maxDiameter(int n, Planet planets[]);
	Planet minMass(int n, Planet planets[]);
	
};

void Planet::read()
{
	cout << "Name: ";
	cin >> name;
	cout << "Diameter: ";
	cin >> diameter;
	cout << "Distance: ";
	cin >> distance;
	cout << "Mass: ";
	cin >> mass;
	cout << endl;
}

void Planet::print()
{
	cout << "Planet(name:" << name << ", distance: "<< distance <<", diameter: "<<diameter << ", mass: " << mass <<")"<< endl;
	cout << endl;
}

double Planet::seconds()
{
	double time, distance1;
	double speed = 299792;
	double speed1 = speed * 1000;
	distance1 = distance * 1000;
	time = distance1 / speed1;
	return time;
}
//You missed :: operator - -3 pts
Planet lastOne(int n, Planet planets[maxSize])
{
	int l = 0;
	double last = planets[0].seconds();
	for (int i = 1; i < n; i++)
	{
		if (planets[i].seconds() < last)
			last = planets[i].seconds();
			l = i;
	}
	return planets[l];
}
 Planet maxDiameter(int n, Planet planets[maxSize])
{
	int d = 0;
	double maxDiam = planets[0].diameter;
	for (int i = 1; i < n; i++)
	{
		if (planets[i].diameter > maxDiam)
			maxDiam = planets[i].diameter;
			d = i;
	}
	return planets[d];
}
 Planet  minMass(int n, Planet planets[])
{
	int m = 0;
	double minM = planets[0].mass;
	for (int i = 1; i < n; i++)
	{
		if (planets[i].mass < minM)
			minM = planets[i].mass;
			m = i;
	}
	return planets[m];
}

int main()
{
	Planet planet;
	//planet.read("Jupiter", 816081455, 142984, 500000);
	planet.read();
	planet.print();
	cout << "Distance from the sun to the planet(in seconds)= " << planet.seconds() << endl;
	cout << endl;

	int n;
	do
	{
		cout << "n= ";
		cin >> n;
		cout << endl;
	} while (n < 1 || n>maxSize);

	Planet planets[maxSize];
	for (int i = 1; i <= n; i++)
	{
		string name;
		double distance, mass, diameter;
		planets[i].read();
	}
	cout << "Planets: " << endl;
	for (int i = 1; i <= n; i++)
	{
		planets[i].print();
	}
	cout << endl;
		cout << "The planet with the smallest mass is:  " << endl;
		minMass(n, planets).print();
		cout << "The planet with the biggest diameter is:  " << endl;
		maxDiameter(n, planets).print();
		cout << "The light reaches this planet last:  " << endl;
		lastOne(n, planets).print();
		
		
//намиране на най-голям диаметър и най-малка маса
/*	for (int j = 0; j < n; j++)
	{
		if (maxDiameter > planets[j].diameter())
			maxDiameter = planets[j].diameter();
		if (minMass < planets[j].mass())
			minMass = planets[j].mass;
	}
	cout << "The largest diameter is: " << maxDiameter << endl;
	cout << "The smallest mass is: " << minMass << endl;
	*/
	system("pause");
	return 0;
}

// 37 pts