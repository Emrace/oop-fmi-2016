#include<iostream>
#include<string>
using namespace std;
enum color{brown,green,orange,red,yellow};
enum yesNo{yes,no};
string _yesNo;
string _color;
struct Fruit
{
	
	char name[30];
	color cl;
	yesNo annual;
	yesNo perennial;
	yesNo tropical;
	void create(Fruit *p, int n);
	void print(Fruit *p, int n);
	void sortAnnual(Fruit *p2, int br);
	void sortPerennial(Fruit *p3, int count);
	
};
void Fruit::create(Fruit *p,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Fruit's name: ";
		cin >>p[i]. name;
		cout << "Fruit color (choose from brown,green,orange,red or yellow) : ";
		cin >> _color;
		//switch would be better, or even better, ask the user to enter a number
		if (_color == "brown"){
			p[i].cl = brown;
		}
		else if (_color == "orange"){
			p[i].cl = orange;
		}
		else if (_color == "green"){
			p[i].cl = green;
		}
		else if (_color == "red"){
			p[i].cl = red;
		}
		else if (_color == "yellow"){
			p[i].cl = yellow;
		}
		else cout << "Unknown value!!!";
		cout << "Annual fruit (enter yes or no) : ";
		cin >> _yesNo;
		//same as above
		if (_yesNo == "yes"){
			p[i].annual = yes;
		}
		else if (_yesNo == "no"){
			p[i].annual = no;
		}
		else cout << "Unknown value!!!";
		cout << "Perennial fruit (enter yes or no) : ";
		cin >> _yesNo;
		//same
		if (_yesNo == "yes"){
			p[i].perennial = yes;
		}
		else if (_yesNo == "no"){
			p[i].perennial = no;
		}
		else cout << "Unknown value!!!";
		cout << "Tropical fruit (enter yes or no): ";
		cin >> _yesNo;
		//same
		if (_yesNo == "yes"){
			p[i].tropical = yes;
		}
		else if (_yesNo == "no"){
			p[i].tropical = no;
		}
		else cout << "Unknown value!!!";
	}
}
void Fruit:: print(Fruit *p,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Fruit name: " << p[i].name << endl;
		cout << "Color: ";
		switch (p[i].cl)
		{
		case brown:cout << "brown\n"; break;
		case green:cout << "green\n"; break;
		case orange:cout << "orange\n"; break;
		case red:cout << "red\n"; break;
		case yellow:cout << "yellow\n"; break;
		}
		cout << "Annual fruit :";
		switch (p[i].annual)
		{
		case yes:cout << "yes\n"; break;
		case no:cout << "no\n"; break;
		}
		cout << "Perennial fruit:";
		switch (p[i].perennial)
		{
		case yes:cout << "yes\n"; break;
		case no:cout << "no\n"; break;
		}
		cout << "Tropical fruit: ";
		switch (p[i].tropical)
		{
		case yes:cout << "yes\n"; break;
		case no:cout << "no\n"; break;
		}

	}
}
void annualFruits(Fruit *p1, int n, Fruit *p2, int& br,int color1)
{
	for (int i = 0; i < n; i++)
	{
		if (p1[i].annual == yes && p1[i].cl==color1)
		{
			strcpy_s(p2[br].name, p1[i].name);
			p2[br].cl = p1[i].cl;
			p2[br].annual = p1[i].annual;
			p2[br].perennial = p1[i].perennial;
			p2[br].tropical = p1[i].tropical;
			br++;
		}

	}
}
void Fruit::sortAnnual(Fruit *p2, int br)
{
	for (int i = 0; i < br; i++)
	{
		for (int j = 1; j < br; j++)
		{
			if (strcmp(p2[i].name, p2[j].name)>0)
			{
				Fruit x;
				x = p2[i];
				p2[i] = p2[j];
				p2[j] = x;

			}
		}
	}
}
void perennialTropicalFruits(Fruit *p1, int n, Fruit *p3, int &count,int color2)
{
	for (int i = 0; i < n; i++)
	{
		if (p1[i].perennial == yes)
		{
			if (p1[i].tropical == yes && p1[i].cl == color2)
			{
                strcpy_s(p3[count].name, p1[i].name);
				p3[count].cl = p1[i].cl;
				p3[count].annual = p1[i].annual;
				p3[count].perennial = p1[i].perennial;
				p3[count].tropical = p1[i].tropical;
				count++;
			}

		}
	}
}
void Fruit::sortPerennial(Fruit *p3, int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j < count; j++)
		{
			if (strcmp(p3[i].name, p3[j].name)<0)
			{
				Fruit x;
				x = p3[i];
				p3[i] = p3[j];
				p3[j] = x;

			}
		}
	}
}
int main()
{
	int n;
	cout << "Enter number of fruits: ";
	cin >> n;
	int br = 0;
	Fruit p1[10];
	p1[0].create(p1, n);
	Fruit p2[10];

	cout << "*****************************\n";
	int color1;
	cout << "Enter number for color (1=brown,2=green,3=orange,4=red,5=yellow):  ";
	cin >> color1;
	switch (color1)
	{
	case 1: color1 = brown; break;
	case 2: color1 = green; break;
	case 3:color1 = orange; break;
	case 4:color1 = red; break;
	case 5:color1 = yellow; break;
	}
	cout << "All annual fruits /ascending order/ - \n";
	annualFruits(p1, n, p2, br,color1);
	p2[0].sortAnnual(p2, br);
	p2[0].print(p2, br);
	cout << "****************************\n";
	Fruit p3[10];
	int count = 0;
	int color2;
	cout << "Enter number for color (1=brown,2=green,3=orange,4=red,5=yellow):  ";
	cin >> color2;
	switch (color2)
	{
	case 1: color2 = brown; break;
	case 2: color2 = green; break;
	case 3:color2 = orange; break;
	case 4:color2 = red; break;
	case 5:color2 = yellow; break;
	}
	cout << "All perennial tropical fruits /descending order/ - \n";
	perennialTropicalFruits(p1, n, p3, count,color2);
	p3[0].sortPerennial(p3, count);
	p3[0].print(p3, count);
	system("pause");
	return 0;
}

//40 pts