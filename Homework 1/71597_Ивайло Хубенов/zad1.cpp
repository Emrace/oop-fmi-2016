#include<iostream>
#include<math.h>
using namespace std;
struct Triangle {
    double a,b,c;
    void create(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }
    void print() {
        cout << a <<" "<< b <<" "<< c << endl;
    }
    double surface() {
        double p = (a + b + c)/2;
        double s = sqrt(p * (p-a) * (p-b) * (p-c));
        return sqrt(p * (p-a) * (p-b) * (p-c));
    }
    double perimeter() {
        return (a + b + c);
    }
    Triangle mult_k(int k) {
        Triangle p;
        p.create(k * a , k * b , k * c);
        return p;
    }
};

void input(Triangle &tr) {
    double a, b, c;
    cin >> a >> b >> c;
    tr.create(a, b, c);
}

void minS(Triangle tr[], int n) {
    double min = tr[1].surface();
    int k = 1;
    for(int i=2 ; i<=n ; i++) {
        if(tr[i].surface() < min) { min = tr[i].surface(); k = i;}
    }
    cout <<"Smallest area: ";
    tr[k].print();
    cout <<" = "<< tr[k].surface() << endl;
}

void maxP(Triangle tr[], int n) {
    double max = tr[1].perimeter();
    int k = 1;
    for(int i=2 ; i<=n ; i++) {
        if(tr[i].perimeter() > max) { max = tr[i].perimeter(); k = i;}
    }
    cout <<"Largest perimeter: ";
    tr[k].print();
    cout <<" = "<< tr[k].perimeter() << endl;
}

int main() {
    Triangle tr[21], kTr[21];
    cout<<"number of triangles: ";
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) {
        input(tr[i]);
    }
    minS(tr, n);
    maxP(tr, n);
    for(int i=1 ; i<n ; i++) {
        kTr[i].create((tr[i].a * i), (tr[i].b * i), (tr[i].c * i));
    }
}

//20 pts