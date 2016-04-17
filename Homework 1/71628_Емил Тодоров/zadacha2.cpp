#include <iostream>
using namespace std;
struct Planet {
    char name[32];
    double distance;   //double-te pri golemi stoinosti poddavat
    double diameter;    // zatova moje bi s int e po-dobre
    double mass;
    void read();
    void print();
    double secondsForLightTravel(double C);
    double getDistance(){
		return distance;
	}
	double getDiameter(){
		return diameter;
	}
	double getMass(){
		return mass;
	}
	char* getName(){
        return name;
	}
};
void Planet :: read(){
    cout<<"Vuvedi imeto na planetata: ";
    cin>>name;
    double _diameter,_distance,_mass;
    cout<<"Vuvedi diametur(v km): ";
    cin>>_diameter;
    diameter=_diameter;
    cout<<"Vuvedi razstoqnie do slunceto(v km): ";
    cin>>_distance;
    distance=_distance;
    cout<<"Vuvedi masa: ";
    cin>>_mass;
    mass=_mass;
}
void Planet :: print(){
    cout<<"Planetata e :"<<getName()<<endl;
    cout<<"Diametura(v km) e:"<<getDiameter()<<endl;
    cout<<"Razstoqnieto do slunceto (v km) e: "<<getDistance()<<endl;
    cout<<"Masata na planetata e: "<<getMass()<<endl;
    cout<<endl;
}
double Planet :: secondsForLightTravel(double C) {

    return distance/C;
}

void fillArray(Planet* arr,int size){
    for(int i=0;i<size;i++)
    {
        arr[i].read();
        cout<<endl;
    }
}
void printArray(Planet* arr,int size){
    for(int i=0;i<size;i++)
    {
        arr[i].print();
    }
}
void printMaxDiameter(Planet* arr,int size)
{
    int checker=0;
    double maxDiameter=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i].diameter>maxDiameter)
        {
            maxDiameter=arr[i].diameter;
            checker=i;
        }
    }
    cout<<arr[checker].getName();
    cout<<maxDiameter;
}
void printMinMass(Planet* arr,int size)
{
    int checker=0;
    double minMass=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i].mass<minMass)
        {
            minMass=arr[i].mass;
            checker=i;
        }
    }
    cout<<arr[checker].getName();
    cout<<minMass;
}
void maxTravelTimeForLight(Planet* arr,int size,double C)
{
    int checker=0;
    double maxTravelTime=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i].secondsForLightTravel(C)>maxTravelTime)
        {
            maxTravelTime=arr[i].secondsForLightTravel(C);
            checker=i;
        }
    }
    cout<<arr[checker].getName()<<" ";
    cout<<maxTravelTime;
}

int main(){
    int C=299792;
    Planet a;
    a.read();
    cout<<endl;
    a.print();
    cout<<"Svetlinata dostiga za "<<a.secondsForLightTravel(C)<<" sekundi!"<<endl;
    cout<<endl;
    int n;
    cout<<"Vuvedi razmer na masiva: ";
    cin>>n;
    Planet s[n];
    fillArray(s,n);
    cout<<endl;
    cout<<"Danni za planetite: ";
    cout<<endl;
    printArray(s,n);
    cout<<"Planetata s nai-golqm diametur e :";
    printMaxDiameter(s,n);
    cout<<endl;
    cout<<"Planetata s nai-malka masa e: ";
    printMinMass(s,n);
    cout<<endl;
    cout<<"Planetata do koqto svetlinata stiga nai-bavno e: ";
    maxTravelTimeForLight(s,n,C);
    cout<<"sekundi";
    cout<<endl;
    return 0;
}

//40 pts 