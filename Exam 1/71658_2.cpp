#include<iostream>
#include<string>

using namespace std;

struct Product{
	string name;
	double price_cafe;
	double price_buy;
	int quantity = 100;
	int max_product;
	void print();

	Product(){}

	Product(string _name, double _price_cafe, double _price_buy){
		name = _name;
		price_cafe = _price_cafe;
		price_buy = _price_buy;
	};
};
void Product::print(){
	cout << "Name: " << name << endl;
	cout << "Price Cafe: " << price_cafe << endl;
	cout << "Price buy: " << price_buy << endl;
}
struct Cafeteria{
	Product pr[20];
	int clients;
	int pr_length;
	double prices;
	double income_money;
	double expenses_money;
	double income();
	double expenses();
	void printStatistics();
	void sell(string name,int quantity);
	void buy();
	string getMostPopularproduct();
};
void Cafeteria::sell(string _name, int _quantity){
	for (int i = 0; i < pr_length; i++){
		if (pr[i].name == _name){
			income_money += pr[i].price_buy;
			pr[i].quantity = _quantity;
		}
	}
}
void Cafeteria::buy(){
	for (int i = 0; i < 100; i++){
		if (pr[i].quantity < 100){
			expenses_money += (100 - pr[i].quantity) * pr[i].price_cafe;
		}
	}
}
void Cafeteria::printStatistics(){
	for (int i = 0; i < pr_length; i++){
		cout << endl;
		pr[i].print();
	}

	//you don't print income and expenses
}
int main(){
	
	Cafeteria cafe;
	cafe.pr_length = 4;

	cafe.pr[0] = Product("spetema", 2.30, 3);
	cafe.pr[1] = Product("lavaca", 4.30, 1);
	cafe.pr[2] = Product("nescafe", 23.00, 5);
	cafe.pr[3] = Product("3in1", 1.30, 3);

	
	cafe.sell("nescafe",5);
	cafe.buy();
	cafe.printStatistics();
	system("PAUSE");
	return 0;
}