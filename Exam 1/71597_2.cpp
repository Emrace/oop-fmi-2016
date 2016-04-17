#include<iostream>
#include<cstdlib>

//#include<string>

using namespace std;


int number;
struct Product {
    string name;
    float sellPrice;
    float buyPrice;
    int quantity;
    int maxQuantity;

    void input() {
        cout <<"name: "; cin>>name;
        cout <<"sell price: "; cin>>sellPrice;
        cout <<"buy price: "; cin>>buyPrice;
        quantity = 100;
        maxQuantity = 100;
    }
    void print() {
        cout << name <<" "<< quantity <<" "<< sellPrice << endl;
    }
};

struct Cafeteria {
    int numberOfClients;
    Product mostPopularProduct;
    float income;
    float expenses;
    Product products[20];
    Cafeteria() {
        numberOfClients = 0;
        income = 0;
        expenses = 0;
    }

    void sell(string n, int q) {
        int p;
        for(int i=0 ; i<=number ; i++) {
            if(i==number) {cout<<"No such item"; system("pause"); return;}
            //it's better to compare strings with compare function
            if(products[i].name == n) {
                p = i; break;
            }
        }
        products[p].quantity-= q;
        income+= q*(products[p].sellPrice);
        numberOfClients++;
    }

    void buy() {
        int i = 0;
        for(int i=0 ; i<number ; i++) {
            //better declare a new Product variable and assign it the value of products[i]
           expenses+= (products[i].maxQuantity - products[i].quantity) * products[i].buyPrice;
            products[i].quantity = products[i].maxQuantity;
        }
    }

    void getMostPopularProduct() {
        //use another name for i, where do you even use it?
        int i = 1, k=0; int minQ = products[0].quantity;
        for(int i=0 ; i<number ; i++) {
            if(products[i].quantity < minQ) {minQ = products[i].quantity; k = i;}
        }
        //could not assign string value to variable of type Product
        mostPopularProduct = products[k].name;
    }

    void printStatistics() {
        int i=0;
        for(int i=0 ; i<number ; i++) {
            cout<<"!";
            products[i].print();
        }
        cout << numberOfClients <<" clients\n";
        cout <<"income: "<< income <<", expenses: "<< expenses << endl <<"total: "<< (income - expenses) << endl;
    }
};



void listProducts(Cafeteria c) {
    for(int i=0 ; i<number ; i++) {
        cout <<"1. ";
        c.products[i].print();
    }
}
int main() {
    Cafeteria c;
    int a;
    cout <<"number of products: "; cin>>number;
    for(int i=0 ; i<number ; i++) {
        cout <<"Product "<< (i+1) <<":\n";
        c.products[i].input();
    }
    do {
            system("cls");
        cout <<"1.Sell a product\n2.Refill\n3.Get most popular product\n4.Print Statistics\n0.Exit\nEnter: ";
        cin>>a;
        string name; int quantity;
        switch (a) {
        case 1:
            listProducts(c);
            cout <<"Product to sell: "; cin>>name;
            cout <<"Quantity: "; cin>>quantity;
            c.sell(name, quantity);
            break;
        case 2:
            c.buy(); break;
        case 3:
            c.getMostPopularProduct();
	    cout<<c.mostPopularProduct; //operator << is not defined for Product
            system("pause");
            break;
        case 4:
            c.printStatistics();
            system("pause");
            break;
        }
    } while(a!=0);
    system("pause");
    return 0;
}


//90 pts