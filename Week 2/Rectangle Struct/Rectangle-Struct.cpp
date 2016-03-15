#include <iostream>
 
using namespace std;
 
struct Rectangle
{
    int length;
    int width;
};
 
void print_rectangle(Rectangle r)
{
    cout << "Length: " << r.length << endl;
    cout << "Width: " << r.width << endl;
}
 
//init rectangle r with values entered from the console
//we use pseudonym to be able to modify the fields of r
void init_rectangle(Rectangle& r)
{
    do
    {
        cout << "Enter length: ";
        cin >> r.length;
        cout << "Enter width: ";
        cin >> r.width;
    } while (r.length < 0 || r.width < 0);
}
 
Rectangle init_rectangle()
{
    Rectangle r;

    //code reuse
    //we use the parametrised function init_rectangle with paramater r
    init_rectangle(r);
   
    return r;
}
 
int main()
{
    Rectangle p;
    p = init_rectangle();
    print_rectangle(p);
 
    system("pause");
}