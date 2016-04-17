#include<iostream>
#include<string>
using namespace std;

//next time, split the exercises in different files

struct Triangle
{
	//is this a mathematically possible triangle
	bool CanExist = true;
	//the sides
	double a, b, c;
	//the function to create a triangle. checks if it can exist
	void Create(double x, double y, double z)
	{
		if (x + y > z && x + z > y && z + y > x) {
			a = x;
			b = y;
			c = z;
		}
		else {
			cout << "such a triangle can not exist" << endl;
			CanExist = false;
		}
	}
	//function to print the triangle info
	void Print()
	{
		cout << a << " " << b << " " << c << " " << Surface() << " " << Perimeter();
	}
	//returns the surface of the triangle
	double Surface()
	{
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
	//returns the perimeter of the triangle
	double Perimeter()
	{
		return a + b + c;
	}
	//multiplies the sides of the triangle p by k
	Triangle mult_k(int k)
	{
		Triangle p;
		p.Create(a*k, b*k, c*k);
		return p;
	}
};
const double SpeedOfLight = 3 * 10 ^ 5; // ^ is a bitwise operator, it does not do what you expect it to do - 0.2
struct Planet
{
public:
	//name of the planet
	string name; //you should've used char*
	//it's distance,diameter and mass
	double distance, diameter, mass;
	//default constructor
	Planet()
	{
		distance = 0;
		diameter = 0;
		mass = 0;
		name = "";
	}
	//input function
	void Read()
	{
		cout << endl << "planet name: ";
		cin >> name;
		cout << endl << name << "'s distance to the sun: ";
		cin >> distance;
		cout << endl << name << "'s diameter: ";
		cin >> diameter;
		cout << endl << name << "'s mass: ";
		cin >> mass;
	}
	//output function
	void Print()
	{
		cout << name << ": " << distance << " km to the sun, " << TimeForSunlight() << " seconds for sunlight to reach " << name << ", " << diameter << " km diameter, " << mass << " kg mass" << endl;
	}
	//calculate the distance necessary for the sunlight to reach the planet's surface. in seconds
	double TimeForSunlight()
	{
		return distance / SpeedOfLight;
	}
};
struct Fruit
{
public:
	//types of color
	enum color { brown, green, orange, red, yellow };
	//yes or no. because bools were apparently too hard to use
	enum yn { yes, no };
	//name, using char so we can sort the array later
	char name[32];
	color cl;
	yn annual;
	yn perennial;
	yn tropical;
	//default constructor. randomly chooses colour
	Fruit()
	{
		strcpy_s(name, "");
		cl = static_cast<color>(rand() % 5);
		annual = static_cast<yn>(rand() % 2);
		perennial = static_cast<yn>(rand() % 2);
		tropical = static_cast<yn>(rand() % 2);
	}
};
//compares the first characters of the names of two fruit
bool ValueCmp(Fruit const & a, Fruit const & b, bool Direction) // why only the first letters? just use strcmp -0.2
{
	if (Direction)
		return a.name[0] > b.name[0];
	else
		return a.name[0] < b.name[0];
}
//sort an array of fruit in a Direction
void DisplayFruitAlphabetically(Fruit(&a)[5], bool Direction)
{
	for (int i = 0, flag = 1; i < 5 && flag; i++)
	{
		flag = 0;
		for (int j = 0; j < 4; j++)
		{
			if (ValueCmp(a[j], a[j + 1], Direction))
			{
				Fruit temp = a[j];             // swap elements
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (Direction) {
			if (a[i].annual == a[i].no)
				cout << a[i].name << endl;
		}
		else
		{
			if (a[i].annual == a[i].yes)
				cout << a[i].name << endl;
		}
	}
	cout << endl;
}

int main()
{
	//define triangles
	Triangle tri[20];
	//min surface, max perimeter
	double minS = 99999, maxP = 0;
	for (int i = 0; i < 20; i++)
	{
		//create random triangles
		tri[i].Create(rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1);
		//if they can exist, we calculate their surface and perimeter
		if (tri[i].CanExist == true) {
			double S = tri[i].Surface();
			if (S < minS)
			{
				minS = S;
			}
			S = tri[i].Perimeter();
			if (S > maxP)
			{
				maxP = S;
			}
			//output
			tri[i].Print();
			cout << endl;
		}
	}
	int k;
	//show the smallest surface and largest perimeter
	cout << "Min S = " << minS << " Max P = " << maxP << endl;
	//multiply the sides of the triangles by k
	cout << "by how much do you want to multiply the faces: ";
	cin >> k;
	for (int i = 0; i < 20; i++)
	{
		//don't do it if the triangle doesn't exist
		if (tri[i].CanExist == true) {
			tri[i] = tri[i].mult_k(k);
			tri[i].Print();
			cout << endl;
		}
	}
	//planets
	Planet SolarSystem[8];
	int size;
	cout << "How many planets do you want to enter: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		//enter the planets
		SolarSystem[i].Read();
	}
	//find the biggest/furthest/slowes to get sunlight planet
	int MaxDiameterIndex = 0, MaxMassIndex = 0, MaxDistanceToSunIndex = 0;
	double MaxDiameter = 0, MaxMass = 0, MaxDistanceToSun = 0;
	for (int i = 0; i < size; i++)
	{
		SolarSystem[i].Print();
		if (SolarSystem[i].diameter > MaxDiameter)
		{
			MaxDiameter = SolarSystem[i].diameter;
			MaxDiameterIndex = i;
		}
		if (SolarSystem[i].mass > MaxMass)
		{
			MaxMass = SolarSystem[i].mass;
			MaxMassIndex = i;
		}
		if (SolarSystem[i].TimeForSunlight() > MaxDistanceToSun)
		{
			MaxDistanceToSun = SolarSystem[i].TimeForSunlight();
			MaxDistanceToSunIndex = i;
		}
	}
	cout << "the planet with the largest mass is " << SolarSystem[MaxMassIndex].name << endl;
	cout << "the planet with the longest diameter is " << SolarSystem[MaxDiameterIndex].name << endl;
	cout << "the planet with the longest time till sunlight reaches it is " << SolarSystem[MaxDistanceToSunIndex].name << endl;
	//fruit
	Fruit fruit[5];
	//give them names
	strcpy_s(fruit[0].name, "apple");
	strcpy_s(fruit[2].name, "date");
	strcpy_s(fruit[1].name, "berries");
	strcpy_s(fruit[4].name, "eggplant");
	strcpy_s(fruit[3].name, "coconut");
	//sort them in both alphabetical directions. false is for the non-annual fruit, rising. true for annual, descending 
	DisplayFruitAlphabetically(fruit, false);
	DisplayFruitAlphabetically(fruit, true);
	system("pause");
	return 0;
}

// 84/100