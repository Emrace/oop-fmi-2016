#include<iostream>
using namespace std;

struct Triangle
{
	double a, b, c;
	void create(double x, double y, double z){
		a = x;
		b = y;
		c = z;
	}
	void print(){
		cout << "a: " << a << "; b: " << b << "; c: " << c << endl;
	}
	double surface(){
		return (1 / 4)*sqrt((a + b + c)*(-a + b + c)*(a - b + c)*(a + b - c));
	}

	double perimeter(){
		return a + b + c;
	}

	Triangle mult_k(int k){
		Triangle triangle;
		triangle.a = a*k;
		triangle.b = b*k;
		triangle.c = c*k;
		return triangle;
	}
};
int main()
{
	Triangle triangles[20];
	int maxPerimeterIndex = 0, minSurfaceIndex = 0;
	int count;
	do
	{
		cout << "Number of triangles: ";
		cin >> count;
	} while (count < 1 || count > 20);


	for (int i = 0; i < count; i++)
	{
		double a, b, c;
		cout << "a b c---" << i + 1 << ":";
		cin >> a >> b >> c;
		triangles[i].create(a, b, c);
		if (triangles[maxPerimeterIndex].perimeter() < triangles[i].perimeter()){
			maxPerimeterIndex = i;
		}
		if (triangles[minSurfaceIndex].surface() > triangles[i].surface()){
			minSurfaceIndex = i;
		}
	}

	//cout << "sdfsdf" << "dffsfdsf";
	cout << "Triangle with max perimeter: ";
	triangles[maxPerimeterIndex].print();

	cout << "Triangle with min surface: ";
	triangles[minSurfaceIndex].print();

	cout << "--------------------------------------------------------------" << endl;
	////////////////////////////////////////////////
	Triangle modifiedTriangles[20];
	for (int i = 0; i < count; i++)
	{
		modifiedTriangles[i] = triangles[i].mult_k(i + 1);
		modifiedTriangles[i].print();
	}

	system("PAUSE");

	return 0;
}

// 20 pts