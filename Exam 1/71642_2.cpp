#include<iostream>
using namespace std;


struct Product
{
private:
	char productName[20];
	char productCode[10];
	int quantity;
	float price;
public:
	char get_productName()
	{
		return productName[20];
	}
	int get_quantity()
	{
		return quantity;
	}
	float get_price()
	{
		return price;
	}
	char get_productCode()
	{
		return productCode[10];
	}
	void read_Product()
	{
		cout << "vuvedete produkta: " << endl;
		cin >> productName;
		cout << "Vuvedete kolichestvo: " << endl;
		cin >> quantity;
		cout << "Vuvedete cena: " << endl;
		cin >> price;
	}
	void printproduct(Product product);
	
}; 

struct Cafeteria
{
private:
	double numberClients, price1, price2, menuItem;
public:
	double get_numberClients()
	{
		return numberClients;
	}
	double get_price1()
	{
		return price1;
	}
	double get_price2()
	{
		return price2;
	}
	double menuItem()
	{
		return menuItem;
	}
	void sell()
	{
		cout << "Vuvedete produkta: ";
		cin >> menuItem;

	}
	void buy()
	{

	}

	
};
	int main()
	{
		Product p[20];


	}





