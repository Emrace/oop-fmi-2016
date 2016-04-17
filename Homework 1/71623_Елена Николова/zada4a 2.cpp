#include<iostream>
#include<iomanip>
using namespace std;
const int c = 299792;
struct Planet
{
	char name[30];
    long  double distance;
	long double diametar;
	long double mass;

	void read();
	void print();
	double secondsFromSunToThePlanet();
	void maxDiametar(Planet *p, int n);
	void minMass(Planet *p,int n);
	void maxSeconds(Planet *p,int n);
};
void Planet::read()
{
	cout << "Planet's name: ";
	cin >> name;
	cout << "Distance from Sun to the Planet : ";
	cin >> distance;
	cout << "Planet's diametar: ";
	cin >> diametar;
	cout << "Planet's mass: ";
	cin >> mass;
}
void Planet::print()
{
	cout << "Planet's name: "<< name<<endl;
	cout << "Distance from Sun to the Planet : "<<setprecision(20)<<distance<<endl;
	cout << "Planet's diametar: "<<setprecision(20)<< diametar<<endl;
	cout << "Planet's mass: "<<setprecision(20)<<mass<<endl;
}
double Planet::secondsFromSunToThePlanet()
{
	return distance/c;
}
void Planet::maxDiametar(Planet *p, int n)
{
	int k=0;
	long double maxDiametar = p[0].diametar;
	for (int i = 1; i < n; i++)
	{
		if (maxDiametar < p[i].diametar)
		{
			k = i;
			maxDiametar = p[i].diametar;
		}
	}
	p[k].print();
}
void Planet::minMass(Planet *p, int n)
{
	int l=0;
	long double minMass = p[0].mass;
	for (int i = 0; i < n; i++)
	{
		if (minMass>p[i].mass)
		{
			minMass = p[i].mass;
			l = i;
		}
	}
	p[l].print();
}
void Planet::maxSeconds(Planet *p, int n)
{
	int m=0;
	double maxSeconds = p[0].secondsFromSunToThePlanet();
	for (int i = 0; i < n; i++)
	{
		if (maxSeconds < p[i].secondsFromSunToThePlanet())
		{
			maxSeconds = p[i].secondsFromSunToThePlanet();
			m = i;
		}
	}
	p[m].print();
}
int main()
{
	Planet p[20];
	int n; 
	cout << "Enter number ot planets: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p[i].read();
		
	}
	for (int i = 0; i < n; i++)
	{
		p[i].print();
	}
	cout << "*********************************\n";
	cout << "Planetata s nai-golqm diametar : ";
	p[0].maxDiametar(p, n);
	cout << "*********************************\n";
	cout << "Planetata s nai-malka masa: ";
	p[0].minMass(p, n);
	cout << "*********************************\n";
	cout << "Planetata nai-otdalechena ot slanceto: ";
	p[0].maxSeconds(p, n);
	system("pause");
	return 0;
}

// 40 pts