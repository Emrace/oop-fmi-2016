#include <iostream>
#include <cstring>
using namespace std;
/*
зад. 2
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
д) намира планетата, до която светлината достига последна
*/

struct Planet
{
private:


    string name;
    double distance;
    double diameter;
    double mass;

public:
    static const double LIGHTSPEED = 299792;

    string getName()
    {
        return name;
    }

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

    void setName(string _name)
    {
        name = _name;
    }

    void setDistance ( double _distance)
    {
        distance = _distance;
    }

    void setDiameter( double _diameter )
    {
        diameter = _diameter;
    }

    void setMass( double _mass )
    {
        mass = _mass;
    }


    void read()
    {
        string tmp1;
        cout<< "Enter the name of planet" <<endl;
        cin>> tmp1;
        setName(tmp1);

        double tmp2;
        cout<< "Enter the distance to the sun" <<endl;
        cin>> tmp2;
        setDistance(tmp2);

        cout<< "Enter the diameter of planet" <<endl;
        cin>> tmp2;
        setDiameter(tmp2);

        cout<< "Enter the mass of the planet" <<endl;
        cin>> tmp2;
        setMass(tmp2);

        cout<<endl;
    }

    void print()
    {
        cout<< "Name of planet: "<< getName() <<endl;
        cout<< "Distance to the sun: "<< getDistance() << "km" <<endl;
        cout<< "Diameter: " << getDiameter() << endl;
        cout<< "Mass: " << getMass() <<endl;
    }


    double calculateDistanceOfLightToSun() // in seconds
    {
        return double( getDistance() / LIGHTSPEED );
    }


};

Planet findBiggestDiameter( Planet setOfPlanets[] , int sizeOfSet )
{
    double maxDiameter;
    int counter;
    for( int i = 0; i < sizeOfSet; i++ )
    {

        if(i == 0)
        {
            maxDiameter = setOfPlanets[i].getDiameter();
            counter = 0;
        }

        if(setOfPlanets[i].getDiameter() > maxDiameter)
        {
            maxDiameter = setOfPlanets[i].getDiameter();
            counter = i;
        }
    }

    return setOfPlanets[counter];
}

Planet findSmallestMass ( Planet setOfPlanets[], int sizeOfSet )
{
    int counter;
    double smallestMass;
    for(int i = 0 ; i < sizeOfSet; i++)
    {
        if( i == 0 )
        {
            smallestMass = setOfPlanets[i].getMass();
            counter = 0;
        }
        if( smallestMass > setOfPlanets[i].getMass() )
        {
            smallestMass = setOfPlanets[i].getMass();
            counter = i;
        }

    }

    return setOfPlanets[counter];
}

Planet findFurthestFromTheSun(Planet setOfPlanets[] , int sizeOfPlanets )
{
    int counter;
    double distance;
    for( int i = 0; i < sizeOfPlanets; i++ )
    {
        if( i == 0)
        {
            distance = setOfPlanets[i].calculateDistanceOfLightToSun();
            counter = 0;
        }
        if( distance < setOfPlanets[i].calculateDistanceOfLightToSun() )
        {
            distance = setOfPlanets[i].calculateDistanceOfLightToSun();
            counter = i;
        }
}
return setOfPlanets[counter];
}
int main()
{
    Planet asd[3];
    for( int i = 0; i < 3 ;i++)
    {
        asd[i].read();
    }
        for( int i = 0; i < 3 ;i++)
    {
        asd[i].print();
        cout<<endl;
    }
    cout<<"Planet with biggest diameter is " << findBiggestDiameter(asd,3).getName()
    << " with a diameter of " << findBiggestDiameter(asd,3).getDiameter() <<endl;

    cout<<"Planet with smallest mass is " << findSmallestMass(asd,3).getName()
    << " with a mass of " << findSmallestMass(asd,3).getMass() <<endl;

    cout<<"It takes planet " << findFurthestFromTheSun(asd,3).getName()
    << "  " << findFurthestFromTheSun(asd,3).calculateDistanceOfLightToSun() << " seconds to get sunlight " <<endl;

    return 0;
}

//40 pts