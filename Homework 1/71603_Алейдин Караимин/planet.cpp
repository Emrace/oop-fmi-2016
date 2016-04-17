#include<iostream>
#include<string>
using namespace std;

struct Planet
{
	string name;
	double distance, diameter, mass;
	void read(){
		cout << "Name: ";
		cin >> name;

		cout << "Distance: ";
		cin >> distance;

		cout << "Diameter: ";
		cin >> diameter;

		cout << "Mass: ";
		cin >> mass;
	}

	void print(){
		cout << "Name: " << name << "||Distance: " << distance << "||Diameter: " << diameter << "||Mass: " << mass << endl;
	}

	double seconds(){
		return distance / 299792;
	}
};


//this just complicates things, no need:  -2 pts
enum Actions
{
	maxDiameterAction,
	minMassAction,
	maxLightSecondsAction,
};
void Input(Planet planets[], int length){
	for (int  i = 0; i < length; i++)
	{
		planets[i].read();
	}
}

void Output(Planet planets[], int length){
	for (int i = 0; i < length; i++)
	{
		planets[i].print();
	}
}

Planet maxDiameter(Planet planets[], int length){
	int maxDiameterIndex = 0;
	for (int i = 1; i < length; i++)
	{
		if (planets[maxDiameterIndex].diameter < planets[i].diameter){
			maxDiameterIndex = i;
		}
	}
	return planets[maxDiameterIndex];
}

Planet minMass(Planet planets[], int length){
	int minMassIndex = 0;
	for (int i = 1; i < length; i++)
	{
		if (planets[minMassIndex].mass > planets[i].mass){
			minMassIndex = i;
		}
	}
	return planets[minMassIndex];
}

Planet maxLigthSeconds(Planet planets[], int length){
	int maxLigthSecondsIndex = 0;
	for (int i = 1; i < length; i++)
	{
		if (planets[maxLigthSecondsIndex].diameter < planets[i].diameter){
			maxLigthSecondsIndex = i;
		}
	}
	return planets[maxLigthSecondsIndex];
}

Planet actions(Planet planets[], int length, Actions action){
	switch (action)
	{
	case maxDiameterAction : 
		return maxDiameter(planets, length);
	case minMassAction:
		return minMass(planets, length);
	case maxLightSecondsAction:
		return maxLigthSeconds(planets, length);
	default:
		break;
	}
}
int main()
{
	Planet planets[100];
	int count;
	do
	{
		cout << "Number of planets: ";
		cin >> count;
	} while (count < 1 || count > 100);

	Input(planets, count);
	Output(planets, count);
	cout << "------------------------------" << endl;

	cout << "Max diameter planet: " << endl;
	actions(planets, count, maxDiameterAction).print();

	cout << "------------------------------" << endl;
	cout << "Min mass planet: " << endl;
	actions(planets, count, minMassAction).print();


	cout << "------------------------------" << endl;
	cout << "Max ligth seconds planet: " << endl;
	actions(planets, count, maxLightSecondsAction).print();

	system("PAUSE");
	return 0;
}

// 38 pts