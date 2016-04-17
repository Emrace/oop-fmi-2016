#include<iostream>
#include<math.h>
using namespace std;
const int MAX_SIZE = 20;
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
	void print() const
	{
		cout << "triangle(" << a << ", " << b << ", " << c << ") \n";
	}
	double get_a() const
	{
		return a;
	}
	double get_b() const
	{
		return b;
	}
	double get_c() const
	{
		return c;
	}
	double perimeter() const
	{
		return a + b + c;
	}
	double surface() const
	{
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
	triangle mult_k(int k)
	{
		triangle t;
		t.create(a * k, b * k, c * k);
		return t;
	}
};
triangle MinSurface(int n, triangle T[])
{
	int k = 0;
	double Min = T[0].surface();
	for (int i = 1; i < n; i++)
	if (T[i].surface() < Min)
	{
		Min = T[i].surface();
		k = i;
	}
	return T[k];
}
triangle MaxPerimeter(int n, triangle T[])
{
	int k = 0;
	double Max = T[0].perimeter();
	for (int i = 1; i < n; i++)
	if (T[i].perimeter() > Max)
	{
		Max = T[i].perimeter();
		k = 1;
	}
	return T[k];
}
void NewSequence(int n, triangle * T, triangle * NewT)
{
	for (int i = 0; i < n; i++)
		NewT[i] = T[i].mult_k(i + 1);
}
int main()
{
	int n;
	do
	{
		cout << "n= "; 
		cin >> n;
	} while (n < 1 || n > MAX_SIZE);
	triangle T[MAX_SIZE];
	int i;
	for (i = 0; i < n; i++)
	{
		double x, y, z;
		bool tri;
		do
		{
			cout << "x, y, z: ";
			cin >> x >> y >> z;
			tri = (x > 0) && (y > 0) && (z > 0) &&
				(x + y > z) && (x + z > y) && (y + z > x);
		} while (!tri);
		T[i].create(x, y, z);
	}
	cout << "Redica ot triugulnici: \n";
	for (i = 0; i < n; i++)
		T[i].print();
	cout << "Triugulnik s min lice: \n";
	MinSurface(n, T).print();
	cout << "Triugulnik s max perimetur: \n";
	MaxPerimeter(n, T).print();
	triangle NT[MAX_SIZE];
	cout << "Nova redica ot triugulnici: \n";
	NewSequence(n, T, NT);
	for (i = 0; i < n; i++)
		NT[i].print();
	system("pause");
	return 0;
}

//20 pts