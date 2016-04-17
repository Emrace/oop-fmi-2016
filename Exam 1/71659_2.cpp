#include <iostream>
#include <string>
using namespace std;
struct Product
{
private:
	string name;
	int quantity;
	int sklad ;
	double buyingPrice;
	double sellingPrice;
public:
	string getName()
	{
		return name;
	}
	int getQuantity()
	{
		return quantity;
	}
	int getSklad()
	{
		return sklad;
	}
	double getBuyingPrice()
	{
		return buyingPrice;
	}
	double getSellingPrice()
	{
		return sellingPrice;
	}
	void print()
	{
		cout << "Imeto na produkta e: ";
		cin >> name;
		cout << "V nalichnost sa: " << quantity << "  " << name << endl;
		cout << "Cenata na sklad e: ";
		cin >> buyingPrice;
		cout << "Cenata na produkta e:";
		cin >> sellingPrice;
	}
	Product()
	{
		quantity = 100;
		sklad = 100;
	}
	Product(string _name, int _quantity, int _sklad, double _buyingPrice, double _sellingPrice)
	{
		name = _name;
		quantity = _quantity;
		sklad = _sklad;
		buyingPrice = _buyingPrice;
		sellingPrice = _sellingPrice;
	}
	void sell()
	{
		int numOfProdsYouWantToBuy;
		cout << "Imeto na produkta e: " << name << endl;
		cout << "Kolko" <<"  "<< name << " " << " iskate da kupite:";
		cin >> numOfProdsYouWantToBuy;
		quantity -= numOfProdsYouWantToBuy;
		int income = 0;
		income += numOfProdsYouWantToBuy*sellingPrice;

		
	}
};
struct Cafeteria
{
private:
	
	int numOfClients;
	string mostPopularProduct;
	double oborot;
public:
	Product product;
	Product getProduct()
	{
		return product;
	}
	int getNumOfClients()
	{
		return numOfClients;
	}
	string getMostPopularProduct()
	{
		return mostPopularProduct;
	}
	double getOborot()
	{
		return oborot;
	}

};


int main()
{
	Product product;
	product.print();
	product.sell();
	system("PAUSE");
	return 0;
}