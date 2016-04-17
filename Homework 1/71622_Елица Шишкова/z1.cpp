#include <iostream>
using namespace std;

struct Triangle {
	double a;
	double b;
	double c;
	double getA()
	{
		return a;
	}
	double getB()
	{
		return b;
	}
	double getC()
	{
		return c;
	}
	Triangle mult_k(int k);
	void create(double x, double y, double z);
	void print();
	double perimeter();
	double surface();
	void createManyTriangles(int n, Triangle a[]);
	void maxPerimeter(int n, Triangle a[]);
	void minArea(int n, Triangle a[]); 
	void trianglesMultK(int k,int n, Triangle a[]);
};

void Triangle::create(double x, double y, double z){
	a = x;
	b = y;
	c = z;
}
void Triangle::print()
{
	cout << "a="<< a << "  " << "b=" << b << "  " << "c= "<< c << endl;
}
double Triangle::surface()
{
	double p = (a + b + c) / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));

}
double Triangle::perimeter()
{
	return a+b+c;
}
Triangle Triangle::mult_k(int k)
{
	Triangle jm;
	jm.create(k*a, k*b, k*c);
	return jm;
}
void Triangle::createManyTriangles(int n, Triangle a[])
{
	for (int i = 0; i < n; i++)
	{
		do{
		cout << "a-triangle N:" << i + 1 << " ";
		cin >> a[i].a;
		cout << "b-triangle N: " << i + 1<< " ";
		cin >> a[i].b;
		cout << "c-triangle N: " << i + 1<< " ";
		cin >> a[i].c;
		} while ((a[i].a + a[i].b <= a[i].c) || (a[i].a + a[i].c <= a[i].b) || (a[i].b + a[i].c <= a[i].a));
		if ((a[i].a + a[i].b <= a[i].c) || (a[i].a + a[i].c <= a[i].b) || (a[i].b + a[i].c <= a[i].a)) 
			a[i].create(a[i].getA(), a[i].getB(), a[i].getC());
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i].perimeter() << "   ";
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i].surface() << "   ";
	}
}
void Triangle::maxPerimeter(int n, Triangle a[])
{
	double max = a[0].perimeter();
	for (int i = 0; i < n; i++)
	{
		if ((a[i].perimeter()) > max)  {
			max = a[i].perimeter();
		}
	}
	cout << "Max perimeter=" << max << endl;

}
void Triangle::minArea(int n, Triangle a[])
{
	double min = a[0].surface();
	for (int i = 0; i < n; i++)
	{
		if (a[i].surface() < min) {
			min = a[i].surface();
		}
	}
	cout << "Min area=" << min;
}
void Triangle::trianglesMultK(int k, int n, Triangle a[])
{
	for (int i = 0; i < n; i++)
	{
		a[i].create((i + 1)*a[i].getA(), (i + 1)*a[i].getB(), (i + 1)*a[i].getC());
	}
}
int main()
{
	Triangle r;
	do
	{
		cout << "Enter triangle's three edges:";
		cout << "a=";
		cin >> r.a;
		cout << "b=";
		cin >> r.b;
		cout << "c=";
		cin >> r.c;
	} while ((r.a + r.b < r.c) || (r.a + r.c < r.b)  || (r.b + r.c < r.a));

	
	r.print();
	cout << "S=" << r.surface() << endl;
	cout << endl;
	cout <<"P=" << r.perimeter() << endl;
	int k = 2;
	r.mult_k(k);
	int n;
	do{
cout << "Enter n between 1 and 20 to create many triangles :";
	cin >> n;
	} while (n<1 || n>20);
	
	Triangle p[20];
	p[20].createManyTriangles(n, p);
	p[20].maxPerimeter(n, p);
	p[20].minArea(n, p);
	cout << endl;
	system("Pause");
	return 0;
}

// 20 pts