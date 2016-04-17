#include<iostream>
#include<cmath>
const int maxSize = 20;
using namespace std;
struct Triangle
{
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


	void setA(double newA)
	{
		a = newA;
	}
	void setB(double newB)
	{
		b = newB;
	}
	void setC(double newC)
	{
		c = newC;
	}

	
	void create(double x, double y, double z);
	void print();
	double surface();
	double perimeter();
	Triangle mult_k(int k);
	Triangle minSurface(int n, Triangle triangle[]);
	Triangle maxPerimeter(int n, Triangle triangle[]);
	void newTriangle(int n, Triangle* triangle, Triangle* newTriangle);
	
};

void Triangle::create(double x, double y, double z)
{
	a = x;
	b = y;
	c = z;
}

void Triangle::print() 
{
	cout <<"Triangle("<< getA() << ", " << getB() << ", " << getC()<<") " << endl;
}

double Triangle::surface()
{
	double p, S;
	p = (a + b + c) / 2;
	S = sqrt(p*(p - a)*(p - b)*(p - c));
	//p = (getA() + getB() + getC()) / 2;
	//S = sqrt(p*(p - getA())*(p - getB())*(p - getC()));
	return S;
}

double Triangle::perimeter()
{
	
	double P = a + b + c;//double P = getA() + getB() + getC();
	return P;
}

Triangle Triangle::mult_k(int k)
{
	Triangle t;
	t.create(a*k, b*k, c*k);
	return t;
}
Triangle minSurface(int n, Triangle triangle[])
{
	int p = 0;
	double minSurf = triangle[0].surface();
	for (int i = 1; i < n; i++)
	{
		if (triangle[i].surface() < minSurf)
			p = i;
	}
	return triangle[p];
}
Triangle maxPerimeter(int n, Triangle triangle[])
{
	int s = 0;
	double maxPerim = triangle[0].perimeter();
	for (int i = 1; i < n; i++)
	{
		if (triangle[i].perimeter() > maxPerim)
			s = i;
	}
	return triangle[s];
}
void newTriangle(int n, Triangle* triangle, Triangle* newTriangle)
{
	for (int i = 0; i < n; i++)
		newTriangle[i] = triangle[i].mult_k(i + 1);
}

int main()
{
	
	const int k = 2;
	Triangle triangle;
	triangle.create(3, 4, 5);
	cout << "Triangle: ";
	triangle.print();
	cout << "Surface= " << triangle.surface() << endl;
	cout << "Perimeter= " << triangle.perimeter() << endl;
	cout << "New triangle: ";
	triangle.mult_k(k).print();
	cout << endl;
	cout << endl;

	int n;
	do
	{
		cout << "n= ";
		cin >> n;
	} while (n < 1 || n>maxSize);
	Triangle triangles[maxSize];
	for (int i = 0; i < n; i++)
	{
		double a, b, c;
		bool isTriangle;
		do
		{
			cout << "Insert a, b, c:  ";
			cin >> a >> b >> c;
			isTriangle = (a>0) && (b > 0) && (c > 0) && (a + b > c) && (a + c > b) && (b + c > a);
		} while (!isTriangle);

		triangles[i].create(a, b, c);
	}
		// намира най-малкото лице и най-големия периметър
	/*double maxP = triangles[0].perimeter();
	double minS = triangles[0].surface();

	for (int j = 0; j < n; j++)
	{
		if (maxP< triangles[j].perimeter())
		{
			maxP = triangles[j].perimeter();
		}
		if (minS > triangles[j].surface())
		{
			minS = triangles[j].surface();
		}

	}
	cout << "Max P= " << maxP << endl;
	cout << "Min S= " << minS << endl;
	
	*/
	cout << "Triangle with the smallest surface: " << endl;
	minSurface(n, triangles).print();
	cout << "Triangle with the biggest perimeter: " << endl;
	maxPerimeter(n, triangles).print();
	cout << endl;
	cout << endl;

	Triangle newTriangles[maxSize];
	cout << "New sequence of triangles: " << endl;
	newTriangle(n, triangles, newTriangles);
	for (int i = 0; i < n; i++)
		newTriangles[i].print(); 
	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}

// 20 pts