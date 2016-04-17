#include <iostream>
#include <string>
#include <cstring>
using namespace std;
enum color { brown, green, orange, red, yellow };
enum yesNo { yes, no };
string _yesNo;
string _color;

struct Fruit {
	char name[32];
	color color;
	yesNo annual;
	yesNo perennial;
	yesNo tropical;

public:
	//default constructor should provide default values for all fields, again, you don't need one in this task
	Fruit(char* _name = " ")	//default constructor
	{
		strcpy_s(name, _name);
	}

	//again, i should start from 0, not 1 - -0.3
	void read(Fruit* fr, int size)
	{
		for (int i = 1; i <= size; i++)
		{
			cout << "Name of the fruit: ";
			cin >> fr[i].name;
			cout << "Color of the fruit: ";
			cin >> _color;
			if (_color == "brown") { fr[i].color = brown; }
			else if (_color == "green") { fr[i].color = green; }
			else if (_color == "orange") { fr[i].color = orange; }
			else if (_color == "red") { fr[i].color = red; }
			else if (_color == "yellow") { fr[i].color = yellow; }

			cout << "Is it annual fruit?: ";
			cin >> _yesNo;
			if (_yesNo == "yes") { fr[i].annual = yes; }
			if (_yesNo == "no") { fr[i].annual = no; }

			cout << "Is it perennial fruit?: ";
			cin >> _yesNo;
			if (_yesNo == "yes") { fr[i].perennial = yes; }
			if (_yesNo == "no") { fr[i].perennial = no; }

			cout << "Is it tropical fruit?: ";
			cin >> _yesNo;
			if (_yesNo == "yes") { fr[i].tropical = yes; }
			if (_yesNo == "no") { fr[i].tropical = no; }
			cout << endl;
		}
	}

	void print(Fruit* fr, int size)
	{
		for (int i = 1; i <= size; i++)
		{
			cout << fr[i].name << endl;
			switch (fr[i].color)
			{
			case brown: cout << "Fruit's color: Brown " << endl; break;
			case green: cout << "Fruit's color: Green " << endl; break;
			case orange: cout << "Fruit's color: Orange " << endl; break;
			case red: cout << "Fruit's color: Red " << endl; break;
			case yellow: cout << "Fruit's color: Yellow " << endl; break;
			}
			switch (fr[i].annual)
			{
			case yes: cout << "Fruit is: Annual" << endl; break;
			case no: cout << "Fruit is: Not annual" <<endl; break;
			}
			switch (fr[i].perennial)
			{
			case yes: cout << "Fruit is: Perennial" << endl; break;
			case no: cout << "Fruit is: Not perennial" << endl; break;
			}
			switch (fr[i].tropical)
			{
			case yes: cout << "Fruit is: Tropical" << endl; break;
			case no: cout << "Fruit is: Not tropical" << endl; break;
			}
		}
	}
};


void sortAnnual(Fruit* fr, int size, Fruit* fr2, color cl){
	int counter = 0;
	for (int i = 1; i <= size; i++) {
		if (fr[i].annual == yes && fr[i].color == cl) {
			strcpy_s(fr2[counter].name, fr[i].name);
			fr2[counter].color = fr[i].color;
			fr2[counter].annual = fr[i].annual;
			fr2[counter].perennial = fr[i].perennial;
			fr2[counter].tropical = fr[i].tropical;
			counter++;
		}
	}

	int result;
	for (int i = 1; i < size; ++i)
	{
		for (int j = 1; j < size; ++j)
		{
			result = strcmp(fr2[j].name, fr2[j + 1].name);
			if (result > 0) 
			{
				char swap[32] = "";
				strcpy_s(swap, fr2[j].name);
				strcpy_s(fr2[j].name, fr2[j + 1].name);
				strcpy_s(fr2[j + 1].name, swap);
			}
		}
	}
}

void sortedPerennialReversed(Fruit* fr, int size, Fruit* fr2, color cl){
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (fr[i].perennial == yes && fr[i].color == cl){
			strcpy_s(fr2[counter].name, fr[i].name);
			fr2[counter].color = fr[i].color;
			fr2[counter].annual = fr[i].annual;
			fr2[counter].perennial = fr[i].perennial;
			fr2[counter].tropical = fr[i].tropical;
			counter++;
		}
	}

	int result;
	for (int i = size; i > 1; --i)
	{
		for (int j = size; j > 1; --j)
		{
			result = strcmp(fr2[j].name, fr2[j - 1].name);
			if (result > 0)
			{
				char swap[32] = "";
				strcpy_s(swap, fr2[j].name);
				strcpy_s(fr2[j].name, fr2[j - 1].name);
				strcpy_s(fr2[j - 1].name, swap);
			}
		}
	}
}

int main(){
	const int fruitsNum = 3;
	const color sortColor = yellow;
	Fruit a[fruitsNum];
	Fruit b[fruitsNum];
	Fruit c[fruitsNum];
	a[0].read(a, fruitsNum);
	a[0].print(a, fruitsNum);
	cout << endl;

	cout << "Yellow annual fruits sorted by name: " << endl;
	sortAnnual(a, fruitsNum, b, sortColor);
	b[0].print(b, fruitsNum);

	cout << "Yellow perennial fruits sorted by name reversed: " << endl;
	sortedPerennialReversed(a, fruitsNum, c, sortColor);
	c[0].print(c, fruitsNum);

	system("pause");
	return 0;
}

// 28/40