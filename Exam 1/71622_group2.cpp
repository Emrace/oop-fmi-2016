#include <iostream>
#include <string>
using namespace std;

struct Product
{
	string name; 
	double priceFromCafeteria;
	double priceFromStore;
	int quantityInCafeteria;
	int quantityInStore;
	int buyQuantity;
	int buyQuantityForStore;
	void printProduct()
	{ 
		cout << "Product's name" << name << "   " << "Quantity in store:" << quantityInStore << "   " << "Price: " << priceFromCafeteria;
	}
	int getMostPopularProduct(int n){

		Product all[20];

		int popular = all[0].buyQuantity;

		for (int i = 0; i < n; i++)
		{
			if (all[i].buyQuantity > popular)
			{
				popular = all[i].buyQuantity;
			}
		}
		return popular;
	}
};
struct Cafeteria
{
	Product allProduct; // should be an array
	int clients;
	double oborot = 100;
	void sell() //should sell from available products
	{
		allProduct.quantityInStore = 100; 
		cout << "Products's name:";
		    cin >> allProduct.name;
			cout << "Quantity:";
			cin >> allProduct.buyQuantity;
			cout << "Price:";
			cin >> allProduct.priceFromCafeteria;
		    allProduct.quantityInCafeteria-= allProduct.buyQuantity;
			oborot += (allProduct.buyQuantity *allProduct.priceFromCafeteria);
			cout << oborot << endl;
			allProduct.printProduct();
		
	}
	void buy()
	{	
		do
		{
			cin >> allProduct.buyQuantity;
			allProduct.quantityInStore += allProduct.buyQuantityForStore;
		} while (allProduct.quantityInStore < 100);
	}
	void popularProducts()
	{
		cout << allProduct.getMostPopularProduct;
	
	}
	
};
int main()
{
	Cafeteria FMI;
	//int n;
	
    FMI.sell();
	
	for (int i = 0; i < 2; i++)
	{
		FMI.getMostPopularProduct(2);
	}
	system("Pause");
	return 0;
}