#include <iostream>
#include <cstring>
using namespace std;
struct Product{

	char name[30];
	double sellPrice;
	double buyPrice;
	int available;
	int maxStored = 100;

	void setProduct(double _sellprice, double _buyprice, int _available){
		sellPrice = _sellprice;
		buyPrice = _buyprice;
		available = _available;
	}
	void printProduct(){
		cout << "Your product is: " << name << endl;
		cout << "Its price is: " << sellPrice << endl;
		cout << "There are " << available << "available " << name << "s" << endl;
	}

};
struct Cafeteria{
private:
	int clientsCount = 0;
	double income = 0;
	int sold;
	double expenses;
	char mostSelled;
	Product a[20];
public:
	
	void sell(char* _name, int _sellQuantity){
		sold = _sellQuantity;
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < _sellQuantity; j++){
				if (strcpy(_name, a[j].name)){
					a[j].available--;
					income += a[j].sellPrice;
					clientsCount++;
				}
			}
		}
	}
	int counter = 0;
	void buy(char* _name){
		
		for (int i = 0; i < 50; i++){
			do{ 
				counter++;
				a[i].available++;
			}
			while (a[i].available <= a[i].maxStored);
		}
	}
	int megaincome(){
		for (int i = 0; i <= sold; i++)
		{
			income += sold*a[i].sellPrice;
		}
	}
	int megaexpences(){
		for (int i = 0; i < counter; i++){
			expenses = counter*a[i].buyPrice;

		}
	}
};

int main(){
	Product bananas;
	bananas.setProduct(3, 1, 80);
	bananas.printProduct();

	system("pause");
	return 0;
}
