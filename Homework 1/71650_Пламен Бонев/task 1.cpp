#include <iostream>
#include <cmath>

using namespace std;

struct Triangle {
	double a;
	double b;
	double c;

	void crate(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}
	void print()
	{
		cout << a << " " << b << " " << c;
	}

	double perimetar()
	{
		return a + b + c;
	}

	double surface()
	{
		double halfPerimetar = perimetar() / 2;
		return sqrt(halfPerimetar*(halfPerimetar - a)*(halfPerimetar - b)*(halfPerimetar - c));
	}

	void mult_k(int k)
	{
		Triangle test2;
		test2.a = a*k;
		test2.b = b*k;
		test2.c = c*k;
	}


};

int main()
{
	Triangle test[30];

	/* test[0].crate(3, 4, 5);
	test[0].print();
	cout << endl;
	test[0].mult_k(2);
	cout << endl;
	cout << "Perimetar: " << test[0].perimetar() << endl;
	cout << "Surface: " <<  test[0].surface() << endl; */


	for (int i = 1; i <= 20; i++)
	{
		test[i].crate(i + 3, i + 1, i + 2);
	}

	double maxPerimetar = 0;
	double minSurface = test[1].surface();

	for (int i = 1; i <= 20; i++)
	{
		if (test[i].perimetar() > maxPerimetar) //what about test[0] ?
			maxPerimetar = test[i + 1].perimetar();
	}

	for (int i = 1; i <= 20; i++)
	{
		if (minSurface > test[i+1].surface()) //what about test[0] ?
			minSurface = test[i + 1].surface();
	}
	
	cout << "Max perimetar: "<< maxPerimetar << endl;
	cout << "Min surface: " << minSurface << endl;

	for (int i = 1; i <= 20; i++)
	{
		test[i].mult_k(i);
	}
	system("PAUSE");
	return 0;
}

//11 pts