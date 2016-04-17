#include<iostream>
#include<cmath>
using namespace std;

struct Triangle
{
	double a;
	double b;
	double c;

	double getAB()
	{
		return c;
	}
	double getBC()
	{
		return a;
	}
	double GetAC()
	{
		return b;
	}
	Triangle mult_k(int k);
	void create(double x, double y, double z);
	void print();
	double perimeter();
	double  surface();
};
void Triangle::create(double x, double y, double z)
{
	a = x;
	b = y;
	c = z;
}
void Triangle::print()
{
	cout <<"a= "<< a << endl;
	cout <<"b= "<< b << endl;
	cout <<"c= "<< c << endl;
}
double Triangle::perimeter()
{
		return a + b + c;
}
double Triangle::surface()
{
		double semiperimeter = perimeter() / 2;
		return sqrt((semiperimeter - c)*(semiperimeter - b)*(semiperimeter - a)*semiperimeter);

}
Triangle Triangle::mult_k(int k)
{
	Triangle p;
	p.create(k*a, k*b, k*c);
	return p;


}

int main()
{
	Triangle p;
		p.create(3, 4, 5);
		p.print();
		cout << "P = " << p.perimeter();
		cout << "\n";
		cout << "S =  " << p.surface();
		cout << "\n";
		int k = 2;
		p.mult_k(k).print();
		cout << "**************************\n";
	Triangle l[20];
	double a, b, c;
	int n;
	cout << "Enter the number of triangles: ";
	cin >> n;
	for (int i = 1; i < n + 1; i++)
	{
		cout << "a= ";
		cin >> l[i].a;
		cout << "b= ";
		cin >> l[i].b;
		cout << "c= ";
		cin >> l[i].c;
		cout << "***********\n";
	}
	double maxPerimeter = l[1].perimeter();
	double minSurface = l[1].surface();

	int z = 1;
	int s = 1;
	for (int i = 1; i<n + 1;i++)
	{
		if ((l[i].a + l[i].b>l[i].c) && (l[i].a + l[i].c > l[i].b) && (l[i].b + l[i].c > l[i].a))
		{
			l[i].create(l[i].a, l[i].b, l[i].c);
			l[i].print();
			if (maxPerimeter<l[i].perimeter())
			{
				maxPerimeter = l[i].perimeter();
				z = i;
			}
			if (minSurface>l[i].surface())
			{
				minSurface = l[i].surface();
				s = i;
			}
		}
	}
	
	cout << "Max Perimeter - " << maxPerimeter << endl;
	l[z].print();
	cout << "Min Surface - " << minSurface << endl;
	l[s].print();
	cout << "****************************\n";

	for (int i = 1; i < n + 1; i++)
	{
		l[i].mult_k(i).print();
		cout << "******************\n";
	}

	system("pause");
	return 0;
}

//20 pts