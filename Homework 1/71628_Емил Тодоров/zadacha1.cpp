#include <iostream>
#include <cmath>
using namespace std;

struct Triangle {
	double a, b, c;
	void create(double x, double y, double z);
	void print();
	double surface();
	double perimeter();
	double getA(){
		return a;
	}
	double getB(){
		return b;
	}
	double getC(){
		return c;
	}
	Triangle mult_k(int k);
};

void Triangle :: create(double x, double y, double z){
	a = x;
	b = y;
	c = z;
}
void Triangle::print(){
	cout << getA() << endl;
	cout << getB() << endl;
	cout << getC() << endl;
}
double Triangle :: surface(){
	double p = (getA() + getB() + getC()) / 2;
	return sqrt(p*(p - getA())*(p-getB())*(p - getC()));
}
double Triangle :: perimeter(){
	double P = getA() + getB() + getC();
	return P;
}
Triangle Triangle :: mult_k(int k){
	Triangle x;
	x.create(a*k,b*k,c*k);
	return x;
}

void fillArray (Triangle* arr,int n){
    for (int i = 0; i < n; i++){
        double a, b, c;
        cin >> a >> b >> c;
        if (a <= 0 || b <= 0 || c <= 0){
            cout << "Invalid a,b,c!"<<endl;
        }
        else if (a + b <= c || b + c <= a || a + c <= b){
            cout << "Invalid a,b,c!"<<endl;
        }
        else arr[i].create(a, b, c);
        }
}

double maxP(Triangle* arr,int n){
    int maxP=arr[0].perimeter();
    for (int j = 0; j < n; j++)
	{
		if (maxP < arr[j].perimeter())
		{
			maxP= arr[j].perimeter();
		}
	}
	return maxP;
}
double minS(Triangle* arr,int n){
    int minS=arr[0].surface();
    for (int j = 0; j < n; j++)
    {
        if (minS>arr[j].surface()){
            minS=arr[j].surface();
        }
    }
    return minS;
}



int main(){
	int n = 5;
	const int k = 5;
	Triangle ABC;
	ABC.create(3, 4, 5);
	ABC.print();
	cout << "Liceto e: " << ABC.surface() << endl;
	cout << "perimetura e: " << ABC.perimeter() << endl;
	ABC.mult_k(n).print();
	Triangle s[k];
	fillArray(s,n);
	cout<<"Minimalno lice: "<<minS(s,n)<<endl;
	cout<<"Maximalen perimetur: "<<maxP(s,n)<<endl;
    cout<<"-------------------"<<endl;
    Triangle f[n];
    for(int i=1;i<=n;i++)
    {
        cout<<"Triugulnik N"<<i<< " ima strani:";
        s[i].mult_k(i).print();
        cout<<endl;
    }
	return 0;
}
// 20 pts 