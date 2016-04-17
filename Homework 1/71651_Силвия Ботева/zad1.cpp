#include <iostream>
#include <cmath>

using namespace std;

struct Triangle
{
private:
	double a, b, c;
public:
	void create(double x, double y, double z);
	void print();
	double surface()
	{
		double halfPerimeter = (a + b + c) / 2;
		return sqrt(halfPerimeter*(halfPerimeter - a)*(halfPerimeter - b)*(halfPerimeter - c));
	}

	double perimeter() 
	{
		return a + b + c;
	}

	double getA(){ return a; }
	double getB(){ return b; }
	double getC(){ return c; }

	Triangle mult_k(int k);
};

void Triangle::create(double x, double y, double z) {
	a = x;
	b = y;
	c = z;
}
void Triangle::print() {
	cout << "(" << a << ", " << b << ", " << c << ")" << endl;
}

Triangle Triangle::mult_k(int k) {
	Triangle t;
	t.create(a*k, b*k, c*k);
	return t;
}

void fillArray(Triangle* ABC, int n) {
	for (int i = 0; i < n; i++){
		double a, b, c;
		cin >> a >> b >> c;
		if (a <= 0 || b <= 0 || c <= 0 || (a + b) <= c || (b + c) <= a || (a + c) <= b)
		{
			cout << "Invalid a,b,c!" << endl;
		}
		else
			ABC[i].create(a, b, c);
	}
}

double maxPerimeter(int n, Triangle* ABC)
{
	double Max = ABC[0].perimeter();
	for (int i = 1; i <= n; i++)
	{
		if (ABC[i].perimeter() > Max)
		{
			Max = ABC[i].perimeter();
		}
		return Max;
	}
}

double minSurface(int n, Triangle* ABC)
{
	double Min = ABC[0].perimeter();
	for (int i = 1; i <= n; i++)
	{
		if (ABC[i].perimeter() < Min)
		{
			Min = ABC[i].perimeter();
		}
		return Min;
	}
}

void newSequence(int n, Triangle *ABC, Triangle *newABC)
{
	for (int i = 0; i < n; i++)
	{
		newABC[i] = ABC[i].mult_k(i + 1);
	}
}

int main() {
	int n = 5;
	const int k = 5;
	Triangle ABC;
	ABC.create(3, 4, 5);
	cout << "Triangle has perimeters = ";
	ABC.print();
	cout << "Surface: " << ABC.surface() << endl;
	cout << "Perimeter: " << ABC.perimeter() << endl;
	cout << "New triangle: ";
	ABC.mult_k(n).print();

	Triangle T[k];
	int br;
	cout << "Number of triangles: ";
	cin >> br;
	cout << "Enter parameters to this " << br << " triangles: ";
	fillArray(T, br);
	cout << "Min surface: " << minSurface(br, T) << endl;
	cout << "Max perimeter: " << maxPerimeter(br, T) << endl;

	Triangle NewT[k];
	newSequence(br, T, NewT);
	for (int i = 0; i < br; i++){
		NewT[i].print();
	}

	system("pause");
	return 0;
}

// 20/20
