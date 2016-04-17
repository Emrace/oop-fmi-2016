#include<iostream>
using namespace std;
struct Planet {
    string name;
    double distance, diameter, mass;

    void read() {
        cout <<"name: "; cin >> name;
        cout <<"distance: "; cin >> distance;
        cout <<"diameter: "; cin >> diameter;
        cout <<"mass: "; cin >> mass;
    }
    void print() {
        cout << name <<" "<< distance <<" "<< diameter <<" "<< mass << endl;
    }
    double sec() {
        return (distance / (299792));
    }
};

void maxDia(Planet a[], int n) {
    double max = a[0].diameter;
    int k = 0;
    for(int i=1 ; i<n ; i++) {
        if(a[i].diameter > max) { max = a[i].diameter; k = i;}
    }
    cout <<"maximal diameter: "<< a[k].name << endl;
}
void minMass(Planet a[], int n) {
    double min = a[0].mass;
    int k = 0;
    for(int i=1 ; i<n ; i++) {
        if(a[i].mass < min) { min = a[i].mass; k = i;}
    }
    cout <<"minimal mass: "<< a[k].name << endl;
}
void maxDist(Planet a[], int n) {
    double max = a[0].sec();
    int k = 0;
    for(int i=1 ; i<n ; i++) {
        if(a[i].sec() > max) { max = a[i].sec(); k = i;}
    }
    cout <<"the light reaches "<< a[k].name << " last.\n";
}

int main() {
    int n;
    cout <<"number of planets: "; cin >> n;
    Planet planets[10];
    for(int i=0 ; i<n ; i++) {
        planets[i].read();
    }
    cout<<"\nPlanets: \n";
    for(int i=0 ; i<n ; i++) {
        planets[i].print();
    }
    cout<<endl;
    maxDia(planets, n);
    minMass(planets, n);
    maxDist(planets, n);
    return 0;
}

//40 pts
