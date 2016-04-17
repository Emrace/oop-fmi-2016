/*зад. 2 
struct Planet
char name[] //може да се използва и string
double distance, diameter, mass
void read() - въвежда данни за планета
void print() - извежда данните за планета
функция, която връща като резултат броя секунди, които са необходими на светлината да достигне от слънцето до планетата
приемете, че C = 299 792 km/s, а distance е зададено в километри

Да се напише програма, която:
а) въвежда множество от планети, реализирано чрез едномерен масив
б) извежда данните за планетите от множеството
в) намира планетата с най-голям диаметър
г) намира планетата с най-малка маса
д) намира планетата, до която светлината достига последна*/
#include <iostream> 
#include <iomanip>  
#include <string>
using namespace std; 
const int Max = 3;
struct Planet
{
	string planName;
	double planDistSun;
	double planDiam;
	double mass;
};
//read and print should be for single planet
void read(Planet *planPtr)
{
	string temp;
	for (int j = 0; j < 3; j++) {
		cout << "Enter a Name for the planet:  ";
		cin >> planPtr[j].planName;

		cout << "Enter a distance from the sun:  ";
		cin >> planPtr[j].planDistSun;

		cout << "Enter a planet diameter ";
		cin >> planPtr[j].planDiam;
		
		cout << "Enter the planet's mass: ";
		cin >> planPtr[j].mass;
		cout << endl;
	}
}
void print(Planet *planPtr)
{
	cout << "The info the planets are  ";
	for (int j = 0; j < 3; j++) {
		cout << " The name of planet is: " << planPtr[j].planName << endl;
		cout << " The diameter of planet is: " << planPtr[j].planDiam << endl;
		cout << " The distance from the sun is: " << planPtr[j].planDistSun << endl;
		cout << " The Planet's mass is: " << planPtr[j].mass << endl;
		cout << endl;
	}
}
Planet MaxDiameter(Planet * arr)
{
	Planet MaxDiam = arr[0];
	for (int i = 0; i < 3; i++)
	{
		if (MaxDiam.planDiam > arr[i].planDiam)
		{
			MaxDiam = arr[i];
		}
	}
	return MaxDiam;
}
Planet MinMass(Planet * arr)
{
	Planet Minmass = arr[0];
	for (int i = 0; i < 3; i++)
	{
		if (Minmass.mass < arr[i].mass)
		{
			Minmass = arr[i];
		}
	}
	return Minmass;
}
Planet LastSunLight(Planet * arr)
{
	Planet LastSun = arr[0];
	for (int i = 0; i < 3; i++)
	{
		if (LastSun.planDistSun > arr[i].planDistSun)
		{
			LastSun = arr[i];
		}
	}
	return LastSun;
}
int main()
{
	Planet planetArray[3];
	Planet *planPtr = planetArray;
	MaxDiameter(planPtr);
	LastSunLight(planPtr);
	MinMass(planPtr);
	read(planPtr);
	print(planPtr);

	system("pause");
	return 0;
}

//no function that returns distance from the sun in seconds
// 35 pts