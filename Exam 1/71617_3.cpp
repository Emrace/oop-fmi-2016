#include <iostream>
#include <cstring>

using namespace std;

//functions were supposed to belong to a structure


struct Product
{
	char nameOfProduct[25];
	double priceByTheCafeteria;
	double priceOfBuyingByCafeteria;
	size_t currentCountOfProduct;
	size_t maxCountOfProduct;
};

struct Cafeteria
{
	Product listOfProducts[20];
	int numberOfClients;
	char bestSellingProduct[25];
	double income;
	double expenses;
	size_t numberOfProducts;
};

void init(Product &forinit , const char* nameOfProduct , double priceByTheCafeteria , double priceOfBuyingByCafeteria ,
	size_t currentCountOfProduct , size_t maxCountOfProduct)
{
	strncpy_s(forinit.nameOfProduct, nameOfProduct, 25);
	forinit.priceByTheCafeteria = priceByTheCafeteria;
	forinit.priceOfBuyingByCafeteria = priceOfBuyingByCafeteria;
	forinit.currentCountOfProduct = currentCountOfProduct;
	forinit.maxCountOfProduct = maxCountOfProduct;
}

Product addProduct(const char* nameOfProduct, double priceByTheCafeteria, double priceOfBuyingByCafeteria,
	size_t currentCountOfProduct, size_t maxCountOfProduct)
{
	Product temp;
	init(temp, nameOfProduct, priceByTheCafeteria, priceOfBuyingByCafeteria, currentCountOfProduct, maxCountOfProduct);
	return temp;
}

void printProduct(Product &forprint)
{
	cout << "Name of product " << forprint.nameOfProduct << endl;
	cout << "Price by the cafeteria " << forprint.priceByTheCafeteria << endl;
	cout << "Price of buying by the cafeteria " << forprint.priceOfBuyingByCafeteria << endl;
	cout << "Current count of product " << forprint.currentCountOfProduct << endl;
	cout << "Max count of product " << forprint.maxCountOfProduct << endl;
}

void init2(Cafeteria &forinit2, Product* listOfProducts, int numberOfClients, char* bestSellingProduct, double income, double expenses
	, size_t numberOfProducts)
{
	for (int i = 0; i < forinit2.numberOfProducts; i++)
	{
		forinit2.listOfProducts[i] = listOfProducts[i];
	}
	forinit2.numberOfClients = numberOfClients;
	strncpy_s(forinit2.bestSellingProduct, bestSellingProduct, 25);
	forinit2.income = income;
	forinit2.expenses = expenses;
	forinit2.numberOfProducts = numberOfProducts;
}

int sell(Cafeteria temp ,const char* nameOfProduct, size_t countForBuying)
{
	int count = 0;
	for (int i = 0; i < temp.numberOfProducts; i++)
	{
		int a = strcmp(temp.listOfProducts[i].nameOfProduct, nameOfProduct);
		if (a == 0)
		{
			count++;
			temp.listOfProducts[i].currentCountOfProduct -= countForBuying;
			temp.income += temp.listOfProducts[i].priceByTheCafeteria; //multiplied by the count?
			cout << "Number of " << temp.listOfProducts[i].nameOfProduct << "left" << temp.listOfProducts[i].currentCountOfProduct << endl;
		}
	}
	return count;
}


void buy(Cafeteria temp)
{
	int i = 0;
	while (i < temp.numberOfProducts)
	{
	     if (temp.listOfProducts[i].currentCountOfProduct < temp.listOfProducts[i].maxCountOfProduct)
		 {
			while (temp.listOfProducts[i].currentCountOfProduct < temp.listOfProducts[i].maxCountOfProduct)
			{
				temp.listOfProducts[i].currentCountOfProduct++;
				temp.expenses -= temp.listOfProducts[i].priceOfBuyingByCafeteria;
			}
			i++;
		 }
		 else
		 {
			 i++;
		 }
	}
}

char* getMostPopularProduct(Cafeteria temp)
{
	for (int i = 0; i < temp.numberOfProducts; i++)
	{
		int a = strcmp(temp.listOfProducts[i].nameOfProduct, temp.bestSellingProduct); 
		// how do you determine which is the best selling product?
		if (a == 0)
		{
			return temp.listOfProducts[i].nameOfProduct;
		}
	}
}

void printStatistics(Cafeteria temp , Product &temp1)
{
    double finalMoney = temp.income + temp.expenses;
	for (int i = 0; i < temp.numberOfProducts; i++)
	{
		printProduct(temp1);
	}
	cout << endl;
	cout << temp.numberOfClients << endl;
	cout << temp.expenses << endl;
	cout << temp.income << endl;
	cout << finalMoney << endl;
}

int main()
{
	Product newProduct;
	Cafeteria c;
	Product listOfProducts[20];

	int index = 0;
	int bestSell = 0;
	for (int i = 0; i < c.numberOfProducts; i++)
	{
		if (bestSell > c.listOfProducts[i].currentCountOfProduct)
		{
			bestSell = c.listOfProducts[i].currentCountOfProduct;
			index = i;
		}
	}
	
	listOfProducts[0] = addProduct("banana", 3, 2, 30, 100);
	listOfProducts[1] = addProduct("Orange", 4, 3, 20, 100);
	listOfProducts[2] = addProduct("Tomato", 3, 1.90, 40, 100);

	init2(c, listOfProducts, sell(c,"banana" , 15), c.listOfProducts[index].nameOfProduct, 0, 0, 3);
	cout << sell(c, "banana", 15) << endl;
	buy(c);
	cout << endl;
	cout << getMostPopularProduct(c) << endl;
    printStatistics(c, newProduct);
	cout << endl;

	return 0;
}