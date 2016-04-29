#include <iostream>
#include <cstring>
using namespace std;
const int productsCounter = 2;
struct Product{
	char name[32];
	double clientsPrice;
	double buyPrice;
	int quantity;
	const int quantityCap=100;
	int timesSold=0;

	void printProduct(){
		cout << "Product's name: " << name << endl;
		cout << "Price to buy: " << buyPrice << endl;
		cout << "Price to sell: " << clientsPrice << endl;
		cout << "Quantity: " << quantity << endl;
	}
	void read(){
		cout << "Add product's name: ";
		cin >> name;
		cout << "Add product's selling price: ";
		cin >> clientsPrice;
		cout << "Add product's buyout price: ";
		cin >> buyPrice;
		quantity = quantityCap;
		cout << endl;
	}
};
struct Cafeteria{
	Product s[productsCounter];
	int clientsCount=0;
	char mostSold[32];
	double oborot=0;
	double razhodi = 0;
	double prihodi = 0; //not used anywhere
	double pechalba = 0;
	void read(){
		for (int i = 0; i < productsCounter; i++)
		{
			s[i].read();
		}
	}

	void sell(char* _name,int count){
		for (int i = 0; i < count; i++){
			for (int j = 0; j < productsCounter; j++){
				if (strcmp(_name, s[j].name)==0)
				{
					s[j].quantity--;
					oborot += s[j].clientsPrice;
					clientsCount++;
					s[i].timesSold++;
				}
			}
		}
	}

	void buy(char* _name,int br){
		for (int i = 0; i < productsCounter; i++){
			int counter = 0;
			for (int i = 0; i < br; i++){
				s[i].quantity++;
				counter++;
			}
			//no need for that
			cout << "Zakupeno kolichestvo "<<s[i].name << " : " << counter<<endl;
		}
	}

	void getMostPopularProduct(){
		Product helper;
		helper.timesSold = 0;
		for (int i = 0; i < productsCounter; i++){
			if (s[i].timesSold > helper.timesSold)
			{
				strcpy_s(helper.name, s[i].name); //it's not called like that
				helper.timesSold = s[i].timesSold;
			}
		}
		cout << "TopSeller: " << helper.name <<endl;
	}

	void printStatistics(){
		for (int i = 0; i < productsCounter; i++){
			s[i].printProduct();
			razhodi = s[i].buyPrice*s[i].timesSold; //it should be += and better do it in the buy method then call it
		}
		pechalba = oborot - razhodi;
		cout << "Clients for today: " << clientsCount << endl;
		cout << "Expenses for today: " << razhodi << endl;
		cout << "Incomings for today: " << oborot << endl;
		cout << "Today Pesho has won: " << pechalba << endl;
	}
};




int main() {
	Cafeteria PriPesho;
	PriPesho.read();
	PriPesho.sell("Kafe", 3);

	PriPesho.printStatistics();
	PriPesho.getMostPopularProduct();

	system("pause");
	return 0;
}