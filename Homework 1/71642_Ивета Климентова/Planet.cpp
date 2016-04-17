#include<iostream>
using namespace std;
struct planet
{
private: 
	double distance, diameter, mass;
	char name[20];
public:
	void read(double x, double y, double z, char w)
	{
		distance = x;
		diameter = y;
		mass = z;
		name[20] = w;
	}
	void print() const
	{
		cout << "Planetata na razstoqnie " << distance << ", diametur " << diameter
			<< ", masa " << mass << "i ime " << name[20] << ". \n";
	}
	double get_distance() const
	{
		return distance;
	}
	double get_diameter() const
	{
		return diameter;
	}
	double get_mass() const
	{
		return mass;
	}
	char get_name() const
	{
		return name[20];
	}

}

//20 pts
