#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Triangle {
	double a;
	double b;
	double c;

	void create(double x, double y, double z) {
		a = x;
		b = y;
		c = z;
	}

	void get() {
		cin >> a;
		cin >> b;
		cin >> c;
	}

	void print() {
		cout << "(" << a << ", " <<
			b << ", " << c << ") " << endl;
	}

	double perimeter() {
		return a + b + c;
	}

	double surface() {
		double p = perimeter() / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}

	Triangle mult_k(int k) {
		double h, g, j;
		create(a, b, c);
		h = a*k;
		g = b*k;
		j = c*k;
		cout << "(" << h << ", " << g << ", "
			<< j << ") " << endl;
	}
};

int main()
{
	Triangle triangles[30];

	int n;
	cout << "Enter the number: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		triangles[i].get();
		cout << endl;
	}

	double maxPerimeter = triangles[0].perimeter();
	for (int i = 0; i < n; i++)
	{
		if (triangles[i].perimeter() > triangles[0].perimeter()) //you compare wrong elements
			maxPerimeter = triangles[i].perimeter();
	}
	cout << "The highest perimeter: " << maxPerimeter << endl;

	double minSurface = triangles[n].perimeter();
	for (int i = 0; i < n; i++)
	{
		if (triangles[i].surface() < triangles[n].surface()) //you compare wrong elements again
			minSurface = triangles[i].surface();
	}
	cout << "The lowest surface: " << minSurface << endl;

	system("PAUSE");
	return 0;
}

// 10 pts