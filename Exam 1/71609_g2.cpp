#include<iostream>
using namespace std;
struct Product
{
private:
	char name[20];
	double price_caf;
	double price_sklad;
	int quantity;
	int quantity_sklad;

public:
	char get_name()
	{
		return name[20];
	}
	double get_price_caf()
	{
		return price_caf;
	}
	double get_price_sklad()
	{
		return price_sklad;
	}
	int get_quantity()
	{
		return quantity;
	}
	int get_quantity_sklad()
	{
		return quantity_sklad;
	}

	void read_product()
	{
		cout << "Name of product:" << endl;
		cin >> name[20];
		cout << "Price in cafeteria: " << endl;
		cin >> price_caf;
		cout << "Price in sklad :" << endl;
		cin >> price_sklad;
		cout << "Quantity :" << endl;
		cin >> quantity;
		cout << "Quantity avaliable in sklad: " << endl;
		cin >> quantity_sklad;
	}
	void print_product()
	{
		cout << "Name of product:" << name[20] << endl;
		cout << "Price in cafeteria: " << price_caf << endl;
		cout << "Price in sklad :" << price_sklad << endl;
		cout << "Quantity :" << quantity << endl;
		cout << "Quantity avaliable in sklad: " << quantity_sklad << endl;
	}
		//this should be outside of the Product struct, no closing bracket for Product
		struct Cafeteria
		{
		private:
			int clients;
			Product; //this should be an array, name is missing as well
		public:
			int get_clients()
			{
				return clients;
			}
		};
	
	double sell(Product p) //no quantity parameter
	{
		cout << "Name: " << endl;
		cin >> name[20];
		cout << "Quantity" << endl;
		cin >> quantity;
		double new_quantity = quantity--;
		double income = price_caf*quantity;
		double newincome = income++;
		return newincome;
	}
	double buy(Product p)
	{
		while (quantity_sklad < 100)
		{
			double outcome = quantity_sklad*price_sklad;

			return outcome;
		}
	}
	double inc(Product p)
	{
		double incomeMoney = newincome - outcome;
	}

	int getMostPopulatProduct(Product p)
	{
		int k = 0;
		for (int i = 0; i < 100; i++)
		{
			double most=sell(p[0])
				if (p[i]>most)
				{
				p[i]=most
				}
		}
		return p[k];
	}


	int main()
	{
		Product p[20];
		for (int i = 0; i < 20; i++)
		{
			read_product();
			print_product();
		}
		sell(p[20]);
		buy(p[20]);
		getMostPopulatProduct(p[20]);
		system("pause");
		return 0;
	}
