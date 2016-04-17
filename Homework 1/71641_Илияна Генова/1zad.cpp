#include <iostream>
#include <cmath>
#include <string>
using namespace std;
struct Triangle
{
private:
	double a;
	double b;
	double c;
public:
	void create(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}
	double getX()
	{
		return a;
	}
	double getY()
	{
		return b;
	}
	double getZ()
	{
		return c;
	}
	void print()
	{
		cout << getX() << endl;
		cout << getY() << endl;
		cout << getZ() << endl;
	}
	double perimeter()
	{
		double P = a + b + c;
		return P;
	}
	double surface()
	{
		double p2 = perimeter() / 2;
		double S = sqrt(p2*(p2 - a)*(p2 - b)*(p2 - c));
		return S;
	}

	Triangle mult_k(int k)
	{
		Triangle f;
		f.create(a*k, b*k, c*k);
		return f;
	}


};
int main()
{
	Triangle triangle;
	triangle.create(3, 4, 5);
	triangle.print();
	cout << "P= " << triangle.perimeter() << endl;
	cout << "S= " << triangle.surface() << endl;


	Triangle f = triangle.mult_k(3);
	f.print();
	

	Triangle triangles[5];
	for (int i = 0; i < 5; i++)
	{
		double a, b, c;
		cout << "a: ";
		cin >> a;
		cout << " b: ";
		cin >> b;
		cout << "  c: ";
		cin >> c;
		if (((a!=0)&&(b!=0)&&(c!=0))&&((a + b) > c || (a + c) > b || (b + c) > a))
		{
			triangles[i].create(a, b, c);
		}
		else
		{
			cout << "Triangle doesn`t exist"<<endl;
			
		}


	}
	double maxP = triangles[0].perimeter();
	double minS = triangles[0].surface();
	for (int i = 1; i < 5; i++)
	{
		if (maxP < triangles[i].perimeter())
		{
			maxP = triangles[i].perimeter();
		}
		if (minS > triangles[i].surface())
		{
			minS = triangles[i].surface();
		}

	}
	cout << "Max perimeter= " << maxP << endl;
	cout << "Min surface=" << minS << endl;

	system("pause");
	return 0;
}
//20 pts