#include<iostream>
#include<string>
using namespace std;

const int NUM = 10;

enum Color { BROWN, GREEN, ORANGE, RED, YELLOW };
enum Yn { YES, NO };

struct Fruit
{
	char name[32];
	Color cl;
	Yn annual;    //едногодишен плод
	Yn perennial; //многогодишен плод
	Yn tropical;  //тропически плод
};

void create_fruit(Fruit &F)
{
		int k, a, p, t;

		char pt[100];
		cin.getline(pt, 100);

		cout << "\n Name of fruit: "; cin.getline(F.name, 32);

		do
		{
			cout << "color of fruit; choose 0(BROWN) or 1(GREEN) or 2(ORANGE) or 3(RED) or 4(YELLOW) ";
			cin >> k;

		} while ((k < 0 || k>4));
		F.cl = (Color)k;

		//a fruit is either annual or perennial, no need for two loops
		//you can deduce the value of perennial based on user input for annual

		do
		{
			cout << "annual; choose 0(YES) or 1(NO) ";
			cin >> a;
		} while (a<0 || a>1);
		F.annual = (Yn)a;

		do
		{
			cout << "perennial; choose 0(YES) or 1(NO) ";
			cin >> p;
		} while (p<0 || p>1);
		F.perennial = (Yn)p;

		do
		{
			cout << "tropical; choose 0(YES) or 1(NO) ";
			cin >> t;
		} while (t<0 || t>1);
		F.tropical = (Yn)t;
	
	cout << endl;
}

void print(int n,Fruit* f[])
{
	for (int i = 0; i <= n - 1; i++)
	{
		cout << "\n Name of fruit: " << f[i]->name << endl;

		cout << "Color of fruit: ";
		switch (f[i]->cl)
		{
		case 0: cout << "brown \n"; break;
		case 1: cout << "green \n"; break;
		case 2: cout << "orange \n"; break;
		case 3: cout << "red \n"; break;
		case 4: cout << "yellow \n"; break;
		}


		cout << "Annual fruit: ";
		switch (f[i]->annual)
		{
		case 0: cout << "yes \n"; break;
		case 1: cout << "no \n"; break;
		}

		cout << "perennial fruit: ";
		switch (f[i]->perennial)
		{
		case 0: cout << "yes \n"; break;
		case 1: cout << "no \n"; break;
		}

		cout << "Tropical fruit: ";
		switch (f[i]->tropical)
		{
		case 0: cout << "yes \n"; break;
		case 1: cout << "no \n"; break;
		}
	}
}
void sort_name(int n, Fruit* F[])
{
	char name_fruit[32];
	for (int i = 0; i <= n-2; i++)
	{
		int k = i;
		strcpy(name_fruit, F[i]->name);
		for (int j = i+1; j <= n-1; j++)
		{
			if (strcmp(name_fruit, F[j]->name) == 1)
			{
				strcpy(name_fruit, F[j]->name);
				k = j;
			}
		}
		swap(F[i], F[k]);
	}
}

void sort_color(int n, Fruit* F[])
{
	Color cl;
	for (int i = 0; i <= n - 2; i++)
	{
		int k = i;
		cl = F[i]->cl;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if ((Color)cl > (Color)(F[j]->cl))
			{
				cl = F[j]->cl;
				k = j;
			}
		}
		swap(F[i], F[k]);
	}
}

void sort_annual(int n, Fruit* F[])
{
	Yn annual_fruit = (Yn)0;

	for (int i = 0; i <= n - 1; i++)
	{
		if ((Yn)(F[i]->annual) == (Yn)annual_fruit)
		{
			cout << "Annual fruit: ";
			cout << F[i]->name << endl;			
		}
	}
}

int main()
{
	Fruit F[NUM];
	Fruit* Fr[NUM];

	int n;
	cout << "Number of fruit: "; cin >> n;

	for (int i = 0; i <= n-1; i++)
	{
		create_fruit(F[i]);
		Fr[i] = &F[i];
	}

	cout << "\n Sort by name of fruits \n";
	sort_name(n, Fr);
	print(n, Fr);

	cout << "\n Sort by color of fruits: (0->BROWN, 1->GREEN, 2->ORANGE, 3->RED, 4->YELLOW) \n";
	sort_color(n, Fr);
	print(n, Fr);

	sort_annual(n, Fr);

	return 0;
}

//40 pts