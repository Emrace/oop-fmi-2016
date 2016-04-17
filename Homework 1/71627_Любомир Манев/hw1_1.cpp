#include <iostream>
#include <cmath>
using namespace std;
struct Triangle
{
private:
  double a;
  double b;
  double c;
public:

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

    void setA(double _a)
    {
        a = _a;
    }

    void setB(double _b)
    {
        b = _b;
    }

    void setC(double _c)
    {
        c = _c;
    }

    Triangle(){}
    Triangle( double newa , double newb , double newc )
  {
      setA(newa);
      setB(newb);
      setC(newc);
  }

  void read()
  {
      double tmp;
      cout<< "Enter a " <<endl;
      cin>> tmp;
      setA(tmp);
      cout<< "Enter b " <<endl;
      cin>> tmp;
      setB(tmp);
      cout<< "Enter c " <<endl;
      cin>> tmp;
      setC(tmp);
  }

  void print()
  {
      cout<< "The sides of the triangle are: " << a << " " << b << " " << c <<endl;
  }

  double perimeter()
  {
      return ( getA() + getB() + getC() );
  }

  double surface()
  {
      double p = double((getA() + getB() + getC() )/2);
      double surface = double(sqrt ( p * ( p - getA() ) * ( p - getB() ) * ( p - getC() ) ) );
      return surface;
  }

  Triangle mult_k(int k)
  {
      return Triangle(getA()*k, getB() * k , getC() * k );
  }

};

Triangle findTriangleWithSmallestSurface( Triangle setOfTriangles[] ,int sizeOfSet)
{
    double smallestSurface;
    int counter;
    for( int i = 0; i < sizeOfSet; i++ )
    {
        if( i == 0 ) //you can just define it outside of 
        {
            smallestSurface = setOfTriangles[i].surface();
            counter = 0;
        }
        if( smallestSurface > setOfTriangles[i].surface() )
        {
            smallestSurface = setOfTriangles[i].surface();
            counter = i;
        }
    }
    return setOfTriangles[counter];
}

Triangle findTriangleWithBiggestPerimeter ( Triangle setOfTriangles[] , int sizeOfSet )
{
    double BiggestPerimeter;
    int counter;
    for( int i = 0; i < sizeOfSet; i++ )
    {
        if( i == 0 )
        {
            BiggestPerimeter = setOfTriangles[i].perimeter();
            counter = 0;
        }
        if( BiggestPerimeter < setOfTriangles[i].perimeter() )
        {
            BiggestPerimeter = setOfTriangles[i].perimeter();
            counter = i;
        }
    }
    return setOfTriangles[counter];
}

Triangle create( double newa, double newb, double newc )
{
    Triangle newTriangle ( newa, newb, newc );
    return newTriangle;
}

int main()
{
    Triangle setOfTriangles[20];
    int n = 5;
    setOfTriangles[0] = create(3,4,5);
    setOfTriangles[1] = create(13,12,5);
    setOfTriangles[2] = create(12,14,15);
    setOfTriangles[3] = create(22,14,15);
    setOfTriangles[4] = create(10,30,25);
    // cin>>n;
    /*
    for( int i = 0; i < n; i++ )
    {
        setOfTriangles[i].read();
    }
    */
    for( int i = 0; i < n; i++ )
    {
        setOfTriangles[i].print();
    }
    cout<<endl;
    cout<< "Biggest perimeter is: " << findTriangleWithBiggestPerimeter(setOfTriangles,5).perimeter() <<endl;
    cout<<"Smallest surface is: " << findTriangleWithSmallestSurface(setOfTriangles,5).surface() <<endl;
    cout<<endl;

    Triangle multipliedSetOfTriangles[20];
    for( int i = 0; i < n; i++ )
    {
        multipliedSetOfTriangles[i] = setOfTriangles[i].mult_k(i+1);
    }

    for( int i = 0; i < n; i++ )
    {
        multipliedSetOfTriangles[i].print();
    }

    return 0;
}
// 20 pts