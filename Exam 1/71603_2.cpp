#include<iostream>
#include<string>
using namespace std;

struct Product
{
	int quantity;
	//int maxQuantityForStorage;
	int selledPackages;
	string name;
	double priceForSell;
	double priceForCafeteria;

	Product(){

	}

	//you should've done it with an input function
	Product(string paramName, double paramPriceForSell, double paramPriceForCafeteria)
	{
		name = paramName;
		quantity = 100;
		selledPackages = 0;
		priceForSell = paramPriceForSell;
		priceForCafeteria = paramPriceForCafeteria;
	}

	void print()
	{
		cout << "Name: " << name << " || Quantity: " << quantity << " || Price: " << priceForSell << endl;
	}
};

struct Cafeteria
{
	Product products[20];
	int productsLength = 0;
	int clients = 0;
	double incomeMoney = 0;
	double expenseMoney = 0;
	double income(){

	}
	double expenses(){

	}
	void sell(string name, int paramQuantity){
		for (int i = 0; i < productsLength; i++)
		{
			
			if (products[i].name == name)
			{
				if (paramQuantity > products[i].quantity)
				{
					cout << "Sorry but we have only " << products[i].quantity << " ";
					break;
				}
				incomeMoney += products[i].priceForSell * paramQuantity;
				products[i].quantity -= paramQuantity;
				products[i].selledPackages += paramQuantity;
				clients++;
			}
		}
	}
	void buy(){
		for (int i = 0; i < productsLength; i++)
		{
			if (products[i].quantity < 100)
			{
				expenseMoney += (100 - products[i].quantity)*products[i].priceForCafeteria;
				products[i].quantity = 100;
			}
		}
	}

	string getMostPopularProduct()
	{
		Product product = products[0];
		for (int i = 0; i < productsLength; i++)
		{
			if (product.selledPackages < products[i].selledPackages)
			{
				product = products[i];
			}
		}
		return product.name;
	}

	void printStatistics()
	{
		cout << "###################Staistics#########################" << endl;;
		for (int i = 0; i < productsLength; i++)
		{
			products[i].print();
			cout << "################################################################" << endl;
		}
		cout <<"Clients: "<< clients<<endl;
		cout << "Income: " << incomeMoney << endl;
		cout << "Expenses: " << expenseMoney << endl;
		cout << "GoodMoney: " << incomeMoney - expenseMoney << endl;
	}
};


int main()
{
	//Sample Demonstration
	Cafeteria cafe;
	cafe.productsLength = 3;
	
	cafe.products[0] = Product("Lavazza", 4.50, 3);
	cafe.products[1] = Product("Cappy", 2.50, 1);
	cafe.products[2] = Product("BodyMarry", 9.50, 7);

	cafe.sell("Lavazza", 12);
	cafe.sell("Cappy", 11);
	cafe.buy();
	cafe.printStatistics();

	cout << "MostPopular product: " << cafe.getMostPopularProduct();

	system("PAUSE");
	return 0;
}

// 100/100