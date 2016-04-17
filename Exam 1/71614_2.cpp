#include<iostream>
#include<string>

using namespace std;

const int maxProducts = 3; //the task was for 20

struct Product{
	string name;
	float prizeBuy; //use double
	float prizeSell;
	int quantityInStock;
	int maxCapableQuantity = 100;
	int quantitySolled;

};
struct Cafeteria{
	Product products[maxProducts];
	int brClients;
	Product mostSelledProduct;
	float wonMoney;
	float moneyPlus;
	float moneyLost;

	void input()
	{
		for (int i = 0; i < maxProducts; i++)
		{
			cin >> products[i].name >> products[i].prizeBuy >> products[i].prizeSell;
			products[i].quantityInStock = products[i].maxCapableQuantity;
			products[i].quantitySolled = 0;
			wonMoney = 0;
			brClients = 0;
			moneyPlus = 0;
			moneyLost = 0;
		}
	}
	void sell(){
		float quantityWantToSell;
		string name;
		cin >> name >> quantityWantToSell;
		for (int i = 0; i < maxProducts; i++)
		{
			if ((name == products[i].name) && (products[i].quantityInStock - quantityWantToSell >= 0 )){
				products[i].quantityInStock -= quantityWantToSell;
				wonMoney += quantityWantToSell*products[i].prizeSell;
				products[i].quantitySolled += quantityWantToSell;
				brClients++;
				moneyPlus += quantityWantToSell*products[i].prizeSell;
			}
		}
	}
	void buy()
	{
		for (int i = 0; i < maxProducts; i++)
		{
			if ((products[i].quantityInStock < products[i].maxCapableQuantity) && (wonMoney - (products[i].maxCapableQuantity - products[i].quantityInStock)*products[i].prizeBuy >= 0))
			{
				wonMoney -= (products[i].maxCapableQuantity - products[i].quantityInStock)*products[i].prizeBuy;
				products[i].quantityInStock = products[i].maxCapableQuantity;
				moneyLost += (products[i].maxCapableQuantity - products[i].quantityInStock)*products[i].prizeBuy;
			}
		}
	}
	Product getMostPopularProduct()
	{
		mostSelledProduct = products[0];
		for (int i = 0; i < maxProducts - 1; i++)
		{
			if (products[i].quantitySolled >= mostSelledProduct.quantitySolled){
				mostSelledProduct = products[i];
			}
		}
		return mostSelledProduct;
	}
	void printStatistics()
	{
		for (int i = 0; i < maxProducts; i++)
		{
			cout << products[i].name << products[i].quantityInStock << products[i].prizeSell << endl;
		}
		cout << brClients << wonMoney << moneyLost << moneyPlus;
	}
};

int main()
{
	Cafeteria cafeteria;
	cafeteria.input();
	cafeteria.sell();
	cafeteria.printStatistics();

	system("pause");
	return 0;
}

//95/100