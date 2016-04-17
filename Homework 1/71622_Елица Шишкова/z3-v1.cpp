#include <iostream>
#include <string>
using namespace std;
//enuma mi e imenuvan yesno poneje mi davashe greshka che sushtestvuva takava funkciq
enum color { brown, green, orange, red, yellow };
enum yesno { yes, no };
string yn_a; string yn_p; string yn_t; string _color;

struct Fruit {
	char name[32];
	color cl;
	yesno annual;
	yesno perennial;
	yesno tropical;
	void inputData(Fruit all[], int n);
	void outputData(Fruit all[], int n);
	void annualFruits(Fruit all[], int n, int col);
	void perennialTropicalFruits(Fruit all[], int n, int col);

};

void Fruit::inputData(Fruit all[], int n){

	for (int i = 0; i < n; i++)
	{
		cout << "Name:";
		cin >> all[i].name;
		cout << "Color:";
		cin >> _color;
		if (_color == "brown")all[i].cl = brown;
		else if (_color == "green")all[i].cl = green;
		else if (_color == "orange")all[i].cl = orange;
		else if (_color == "red") all[i].cl = red;
		else if (_color == "yellow") all[i].cl = yellow;
		else cout << "Unknown fruit color.";
		cout << "Annual - yes or no:";
		cin >> yn_a;
		if (yn_a == "yes")all[i].annual = yes;
		else if (yn_a == "no") all[i].annual = no;
		else cout << "Unknown answer.";
		cout << "Perennial - yes or no:";
		cin >> yn_p;
		if (yn_p == "yes") all[i].perennial = yes;
		else if (yn_p == "no")all[i].perennial = no;
		else cout << "Unknown answer.";
		cout << "Tropical - yes or no:";
		cin >> yn_p;
		if (yn_p == "yes") all[i].tropical = yes;
		else if (yn_p == "no")all[i].tropical = no;
		else cout << "Unknown answer.";
	}
}
void Fruit::outputData(Fruit all[], int n)
{
	for (int i = 0; i < n; i++)
	{

		cout << "Fruit:" << all[i].name << "   " << "Color:";
		switch (all[i].cl){
		case brown: cout << "brown"; break;
		case green: cout << "green"; break;
		case orange: cout << "orange"; break;
		case yellow: cout << "yellow"; break;
		case red: cout << "red"; break;
		}
		cout << "   " << "Annual:";
		switch (all[i].annual)
		{
		case yes: cout << "Yes"; break;
		case no: cout << "No"; break;
		}
		cout << "   " << "Perennial:";
		switch (all[i].perennial){
		case yes: cout << "Yes"; break;
		case no: cout << "No"; break;
		}
		cout << "   " << "Tropical:";
		switch (all[i].tropical)
		{
		case yes: cout << "Yes"; break;
		case no: cout << "No"; break;
		}
		cout << endl;
	}
}

void Fruit::annualFruits(Fruit all[], int n, int col)
{
	Fruit allNew[21];
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (all[i].cl == col){
			strcpy_s(allNew[counter].name, all[i].name);
			allNew[counter].cl = all[i].cl;
			allNew[counter].annual = all[i].annual;
			allNew[counter].perennial = all[i].perennial;
			allNew[counter].tropical = all[i].tropical;
			counter++;
		}
		if  (all[i].annual=yes){ //should be ==
			strcpy_s(allNew[counter].name, all[i].name);
			allNew[counter].cl = all[i].cl;
			allNew[counter].annual = all[i].annual;
			allNew[counter].perennial = all[i].perennial;
			allNew[counter].tropical = all[i].tropical;
			counter++;
		}
	}

	for (int i = 0; i < counter; i++)
	{
		for (int j = 1; j < counter; j++)
		{
			if (strcmp(allNew[j - 1].name, allNew[j].name)>0)
			{
				strcpy_s(name, allNew[j - 1].name);
				strcpy_s(allNew[j - 1].name, allNew[j].name);
				strcpy_s(allNew[j].name, name);
			}
		}

	}
	for (int i = 0; i < counter; i++)
	{
		cout << allNew[i].name << "   ";
	}
}


void Fruit::perennialTropicalFruits(Fruit all[], int n, int col)
{
	Fruit newAll[21];
	int counter = 0;
	for (int i = 0; i < n; i++)
	{

		if (col == all[i].cl)
		{
			strcpy_s(newAll[counter].name, all[i].name);
			newAll[counter].cl = all[i].cl;
			newAll[counter].annual = all[i].annual;
			newAll[counter].perennial = all[i].perennial;
			newAll[counter].tropical = all[i].tropical;
			counter++;
		}
		if (all[i].perennial = yes) //should be ==
		{
			strcpy_s(newAll[counter].name, all[i].name);
			newAll[counter].cl = all[i].cl;
			newAll[counter].annual = all[i].annual;
			newAll[counter].perennial = all[i].perennial;
			newAll[counter].tropical = all[i].tropical;
			counter++;
		}
		if (all[i].tropical = yes) //same as above
		{
			strcpy_s(newAll[counter].name, all[i].name);
			newAll[counter].cl = all[i].cl;
			newAll[counter].annual = all[i].annual;
			newAll[counter].perennial = all[i].perennial;
			newAll[counter].tropical = all[i].tropical;
			counter++;
		}
	}

	for (int i = 0; i < counter; i++)
	{
		for (int j = 1; j < counter; j++)
		{
			if (strcmp(newAll[j - 1].name, newAll[j].name)>0) //shouldn't it be <? 
			{
				strcpy_s(name, newAll[j - 1].name);
				strcpy_s(newAll[j - 1].name, newAll[j].name);
				strcpy_s(newAll[j].name, name);
			}
		}
	}
	for (int i = counter - 1; i >= 0; i--)
	{
		cout << newAll[i].name << "   ";
	}


}

int main()
{
	Fruit allFruits[20]; int n;
	cout << "Enter a number of fruits:";
	cin >> n;
	allFruits[n].inputData(allFruits, n);
	allFruits[n].outputData(allFruits, n);
	int af; int ptf;
	cout << "Enter number between 1 and 5 to choose annual fruits from same color (1-brown, 2-green, 3-orange, 4-red, 5-yellow)";
	cin >> af;
	switch (af)
	{
	case 1: af = brown; break;
	case 2: af = green; break;
	case 3: af = orange; break;
	case 4: af = red; break;
	case 5: af = yellow; break;
	default: cout << "Unknown color";
	}
	allFruits[n].annualFruits(allFruits, n, af);
	cout << endl;
	cout << "Enter number between 1 and 5 to choose perennial tropical fruits from same color (1-brown, 2-green, 3-orange, 4-red, 5-yellow)";
	cin >> ptf;
	switch (ptf)
	{
	case 1: ptf = brown; break;
	case 2: ptf = green; break;
	case 3: ptf = orange; break;
	case 4: ptf = red; break;
	case 5: ptf = yellow; break;
	default: cout << "Unknown color";
	}
	allFruits[n].perennialTropicalFruits(allFruits, n, ptf);
	system("Pause");
	return 0;

}

// 25 pts