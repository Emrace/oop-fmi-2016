#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

struct Cafeteria
{
	public:
	Product product[5];
	double budget;
	double income;	 
	double expenses;
	int sellCounter;
	int productCounter;
	
	Cafeteria(double income, double expenses, int sellCounter, int productCounter)
	{
	income=0;
	expenses=0;
	sellCounter=0;
	productCounter=0;
	}

void Begin()
{
cout<<"Vuvedete nachalen broi producti, s koito razpolaga kafeto:"<<endl;
cin>>productCounter;
	for(int i=0; i<productCounter; i++)
	{
		string nameProduct;
		cin>>nameProduct;
		int priceProduct;
		cin>>priceProduct;
		int quantityProduct;
		cin>>quantityProduct;
	}		
}
};

struct Product
{
public:
string name;
int quantiy;
double price;
int sold;

Product(string name, int quantity, double price)
{
	name = "";
	quantity = 0;
	price = 0;
}

void Print()
{
	cout<<"Product name: "<< name<<": "<<quantity<<"in stock cost "<<price<<endl;

};

/*void buy(string name, int quantity)
{
	for(int i=0;i<productCounter;i++)
	{
		{
		if(product[i].quantity < 100)
			{
			int need = 100 - product[i].quantity;
*/	  	  	  
			

	
void sell(string name, int quantity)
{
	for(int i=0;i<5;i++)
	{
		if(product[i].name == name)	   
		{
		if(product[i].quantity<100)
			{
			income += product[i].price*quantity;
			product[i].sold += quantity;
			sellCounter ++;
			}
		}
	}
}
	

void PrintStatistic()
{
	for(int i=0;i<5=i++)
	{
	product[i].print();
	cout<<endl;
	}
	cout<<sellCounter<<" customers been served today"<<endl;
}
};

int main()
{
system ("PAUSE");
return 0;
}

//50 pts