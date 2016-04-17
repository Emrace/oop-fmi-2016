#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const int maxSize = 20;
struct Cafeteria
{
	Product products[maxSize];
	int clientsForADay;
	double earnedMoney;
	double spendMoney;
	void input()
	{
		Product products[maxSize];
		int n;
		cout << "Number of products: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			products[i].input();
			products[i].print();
		}
	}
	double sell(char *_name, double _quantity)
	{
		Product products[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			strcpy(products[i].name, _name);
			products[i].quantityAvailable = _quantity;
		}
		int count = 0;
		double price;
		double DDS = 0.2;
		int quantityLeft;
		for (int i = 0; i < maxSize; i++)
		{
			products[i].input();
			count++;
			products[i].priceForSale++;
			quantityLeft=products[i].quantityAvailable - count;
			price = products[i].priceForSale;
		}
		return quantityLeft;
	}
	double buy(double _quantity)
	{
		Product products[maxSize];
		int count = 0;		
		for (int i = 0; i < maxSize; i++)
		{
			products[i].quantityAvailable = _quantity;
		}
	}
	void printStatistics()
	{
		Product products[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
		   products[i].print();
		}
		cout << "Count of clients for a single day: " << clientsForADay << endl; //the value is never set to anything
		cout << "Spend money for a single day: " << spendMoney << endl;
		cout << "Earned money for a single day:  " << earnedMoney << endl;
		double allMoney = fabs (earnedMoney - spendMoney); //earned money and spent money don't have a value
		cout << "Money at the end of the day: " << allMoney << endl;
	}
};
struct Product
{
	char name[20];
	double DDS = 0.2; //this must be a constant, if you're gonna use it
	double priceToBuy;
	//vat was not mentioned in the task
	double priceForSale = priceToBuy*DDS + priceToBuy; // the price must be set in the input function
	int quantityAvailable;
	int maxQuantity[100];
	void input()
	{
		cout << "Name of the product: ";
		cin >> name;
		cout << "Price to sell: ";
		cin >> priceToBuy;
		cout << "Available quantity: ";
		cin >> quantityAvailable;
	}
	void print()
	{
		cout << "Name of the product: " << name << endl;
		cout << "Sale price: " << priceForSale << endl;
		cout << "Original price: " << priceToBuy << endl;
		cout << "Available quantity: " << quantityAvailable << endl;
		cout << "Max quantity of the products that the Cafeteria can collect: " << maxQuantity << endl;
	}
};

int main()
{
	//you were supposed to have one cafeteria
	Cafeteria cafeteria[maxSize];
	char name[20];
	double quantity;
	for (int i = 0; i < maxSize; i++)
	{
		cafeteria[i].input();
		cafeteria[i].sell(name, quantity); //quantity is not initialized
		cafeteria[i].buy(quantity);
		cafeteria[i].printStatistics();
	}
	system("pause");
	return 0;
}

//76/100