#include <iostream>
#include <cmath>
using namespace std;

int MAXProducts = 20;
int MAXQuantity = 100;
struct Product
{
private:
	string name;
	double price1;
	double sellPrice;
	double quantity1;
	double quantity2;
public:
	double getPrice1()
	{
		return price1;
	}
	double getQuantity1()
	{
		return quantity1;
	}
	

	
};
struct Cafeteria
{
private:
	Product product;
	double countClients;
	Product MostSell;
	double dailyWon;
public:
	void create()
	{
		for (int i = 0; i < MAXProducts; i++)
		{
			cout << "name:";
			cin >> product[i].name;
			cout << "BuyPrice:";
			cin >> product[i].price1;
			cout << "SellPrice:";
			cin >> product[i].sellPice;
			cout << "Quantity:";
			cin >> product[i].quantity1;
			cout << "MaxQuantity:";
			cin >> product[i].quantity2;
		}
	}
	void buy()
	{
		for (int i = 0; i < MAXProducts; i++)
		{
			do                    // if  (product[i].quantity1 < product[i].quantity2)
			{
				product[i].quantity1 = product[i].quantity2  
				
		} 
			while (product[i].quantity1 < product[i].quantity2) // { product[i].quantity1 = product[i].quantity2 }
		}
	}

	void sell()
	{

		double sellQuantity;
		cout << "name:";
		cin >> product;
		cout << "SellQuantity:";
		cin >> sellQuantity;

		{
			if (sellQuantity != 0)
			{

				product[i].quantity1 = product[i].quantity1 - sellQuantity;
				dailyWon = dailyWon + product[i].price1;
			}
			else
			{
				cout << "no sell" << endl;
			}
		}
	}

	void getMostPopularProduct()
	{

	}
	
	void PrintStatistics()
	{
		double quantityNow = product[i].quantity1;
		cout << "name:" << product << endl;
		cout << "quantity:" << quantityNow;
		cout << "price:" << product[i].price1;
	


	}
};
	int main()
	{

		Product products[MAXProducts];
		p.PrintStatistics();
		
		system("pause");
		return 0;

	};

	
}