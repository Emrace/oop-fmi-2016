#include <iostream>

using namespace std;

const int MAX_SIZE = 20;

struct Triangle{
	double a, b, c;

	void create(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}

	void print()
	{
		cout << "triangle" << "(" << a << ", " << b << ", " << c << ")";
	}

	double get_a()
	{
		return a;
	}

	double get_b()
	{
		return b;
	}

	double get_c()
	{
		return c;
	}

	double surface()
	{
		double p = (a + b + c) / 2;

		return sqrt(p*(p - a)*(p - b)*(p - c));
	}

	double perimeter()
	{
		return a + b + c;
	}

	Triangle mult_k(int k)
	{
		Triangle t;
		t.create(a * k, b*k, c*k);
	}
};

Triangle GetMaxPerimeterTriangle(int n, Triangle seq[])
{
	int k = 0;
	double max = seq[0].perimeter();

	for (int i = 1; i < n; i++)
	{
		if (seq[i].perimeter() > max)
		{
			max = seq[i].perimeter();
			k = i;
		}
	}

	return seq[k];
}

Triangle GetMinSurfaceTriangle(int n, Triangle seq[])
{
	int k = 0;
	double min = seq[0].surface();

	for (int i = 1; i < n; i++)
	{
		if (seq[i].perimeter() < min)
		{
			min = seq[i].perimeter();
			k = i;
		}
	}

	return seq[k];
}

void CreateNewSeq(int n, Triangle* seq, Triangle* newSeq)
{
	for (int i = 0; i < n; i++)
	{
		newSeq[i] = seq[i].mult_k(i + 1);
	}
}

int main()
{
	int n;
	
	Triangle seq[MAX_SIZE];

	do
	{
		cout << "n: ";
		cin >> n;
	} while (n < 1 || n > 20);

	for (int i = 0; i < n; i++)
	{
		double x, y, z;
		bool isTriangle;

		do
		{
			cout << "x, y, z";
			cin >> x, y, z;
			isTriangle = (x > 0) && (y > 0) && (z > 0) && (x + y > z) && (x + z > y) && (y + z > x);
		} while (!isTriangle);
	}

	system("pause");
	return 0;
}

