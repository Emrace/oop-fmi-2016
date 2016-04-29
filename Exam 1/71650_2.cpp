#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Product
{
public:

	string name;
	double buyPrice;
	double sellPrice;
	int quantity;
	int storage;

	Product(string _name = " ", double _buyPrice = 0, double _sellPrice = 0, int _quantity = 0, int _storage = 100)
	{
		name = _name;
		buyPrice = _buyPrice;
		sellPrice = _sellPrice;
		quantity = _quantity;
		storage = _storage;

	}

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Available: " << quantity << endl;
		cout << "Price: " << sellPrice << endl;
	}

	void print2()
	{
		cout << name << endl;
	}
};


struct Cafeteria
{
public:
	string name;
	int clients;
	double income;
	// string item; // kakvo se prodava nai-mnogo
	int sell1; // pari koito pecheli dnevno
	int sell2; // kolko harchi na den

	Cafeteria(string _name = " ",int _clients = 0, double _income = 0, double _sell1 = 0, double _sell2 = 0)
	{
		name = _name;
		clients = _clients;
		income = _income;
		sell1 = _sell1;
		sell2 = _sell2;

	}
	void sell(Product product, int n)
	{
		Cafeteria cafee;

		product.quantity -= n;
		cafee.income += product.sellPrice;
		cafee.sell1 += product.sellPrice;

		cout << "Ostanalo kolichestvo " << product.quantity << endl;
		cout << "Pechalba: " << cafee.sell1 << endl;
	}
	
	void buy(Product product)
	{
		
	}



};

string getMostPopularProduct(Product product[], int n) //it should be in cafeteria
{
	int mostPopular = product[0].quantity;
	int currentIndex = 0;

	for (int i = 0; i < n; i++)
	{
		if (mostPopular < product[i + 1].quantity) 
		//you will go outside of the array when i == n-1, also shouldn't it be reversed
		{
			mostPopular = product[i + 1].quantity;
			currentIndex = i + 1;
		}
		string nameof;
		nameof = product[currentIndex].name;

		return nameof;
		
	}
}


int main()
{
	Cafeteria Pesho("Pesho", 0, 0, 0, 0);

	//products should be in the cafeteria
	Product a("Coca-cola", 2, 5, 100, 100);
	Product b("Fanta", 3, 8, 100, 100);
	Product c("Cafee", 0.5, 2, 100, 100);
	Product d("Water", 1, 2.5, 100, 100);

	const int MAX_SIZE = 30;
	Product products[] = { a, b, c, d };

	for (int i = 0; i < 4; i++)
	{
		products[i].print();
		cout << endl;
	}

	Product mostpop;
	
	mostpop = getMostPopularProduct(products, 4);
	cout << "Most popular product is: ";
	mostpop.print2();


	system("PAUSE");
	return 0;
}