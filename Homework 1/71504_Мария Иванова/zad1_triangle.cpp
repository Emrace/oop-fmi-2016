#include<iostream>
#include<math.h>
using namespace std;

const int SIZE = 20;
struct triangle
{
private:
	double a, b, c;
public:
	void create(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}
	void print()const
	{
		cout << "triangle( " << a << ", " << b << ", " << c << ") \n";
	}
	
	double get_a()const
	{
		return a;
	}
	double get_b()const
	{
		return b;
	}
	double get_c()const
	{
		return c;
	}
	double perimeter()const
	{
		return a + b + c;
	}
	double surface()const
	{
		double p;
		p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
	triangle mult_k(int k)
	{
		triangle t;
		t.create(a*k, b*k, c*k);
		return t;
	}
};
triangle minSurface(int n, triangle t[])
{
	int p = 0;
	double min = t[0].surface();
	for (int i = 1; i < n; i++)
	{
		if (t[i].surface() < min)
		{
			min = t[i].surface();
			p = i;
		}
	}
	return t[p];
}
triangle maxPerimeter(int n, triangle t[])
{
	int k = 0;
	double max = t[0].perimeter();
	for (int i = 1; i < n; i++)
	{
		if (t[i].perimeter() > max)
		{
			max = t[i].perimeter();
			k = i;
		}
	}
	return t[k];
}
void newSequence(int n, triangle* t, triangle* newT)
{
	for (int i = 0; i < n; i++)
	{
		newT[i] = t[i].mult_k(i + 1);
	}
}
int main()
{
	int n;
	do
	{
		cout << "n = "; cin >> n;
	} while (n< 1 || n> SIZE);
	triangle T[SIZE];
	
	for (int i = 0; i < n; i++)
	{
		double x, y, z;
		bool flag;
		do
		{
			cout << "x,y,z : ";
			cin >> x >> y >> z;
			flag = (x > 0) && (y > 0) && (z > 0) && (x + y > z) && (x + z > y) && (y + z > x);
		} while (!flag);
		T[i].create(x, y, z);
	}
	cout << "row of triangles: \n";
	for (int i = 0; i < n; i++)
	{
		T[i].print();
	}
	cout << "triangle with min surface: \n";
	minSurface(n, T).print();
	cout << "triangle with max perimeter: \n";
	maxPerimeter(n, T).print();
	triangle N[SIZE];
	cout << "New row of triangles: \n";
	newSequence(n, T, N);
	for (int i = 0; i < n; i++)
	{
		N[i].print();
	}
	return 0;
}

// 20 pts