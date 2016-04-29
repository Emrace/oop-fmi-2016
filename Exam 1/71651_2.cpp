#include <iostream>
#include <cstring>

using namespace std;

const int nPr = 2;
struct Product
{
	char name[32];
	double price;
	double firstPrice;		//cena na koqto se kupuva
	int quantity;		//kolichestvo produkti
	const int sQuantity = 100;		//skladirano kolichestvo

	void readProduct()
	{
	cout << "Vuvedi ime na produkta: ";
	cin >> name;
	cout << "Vuvedi cena na produkta ";
	cin >> price;
	cout << "Vuvedi skladova cena na produkta: ";
	cin >> firstPrice;
	quantity = sQuantity;
	cout << endl;
	}
	
	void printProduct()
	{
		cout << "Ime na produkta:" << name << endl;
		cout << "Cenata na producta e: " << price << endl;
		cout << "Skaldovata cena na produkta e: " << firstPrice << endl;
		cout << "Nalichnoto kolichestvo na produkta e:" << quantity << endl;
	}
};

struct Cafeteria
{
	Product products[20];
	char nameOfTheMostSoldProduct[32];
	int numberOfClients;
	double cashForDay;

	void read()
	{
		for (int i = 0; i < nPr; i++){
			products[i].readProduct();
		}
	}
	void print()
	{
		for (int i = 0; i < nPr; i++)
		{
			products[i].printProduct();
		}
	}
	void sell(char* name, int quantity)
	{
		for (int i = 0; i < quantity; i++)
		{
			for (int j = 0; j < nPr; j++)
			{
				if (strcmp(name, products[j].name)){ //strcmp returns 0 if the strings are equal
					products[j].quantity--;
					cashForDay += products[j].price;
					cout <<"Pechalbata e: "<<cashForDay;
				}
			}
		}
	}
	void buy(char* name, int quantity)
	{
		int counter = 0;
		for (int i = 0; i < nPr; i++)
		{
			do{
				products[i].quantity++;
				counter++;
				cashForDay -= products[i].price;
			} while (products[i].quantity < products[i].sQuantity);
			cout << "Parite, dadeni za produkti sa: " << cashForDay;
		}
	}
};

//char getMostPopularProduct() {
//	for (int i = 0; i < 20; i++)
//	{
//
//	}
//}

int main()
{
	Cafeteria c;
	c.read();
	c.print();

	int n;
	cout << "Vuvedi broi prodadeni kafeta: ";
	cin >> n;
	
	c.sell("Kafe", n);
	c.buy("Kafe", n);

	system("pause");
	return 0;
}