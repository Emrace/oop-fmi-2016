#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int CONST_MAX_STORAGE = 100;

struct Product {
	string name; // ime na produkta
	double price1; // cenata na koqto zavedenieto go kupuva
	double price2; // cenata na koqto zavedenieto go prodava
	int quantity; // kolichestvo v nalichnost
	int times1; // kolko puti se e prodal edin produkt dnevno (za samiq produkt)
	int storage; // kakvo kolichestvo nai mn moje da se subira

	Product(string _name = " ", double _price1 = 0, double _price2 = 0,
		int _quantity = 0, int _times1 = 0, int _storage = 0) {
		name = _name;
		price1 = _price1;
		price2 = _price2;
		quantity = _quantity;
		times1 = _times1;
		storage = _storage;
	}

	void input(Product products[], int n) {
		for (int i = 0; i < n; i++)
		{
			cin >> products[i].name >> products[i].price1
				>> products[i].price2 >> products[i].quantity >>
				products[i].times1 >> products[i].storage; //times should be 0
		}
	}

	void getMostPopularProduct() {
		Product products[20];


		int popular = products[0].times1;
		string name = products[0].name;

		for (int i = 1; i < 20; i++)
		{
			if (products[i].times1 > products[0].times1) //that's not how it works
				popular = products[i].times1;
			name = products[i].name;
		}

		cout << "The most popular product is " << name << endl;
	}

	void print() {

		cout << endl;
		cout << "Name: " << name << endl << "  -price1: " << price1 << endl << "  -price2: "
			<< price2 << endl << "  -the quantity: " << quantity << endl << "  -how many times?: " <<
			times1 << endl << "  -how many on storage?: " << storage << endl;
	}
};


struct Cafeteria {
	int clients; // broi klienti za edin den
	
	int times; // kolko puti se e prodal edin produkt dnevno (za oborota)
	//what is it used for?

	double sum1; // kolko pari pecheli dnevno
	double sum2; // kolko pari se harchat dnevno
	
	Cafeteria(int _clients = 0, int _times = 0,
	double _sum1 = 0, double _sum2 = 0) {
		clients = _clients; //clients count change every time you sell a product
		times = _times;
		sum1 = _sum1;
		sum2 = _sum2;
	}

	void sell(Product product, int n) {
		Cafeteria();
		product.quantity -= n;
		sum1 += product.price2; //multiplied by n?

		cout << "Nalichno kolichestvo: " << product.quantity << endl <<
			"Pechalba: " << sum1 << endl; // no need to print that
	}

	void buy(Product product) {
		Cafeteria();
		if (times != 0)
			product.quantity += product.storage; // toest ako pytite v koito se e prodalo
		// e razlichen ot nula, to kolichestvoto mu da e ravno na maximalniq broi koito pobira sklada

		//what about the money spent to restock?
	}

	void printStatistics() {
		Product product;
		cout << "Statistics: " << endl;
		cout << product.name << " " << product.price1 << " " <<
			product.quantity << " " << clients << " " << sum1 //clients is not set to a value
			<< " " << sum2 << endl;
	}
};


int main() {

	Product a1("Starbucks", 2.5, 3.5, 30, 10, 100);
	a1.print();

	

	system("PAUSE");
	return 0;
}