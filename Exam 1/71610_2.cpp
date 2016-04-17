#include<iostream>
#include<string>
using namespace std;
struct Product
{
public:
	//product name
	string name;
	//product quantity in stock
	int quantity;
	//product price
	double price; //no buy price
	//how many units of the product has sold today
	int SoldToday;
	//print the product info
	void print()
	{
		cout << name << " : " << quantity << " in stock ; costs " << price << "$ ; " << SoldToday << " have sold today";
	}
	//default constructor
	Product()
	{
		name = "";
		quantity = 0;
		price = 0;
		SoldToday = 0;
	}
	//constructor with arguments
	Product(string newName, double newPrice)
	{
		name = newName;
		quantity = 0;
		price = newPrice;
		SoldToday = 0;
	}
};
struct Cafeteria
{
private:
	//array of products
	Product products[10];
	//offset value for how much we're going to save by buying products. 
	//we need to make money after all, we don't want to spend 300 dollars a day just to earn that much if we sold everything
	const double BuyProductCheaperOffset = 0.5;
	//the total money we currently have
	double Budget()
	{
		return Income - Expenses;
	}
	//how much money we've earned today by selling products
	double Income;
	//how much money we've spent today to restock products
	double Expenses;
	//how many customers we've served today
	int SellCounter;
	//how many types of products we have in stock
	int ProductCount;
public:
	//default constructor
	Cafeteria()
	{
		Income = 0;
		Expenses = 0;
		SellCounter = 0;
		ProductCount = 0;
	}
	//input how many and what products we have, how much they cost
	void Start()
	{

		cout << "How many products does the cafeteria have: ";
		cin >> ProductCount;
		cout << endl;
		for (int i = 0; i < ProductCount; i++)
		{
			cout << "Product name: ";
			string newName;
			cin >> newName;
			cout << endl << newName << " costs : ";
			double newPrice;
			cin >> newPrice;
			products[i] = Product(newName, newPrice);
			cout << endl;
		}
		buy();
	}
	void sell(string name, int quantity)
	{
		for (int i = 0; i < ProductCount; i++)
		{
			//if we have enough of the product, sell it
			if (products[i].name == name)
			{
				if (products[i].quantity >= quantity)
				{
					products[i].quantity -= quantity;
					Income += products[i].price*quantity;
					products[i].SoldToday += quantity;
					SellCounter++;
					return;
				}
				else {//otherwise sell all we can
					if (products[i].quantity > 0)
					{
						cout << "we only have " << products[i].quantity << " " << products[i].name << endl;
						int diff = products[i].quantity;
						products[i].quantity = 0;
						Income += products[i].price*diff;
						products[i].SoldToday += diff;
						SellCounter++;
						return;
					}
					else
					{//otherwise say that we don't have any of it
						cout << "we don't have any " << products[i].name << " today" << endl;
						return;
					}
				}
			}
		}				
		//if the product doesn't exist in the cafeteria
		cout << "there is no such product in the cafeteria" << endl;
	}
	//restock products, 100 being the max
	void buy()
	{
		for (int i = 0; i < ProductCount; i++)
		{
			if (products[i].quantity < 100) {
				int difference = 100 - products[i].quantity;
				products[i].quantity += difference;
				//buy the products cheaper than what we sell them for
				Expenses += products[i].price*difference*BuyProductCheaperOffset;
				//every product should have a different price to restock
			}
		}
	}
	//would be better if this was a product, i'd be able to print how many it has sold today, without having to do more loop searching
	//but because of the task it's a string
	string getMostPopularProduct()
	{
		int index = 0;
		int mostsold = 0;
		for (int i = 0; i < ProductCount; i++)
		{
			if (products[i].SoldToday > mostsold)
			{
				index = i;
				mostsold = products[i].SoldToday;
			}
		}
		return products[index].name;
	}
	//print info for each product, as well as income,expenses, most popular product, served customers, etc
	void PrintStatistics()
	{
		cout << endl;
		for (int i = 0; i < ProductCount; i++)
		{
			products[i].print();
			cout << endl;
		}
		cout << SellCounter << " customers have been served today" << endl;
		string mostpop = getMostPopularProduct();
		cout << "The most popular product today is " << mostpop << endl;
		cout << "We have spent " << Expenses << "$ today, and earned " << Income << "$" << endl;
		cout << "Total: " << Budget() << "$" << endl;
	}
};

int main()
{
	Cafeteria cafe;
	cafe.Start();
	string answer = "";
	cout << endl << "To interact, type buy/statistics/exit" << endl;
	//cycle for different inputs
	//stops when we type exit/Exit
	do
	{
		cout << "what do you wish to do: ";
		cin >> answer;
		if (answer == "Buy"|| answer == "buy")
		{
			cout << endl << "what do you wish to buy: ";
			string newName;
			cin >> newName;
			cout << endl << "how many " << newName << " do you wish to buy: ";
			int newQuantity;
			cin >> newQuantity;
			cafe.sell(newName, newQuantity);
		}
		else
			if (answer == "Statistics"|| answer == "statistics")
			{
				cafe.PrintStatistics();
			}
	} while (answer != "Exit"&&answer != "exit");
	system("pause");
	return 0;
}

//90/100