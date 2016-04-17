#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct Product
{
	char name[40];
	int quantityInStore=100;
	int quantityAvailable;
	double priceInCafeteria;
	double priceCafeteriabuy;

};
struct Cafeteria
{
	Product product[20];
	double account=0;
	void createProducts(Cafeteria *p,int n);//no need to pass the cafeteria as an argument anywhere
	void printProducts(Cafeteria *p,int n);
	void sell(Cafeteria *p,int n); 
	void buy(Cafeteria *p,int n);
	Cafeteria GetMostPopularProduct(Cafeteria *p, int n); //should return string
};
void Cafeteria::createProducts(Cafeteria *p,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Product name: ";
		cin >> p[i].product[i].name;
		cout << "Available quantity: ";
		cin >> p[i].product[i].quantityAvailable;
		cout << "Price in Cafeteria: ";
		cin >> p[i].product[i].priceInCafeteria;
		cout << "Price that Cafeteria buys the product: ";
		cin >> p[i].product[i].priceCafeteriabuy;
	}
}
void Cafeteria::printProducts(Cafeteria *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Product name: "<< p[i].product[i].name<<endl;
		cout << "Quantiti in store: "<<p[i].product[i].quantityInStore<<endl;
		cout << "Available quantity: "<<p[i].product[i].quantityAvailable<<endl;
		cout << "Price in Cafeteria: "<<setprecision(2)<<p[i].product[i].priceInCafeteria<<endl;
		cout << "Price that Cafeteria buys the product: "<<setprecision(2)<<p[i].product[i].priceCafeteriabuy<<endl;
	}
}
void Cafeteria::sell(Cafeteria *p,int n)
{
	
	char productSell[20];
		cout << "Enter the product name that you want to buy: ";
		cin >> productSell;
		int quantity;
		cout << "Enter the number of that  product you want to buy: ";
		cin >> quantity;
		double bill = 0;
		for (int i = 0; i < n; i++)
		{
			if (strcpy_s(p[i].product[i].name, productSell) == 0) //strcmp is the function you'll looking for
			{
				p[i].product[i].quantityAvailable -= quantity;

			if (p[i].product[i].quantityAvailable < 0)
				{
					cout << "We don't have " << quantity << " of that product!!";
				}
				else
				{
					bill = quantity*p[i].product[i].priceInCafeteria;
					cout << "Your bill is: ";
					cout << bill << endl;
					
				}

			}
			else
			{
				cout << "We don't have " << p[i].product[i].name; //prints every product name till you find the product
			}
		}
		account += bill;
}
void Cafeteria::buy(Cafeteria *p, int n)
{
	int count=0;
	double billCafeteria = 0;
	for (int i = 0; i < n; i++)
	{

		while (p[i].product[i].quantityInStore < 100)
		{
			count++;
			p[i].product[i].quantityAvailable += count;
			billCafeteria = count*p[i].product[i].priceCafeteriabuy;
			account -= billCafeteria;
		}
	}
	cout << account;
}
int main()
{
	Cafeteria p[20];
	int n;
	cout << "Enter the number of products: ";
	cin >> n;
	p[0].createProducts(p, n);
	p[0].printProducts(p, n);
	int numberClients;
	cout << "Enter the number of clients: ";
	cin >> numberClients;
	for (int i = 0; i < numberClients; i++)
	{
	p[1].sell(p, n);
	}
	p[1].buy(p, n);

	system("pause");
	return 0;
}