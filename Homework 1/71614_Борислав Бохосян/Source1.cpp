#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

enum color { brown, green, orange, red, yellow };
enum yesno { yes, no };

struct Fruit {
	char name[32];
	color cl;
	yesno annual;
	yesno perennial;
	yesno tropical;

};

void output(Fruit *fruits, int numberFruits);
void input(Fruit *fruits, int numberFruits);
void outputAnnual(Fruit *fruits, int numberFruits);
void outputPerennial(Fruit *fruits, int numberFruits);

int main()
{
	int numberFruits;
	cout << "Insert number fruits: ";
	cin >> numberFruits;
	Fruit *fruits = new Fruit[numberFruits];
	input(fruits,numberFruits);
	output(fruits,numberFruits);
	outputAnnual(fruits, numberFruits);
	outputPerennial(fruits, numberFruits);

	delete[]fruits;
	system("pause");
	return 0;
}

void outputPerennial(Fruit *fruits, int numberFruits) {
	char chooseEnum;
	cout << "Choose color(b for brown,g for green,o for orrange,r for red or y for yellow): " << endl;
	cin >> chooseEnum;
	switch (chooseEnum)
	{
	case 'b': chooseEnum = 0; break;
	case 'g': chooseEnum = 1; break;
	case 'o': chooseEnum = 2; break;
	case 'r': chooseEnum = 3; break;
	case 'y': chooseEnum = 4; break;
	}
	vector<string> stringVecV2;
	for (unsigned int i = 0; i < numberFruits; ++i)
	{
		stringVecV2.push_back(fruits[i].name);
	}
	//you shouldn't have used stl for this task -10pts
	sort(stringVecV2.begin(), stringVecV2.end());
	for (unsigned int i = 0; i < numberFruits/2; i++)
	{
		string helper;
		helper = stringVecV2[i];
		stringVecV2[i] = stringVecV2[numberFruits - 1 - i];
		stringVecV2[numberFruits - 1 - i] = helper;
	}
	for (unsigned int i = 0; i < numberFruits; ++i)
	{
		if (fruits[i].cl == chooseEnum && fruits[i].perennial == 0 && fruits[i].tropical == 0) {
			cout << stringVecV2[i] << endl;
		}
	}

}

void outputAnnual(Fruit *fruits,int numberFruits) {
	char chooseEnum;
	cout << "Choose color(b for brown,g for green,o for orrange,r for red or y for yellow): " << endl;
	cin >> chooseEnum;
	switch (chooseEnum)
	{
	case 'b': chooseEnum = 0; break;
	case 'g': chooseEnum = 1; break;
	case 'o': chooseEnum = 2; break;
	case 'r': chooseEnum = 3; break;
	case 'y': chooseEnum = 4; break;
	}
		vector<string> stringVecV1;
		for (unsigned int i = 0; i < numberFruits; ++i)
		{
			stringVecV1.push_back(fruits[i].name);
		}
		sort(stringVecV1.begin(), stringVecV1.end());
		for (unsigned int i = 0; i < numberFruits; ++i)
		{
			if (fruits[i].cl==chooseEnum && fruits[i].annual==0) {
				cout << stringVecV1[i] << endl;
			}
		}
	
}

void output(Fruit *fruits,int numberFruits) {
	for (int i = 0; i < numberFruits; i++)
	{
		cout << "Fruit number" << i + 1 << ": " << endl;
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
		cout << "Is it annual ?: ";
		switch (fruits[i].annual)
		{
		case yes: cout << "Yes" << endl; break;
		case no: cout << "No" << endl; break;
			break;
		}
		cout << "Is it perennial ?: ";
		switch (fruits[i].perennial)
		{
		case yes: cout << "Yes" << endl; break;
		case no: cout << "No" << endl; break;
			break;
		}
		cout << "Is it tropical ?: ";
		switch (fruits[i].tropical)
		{
		case yes: cout << "Yes" << endl; break;
		case no: cout << "No" << endl; break;
			break;
		}
	}
}

void input(Fruit *fruits,int numberFruits) {
	for (int i = 0; i < numberFruits; i++)
	{
		char chooseEnum;
		cout << "What is the name of the fruit ?: " << endl;
		cin >> fruits[i].name;
		do
		{
			cout << "What color is that fruit ?: ";
			cout << "Please type b for brown,g for green,o for orrange,r for red or y for yellow" << endl;
			cin >> chooseEnum;
			switch (chooseEnum)
			{
			case 'b': fruits[i].cl = brown; break;
			case 'g': fruits[i].cl = green; break;
			case 'o': fruits[i].cl = orange; break;
			case 'r': fruits[i].cl = red; break;
			case 'y': fruits[i].cl = yellow; break;
			default: cout << "Please type b for brown,g for green,o for orrange,r for red or y for yellow" << endl;
			}
		} while (chooseEnum != 'b' && chooseEnum != 'g' && chooseEnum != 'o' && chooseEnum != 'r' && chooseEnum!= 'y');
			do 
			{
				cout << "Is that fruit annual ?: ";
				cout << "Please type y for yes and n for no" << endl;
				cin >> chooseEnum;
				switch (chooseEnum)
				{
				case 'y': fruits[i].annual = yes; break;
				case 'n': fruits[i].annual = no; break;
				default: cout << "Please type y for yes and n for no" << endl;
				}
			} while (chooseEnum != 'y' && chooseEnum != 'n');
			do 
			{
				cout << "Is that fruit perennial ? :";
				cout << "Please type y for yes and n for no" << endl;
				cin >> chooseEnum;
				switch (chooseEnum)
				{
				case 'y': fruits[i].perennial = yes; break;
				case 'n': fruits[i].perennial = no; break;
				default: cout << "Please type y for yes and n for no" << endl;
				}
			} while (chooseEnum != 'y' && chooseEnum != 'n');
			do 
			{
				cout << "Is that fruit tropical ? :";
				cout << "Please type y for yes and n for no" << endl;
				cin >> chooseEnum;
				switch (chooseEnum)
				{
				case 'y': fruits[i].tropical = yes; break;
				case 'n': fruits[i].tropical = no; break;
				default: cout << "Please type y for yes and n for no";
				}
			} while (chooseEnum != 'y' && chooseEnum != 'n');

		}
	}

// 30 pts