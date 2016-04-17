/*���. 1 (����� �������� � ���)
struct Triangle, ����� �������
double a, b, c - ������ �� �����������
void creat�(double x, double y, double z) - ������� ���������� �� ��� ������ x, y, z
void print() - ������� ����������� �� ��������� (������ �������� ��)
double surface() - �������� ������ �� �����������
double perimeter() - �������� ���������� �� �����������
triangle mult_k(int k) - ������� ��� ���������� ��� ������ ����� �� �������� �� ����� ���������� �������� � ��������� k

�� �� ������ ��������, ����� ������� ������ �� n ����������� (1 <= n <= 20),
���������� �� �������� �� � ������ � ������� ����������� � ��������� ���� � ����������� � ���������� ���������. 
���������� �� ���������� � ������ �� �������������, �������� �� ���������� ������, 
���� �������� �� ����� ���������� �� �������� � ���������,
����� �� ������ �� �������� � �������� (����������� �� ������� �� 1)*/
#include <iostream>
#include <cmath>
const int MAX_SIZE = 20;
using namespace std;
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
	triangle mult_k(int k)
	{
		triangle t;
		t.create(a*k, b*k, c*k);
		return t;
	}
	void print()
	{
		cout << "triangle(" << a << " , " << b << " , " << c << ")\n";
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
	double perimeter() 
	{
		return a + b + c;
	}
	double surface() 
	{
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
	triangle mukt_k(int k) {
		triangle t;
		t.create(a*k, b*k, c*k);
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
		if (T[i].perimeter()>Max)
		{
			Max = T[i].perimeter();
			k = i;
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
		cout << "n="; cin >> n;
	} while (n<1 || n> MAX_SIZE);
	triangle T[MAX_SIZE];
	int i;
	for (int i = 0; i < n; i++)
	{
		double x, y, z;
		bool tri;
		do {
			cout << "Stranata x="; cin >> x;
			cout << "Stranata y="; cin >> y;
			cout << "Stranata z="; cin >> z;
			tri = (x > 0) && (y > 0) && (z > 0) && (x + y > z) && (x + z > y) && (y + z > x);
		} while (!tri);
		T[i].create(x, y, z);
	}
	cout << " Redica ot triugulnici:\n";
	for (int i = 0; i < n; i++)
		T[i].print();
	cout << " Triagulnik s nai malko lice: \n";
	MinSurface(n, T).print();
	cout << " Triagulnik s nai golqm perimeter: \n";
	MaxPerimeter(n, T).print();
	triangle NT[MAX_SIZE];
	cout << "Nova redica ot triagulnici: \n";
	NewSequence(n, T, NT);
	for (int i = 0; i < n; i++)
	{
		NT[i].print();
	}
	system("pause");
	return 0;
}

//20 pts