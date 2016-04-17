#include<iostream>
#include<string>
using namespace std;


enum color
{
	brown,
	green,
	orange,
	red,
	yellow,
};


//Sorry but visual studio has included method with name yn, so I cant use it in {yn annual}
//use Yn instead
enum yesorno
{
	yes,
	no
};


struct Fruit
{
	char name[32];
	color cl;
	yesorno annual;
	yesorno perennial;
	yesorno tropical;

};

//simple input -- follow the instruction.
void Input(Fruit fruits[], int length){
	for (int i = 0; i < length; i++)
	{
		string name;
		cout << "Name: ";
		cin >> name;

		strcpy_s(fruits[i].name, name.c_str());

		int temp;
		cout << "Color: [0] -> brown || [1] -> green || [2] -> orange || [3] -> red || [4] -> yellow: ";
		cin >> temp;
		fruits[i].cl = (color)temp;

		cout << "Is annual: [0] -> yes || [1] -> no: ";
		cin >> temp;
		fruits[i].annual = (yesorno)temp;

		cout << "Is perennial: [0] -> yes || [1] -> no: ";
		cin >> temp;
		fruits[i].perennial = (yesorno)temp;

		cout << "Is tropical: [0] -> yes || [1] -> no: ";
		cin >> temp;
		fruits[i].tropical = (yesorno)temp;
		
	}
}

string GetColorName(color color){
	switch (color)
	{
	case brown:
		return "brown";
	case green:
		return "green";
	case orange:
		return "orange";
	case red:
		return "red";
	case yellow:
		return "yellow";
	default:
		break;
	}
}

void Output(Fruit fruits[], int length){
	for (int i = 0; i < length; i++)
	{
		cout << "Name: " << fruits[i].name << " || color: "
			<< GetColorName(fruits[i].cl) << " || is annual?: " << ((fruits[i].annual == 0) ? "yes" : "no") << " || is perennial?: "
			<< ((fruits[i].perennial == 0) ? "yes" : "no") << " || is tropical?: " << ((fruits[i].tropical == 0) ? "yes" : "no") << endl;
	}
}

void SortByNameUp(Fruit fruits[], int length){
	for (int  i = 0; i < length; i++)
		for (int k = 0; k < length - 1; k++)
			if (strcmp(fruits[k].name, fruits[k+1].name) > 0){
				Fruit temp = fruits[k];
				fruits[k] = fruits[k + 1];
				fruits[k + 1] = temp;
			}
}

void SortByNameDown(Fruit fruits[], int length){
	for (int i = 0; i < length; i++)
		for (int k = 0; k < length - 1; k++)
			if (strcmp(fruits[k].name, fruits[k + 1].name) < 0){
				Fruit temp = fruits[k];
				fruits[k] = fruits[k + 1];
				fruits[k + 1] = temp;
			}
}

void OutputAnnualWithSelectedColor(Fruit fruits[], int length, color color){

	SortByNameUp(fruits, length);
	cout << "Annual fruits by color ---------------------------------------------------------------------" << endl;
	for (int i = 0; i < length; i++)
	{
		if (fruits[i].annual == yes && fruits[i].cl == color){
			cout << "Name: " << fruits[i].name << " || color: "
				<< GetColorName(fruits[i].cl) << " || is annual?: " << ((fruits[i].annual == 0) ? "yes" : "no") << " || is perennial?: "
				<< ((fruits[i].perennial == 0) ? "yes" : "no") << " || is tropical?: " << ((fruits[i].tropical == 0) ? "yes" : "no") << endl;
		}
	}
}

void OutputPerennialTropicalWithSelectedColor(Fruit fruits[], int length, color color){

	SortByNameDown(fruits, length);
	cout << "Perennial tropical fruits by color ---------------------------------------------------------------------" << endl;
	for (int i = 0; i < length; i++)
	{
		if (fruits[i].perennial == yes && fruits[i].cl == color && fruits[i].tropical == yes){
			cout << "Name: " << fruits[i].name << " || color: "
				<< GetColorName(fruits[i].cl) << " || is annual?: " << ((fruits[i].annual == 0) ? "yes" : "no") << " || is perennial?: "
				<< ((fruits[i].perennial == 0) ? "yes" : "no") << " || is tropical?: " << ((fruits[i].tropical == 0) ? "yes" : "no") << endl;
		}
	}
}


int main(){

	Fruit fruits[100];
	int count;
	do
	{
		cout << "Number of fruits: ";
		cin >> count;
	} while (count < 1 || count > 100);

	Input(fruits, count);
	cout << endl;
	Output(fruits, count);
	cout << endl;

	//try with red
	OutputAnnualWithSelectedColor(fruits, count, red);
	OutputPerennialTropicalWithSelectedColor(fruits, count, red);

	system("PAUSE");
	return 0;
}

// 40pts