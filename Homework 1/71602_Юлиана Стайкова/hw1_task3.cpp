#include<iostream>
using namespace std;

const int maxSize = 50;
enum color { brown, green, orange, red, yellow };
enum y_n { yes, no };

struct Fruit
{
	char name[32];
	color cl;
	y_n annual;
	y_n perennial;
	y_n tropical;

	
};
void output(int n, Fruit fruits[maxSize]);
void input(int n, Fruit fruits[maxSize]);


int main()
{
	int n;
	cout << "Insert number of fruits: ";
	cin >> n;
	
	Fruit *fruits = new Fruit[n];
	input(n, fruits);
	cout << endl;
	output(n, fruits);
	//delete[]fruits; 			//allocated memory should be freed, we haven't cover that yet, how did you come up with that -0.1
								// -0.1 is because of possible memory leak

	system("pause");
	return 0;
}

void input(int n, Fruit *fruits)
{
	for (int i = 0; i < n; i++)
	{
		char choose;
		cout << "Name of the fruit: " << endl;
		cin >> fruits[i].name;
		do
		{
			cout << "Color: " << endl;
			cout << "Choose one of the following letters: b (brown),g (green), o (orrange),r (red) or y (yellow)." << endl;
			cin >> choose;
			switch (choose)
			{
			case 'b': fruits[i].cl = brown; break;
			case 'g': fruits[i].cl = green; break;
			case 'o': fruits[i].cl = orange; break;
			case 'r': fruits[i].cl = red; break;
			case 'y': fruits[i].cl = yellow; break;
			default: cout << "Insert one of the following letters: b (brown), g (green), o (orrange), r (red) or y (yellow)." << endl;
			}
		} while ((!(choose == 'b')) && (!(choose == 'g')) && (!(choose == 'o')) && (!(choose == 'r')) && (!(choose == 'y')));

		do
		{
			cout << "Is the fruit annual : ";
			cout << "Insert y for yes or n for no" << endl;
			cin >> choose;
			switch (choose)
			{
			case 'y': fruits[i].annual = yes; break;
			case 'n': fruits[i].annual = no; break;
			default: cout << "Please type y for yes or n for no" << endl;
			}
		} while ((!(choose == 'y')) && (!(choose == 'n')));

		do
		{
			cout << "Is the fruit perennial:";
			cout << "Insert y for yes or n for no" << endl;
			cin >> choose;
			switch (choose)
			{
			case 'y': fruits[i].perennial = yes; break;
			case 'n': fruits[i].perennial = no; break;
			default: cout << "Please type y for yes or n for no" << endl;
			}
		} while ((!(choose == 'y')) && (!(choose == 'n')));

		// value of perennial can be deduced from the value of annual

		do
		{
			cout << "Is the fruit tropical:";
			cout << "Insert y for yes or n for no" << endl;
			cin >> choose;
			switch (choose)
			{
			case 'y': fruits[i].tropical = yes; break;
			case 'n': fruits[i].tropical = no; break;
			default: cout << "Please type y for yes or n for no";
			}
		} while ((!(choose == 'y')) && (!(choose == 'n')));

	}
}

void output(int n, Fruit *fruits)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Number of the fruit: " << i + 1 <<  endl;
		cout << "Name: " << fruits[i].name << endl;
		cout << "Color: ";

		switch (fruits[i].cl)
		{
		case brown: cout << "brown" << endl; break;
		case green: cout << "green" << endl; break;
		case orange: cout << "orange" << endl; break;
		case red: cout << "red" << endl; break;
		case yellow: cout << "yellow" << endl; break;
			break;
		}

		cout << "Is the fruit annual?  ";
		switch (fruits[i].annual)
		{
		case yes: cout << "Yes" << endl; break;
		case no: cout << "No" << endl; break;
			break;
		}
		cout << "Is the fruit perennial? ";

		switch (fruits[i].perennial)
		{
		case yes: cout << "Yes" << endl; break;
		case no: cout << "No" << endl; break;
			break;
		}
		cout << "Is the fruit tropical? ";
		switch (fruits[i].tropical)
		{
		case yes: cout << "Yes" << endl; break;
		case no: cout << "No" << endl; break;
			break;
		}
		cout << endl;
	}
	cout << endl;
}

//last 2 functions not implemented -0.5

// 16 pts
