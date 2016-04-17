#include<iostream>
#include<cmath>

using namespace std;

struct Triangle {
private:
	double a;
	double b;
	double c;
public:
	void setA(double _a) {
		a = _a;
	}
	void setB(double _b) {
		b = _b;
	}
	void setC(double _c) {
		c = _c;
	}
	double getA() {
		return a;
	}
	double getB() {
		return b;
	}
	double getC() {
		return c;
	}
	void create(double x, double y, double z)
	{
		setA(x);
		setB(y);
		setC(z);
	}
	void print() {
		cout << getA() << " " << getB() << " " << getC() << endl;
	}
	double surface() {
		return sqrt(perimeter()*(perimeter()-a)*(perimeter()-b)*(perimeter()-c));
	}
	double perimeter() {
		return getA() + getB() + getC();
	}
	Triangle mult_k(int k) {
		Triangle helper;
		helper.a = a*k;
		helper.b = b*k;
		helper.c = c*k;
		return helper;
	}


};

int main()
{
	double aSide;
	double bSide;
	double cSide;
	int longArray;
	int numberTriangleMinimalSurface = 0;
	int numberTriangleMaximalPerimeter = 0;
	cin >> longArray;
	Triangle helpTriangle;
	Triangle *oldTriangles = new Triangle[longArray];
	Triangle *newTriangles = new Triangle[longArray];
	for (int i = 0; i < longArray; i++)
	{
		cin >> aSide >> bSide >> cSide;
		oldTriangles[i].create(aSide,bSide,cSide);
	}
	for (int i = 0; i < longArray; i++)
	{
		if (oldTriangles[numberTriangleMinimalSurface].surface() > oldTriangles[i].surface()) {
			numberTriangleMinimalSurface = i;
		}
	}

	cout << "Triangle number " << numberTriangleMinimalSurface << " has smallest surface" << endl;

	for (int i = 0; i < longArray; i++)
	{
		if (oldTriangles[numberTriangleMaximalPerimeter].perimeter() < oldTriangles[i].perimeter()) {
			numberTriangleMaximalPerimeter = i;
		}
	}
	cout << "Triangle number " << numberTriangleMaximalPerimeter << " has largest perimeter" << endl;
	cout << "New triangles: " << endl;
	for (int i = 0; i < longArray; i++)
	{
		helpTriangle = oldTriangles[i];
		newTriangles[i] = helpTriangle.mult_k(i + 1);
	}
	for (int i = 0; i < longArray; i++)
	{
		newTriangles[i].print();
	}
	

	delete[]oldTriangles;
	delete[]newTriangles;
	system("pause");
	return 0;
}

// 20 pts