#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Triangle
{
private:
	double a, b, c;
public:
	void create(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}
	double getX()
	{
		return a;
	}
	double getY()
	{
		return b;
	}
	double getZ()
	{
		return c;
	}
	void print()
	{
		cout << "a= " << getX() << endl;
		cout << "b= " << getY() << endl;
		cout << "c= " << getZ() << endl;
	}
	double surface()
	{
		double S;
		double p;
		p = perimeter() / 2;
		S = sqrt(p*(p - a)*(p - b)*(p - c));
		return S;
	}
	double perimeter()
	{
		double P;
		P = a + b + c;
		return P;
	}
	Triangle mult_k(int k)
	{
		Triangle p;
		p.create(a*k, b*k, c*k);
		return p;
	}


};
int main()
{



	Triangle triangle;
	triangle.create(3, 4, 5);
	triangle.print();
	cout << "The surface of the triangle is: " << triangle.surface() << endl;
	cout << "The triangle perimeter is: " << triangle.perimeter() << endl;
	Triangle p;
	p = triangle.mult_k(5);
	Triangle triangles[20];
	for (int i = 0;i < 20;i++)
	{
		double a, b, c;
		cout << "please enter a: ";
		cin >> a;
		cout << "please enter b: ";
		cin >> b;
		cout << "please enter c: ";
		cin >> c;
		if ((a + b) > c || (b + c) > a || (a + c) > b)
		{
			triangles[i].create(a, b, c);
		}
		else
		{
			cout << "Invalid triangle parameters!";
			return 0;
		}


	}
	double maxP = triangles[0].perimeter(), minS = triangles[0].surface();
	for (int i = 1;i < 20;i++)
	{
		if (maxP < triangles[i].perimeter())
		{
			maxP = triangles[i].perimeter();
		}
		if (minS > triangles[i].surface())
		{
			minS = triangles[i].surface();
		}

	}
	cout << "The maximum perimeter is: " << maxP << endl;
	cout << "The minimum surface is:" << minS << endl;
	Triangle trianglesMult[20];
	for (int i = 1;i <=20;i++)
	{
		trianglesMult[i - 1] = triangles[i - 1].mult_k(i);
	
	}
	
	system("pause");
	return 0;
}

//20 pts

struct Planet
char name[] //ìîæå äà ñå èçïîëçâà è string
double distance, diameter, mass
void read() - âúâåæäà äàííè çà ïëàíåòà
void print() - èçâåæäà äàííèòå çà ïëàíåòà
ôóíêöèÿ, êîÿòî âðúùà êàòî ðåçóëòàò áðîÿ ñåêóíäè, êîèòî ñà íåîáõîäèìè íà ñâåòëèíàòà äà äîñòèãíå îò ñëúíöåòî äî ïëàíåòàòà
ïðèåìåòå, ÷å C = 299 792 km/s, à distance å çàäàäåíî â êèëîìåòðè

Äà ñå íàïèøå ïðîãðàìà, êîÿòî:
à) âúâåæäà ìíîæåñòâî îò ïëàíåòè, ðåàëèçèðàíî ÷ðåç åäíîìåðåí ìàñèâ
á) èçâåæäà äàííèòå çà ïëàíåòèòå îò ìíîæåñòâîòî
â) íàìèðà ïëàíåòàòà ñ íàé-ãîëÿì äèàìåòúð
ã) íàìèðà ïëàíåòàòà ñ íàé-ìàëêà ìàñà
ä) íàìèðà ïëàíåòàòà, äî êîÿòî ñâåòëèíàòà äîñòèãà ïîñëåäíà


struct Planet
{
private:
	string name;
	double distance, diameter, mass;
public:
	double getDiam()
	{
		return diameter;
	}
	double getM()
	{
		return mass;
	}
	double getDist()
	{
		return distance;
	}

	void read()
	{
		cout << "Enter the planet's name:";
		cin >> name;
		cout << "Enter the distance to Earth:";
		cin >> distance;
		cout << "Enter the diameter of the planet: ";
		cin >> diameter;
		cout << "Enter the mass of the planet:";
		cin >> mass;

	}
	void print()
	{
		cout <<"The name of the planet is: " << name << endl;
		cout << "The distance to the planet is: " << distance << endl;
		cout << "The diameter of the planet is: " << diameter << endl;
		cout << "The mass of the planet is: " << mass << endl;
		
	}
	double sunToPlanet()
	{
		const int C = 299792;
		double sec;
		sec = distance / C;
		return sec;
	}
};
int main()
{
	Planet planets[5];
	for (int i = 0;i < 5;i++)
	{
		planets[i].read();

	}
	for (int i = 0;i < 5;i++)
	{
		planets[i].print();
	}
	double biggestD = planets[0].getDiam(), minM = planets[0].getM(), lastPlanet = planets[0].sunToPlanet();
	for (int i = 0;i < 5;i++)
	{
		if (biggestD < planets[i].getDiam())
		{
			biggestD = planets[i].getDiam();
		}
		if (minM > planets[i].getM())
		{
			minM = planets[i].getM();
		}
		if (lastPlanet < planets[i].sunToPlanet())
		{
			lastPlanet = planets[i].sunToPlanet();
		}
	}
	cout << "The biggest planet is: " << biggestD << endl;
	cout << "The planet with the smallest mass is: " << minM << endl;
	cout << "The furthest planet from the Sun is:" << lastPlanet << endl;
	system("pause");
	return 0;
}
 
// 40 pts

 struct Fruit
 {
 char name[32]; 			//èìå íà ïëîä, òóê âå÷å òðÿáâà äà ïîëçâàòå char ìàñèâ
 color cl;				//öâÿò íà ïëîä
 yn annual; 				//åäíîãîäèøåí ïëîä
 yn perennial; 			//ìíîãîãîäèøåí ïëîä
 yn tropical;			//òðîïè÷åñêè ïëîä
 };

 êúäåòî
 enum color {brown, green, orange, red, yellow};
 enum yn {yes, no};

 Äà ñå íàïèøå ôóíêöèÿ, êîÿòî:
 à) ñúçäàâà åäíîìåðåí ìàñèâ îò ïëîäîâå;
 á) èçâåæäà åäíîìåðåí ìàñèâ îò ïëîäîâå;
 â) èçâåæäà åäíîãîäèøíèòå ïëîäîâå ñ äàäåí öâÿò, çàïèñàíè â ìàñèâà, ñîðòèðàíè âúâ âúçõîäÿù ðåä ïî èìå íà ïëîäà
 ã) èçâåæäà ìíîãîãîäèøíèòå òðîïè÷åñêè ïëîäîâå ñ äàäåí öâÿò, ñîðòèðàíè â íèçõîäÿù ðåä ïî èìå íà ïëîäà
 
struct Fruit
{
public:
	enum yn {
		yes,
		no
	};
	enum color {
		brown = 0,
		green = 1,
		orange = 2,
		red = 3,
		yellow = 4
	};
private:
	char name[32];
	
	color cl;
	
	yn annual;
	yn perennial;
	yn tropical;
public:
	color getColor()
	{
		return cl;
	}
	yn getAnnual()
	{
		return annual;
	}
	yn getPerennial()
	{
		return perennial;
	}
	yn getTropical()
	{
		return tropical;
	}
	char* getName()
	{
		return name;
	}
	void read()
	{
		cout << "Enter the fruit's name: ";
		cin >> name;
		int color;
		cout << "Enter the fruit's color(0: brown, 1: green, 2: orange, 3: red, 4: yellow): ";
		cin >> color;
		cl = convertIntToColor(color);
		string stringYn;
		cout << "Is the fruit annual(enter 'yes' or 'no'): ";
		cin >> stringYn;
		annual = convertStringToYn(stringYn);
		cout << "Is the fruit perennial(enter 'yes' or 'no'): ";
		cin >> stringYn;
		perennial = convertStringToYn(stringYn);
		cout << "Is the fruit tropical(enter 'yes' or 'no'): ";
		cin >> stringYn;
		tropical = convertStringToYn(stringYn);
	}
	color convertIntToColor(int color)
	{
		switch (color)
		{
		case 0:
			return color::brown;
		case 1:
			return color::green;
		case 2:
			return color::orange;
		case 3:
			return color::red;
		case 4:
			return color::yellow;
		}
		return color::brown;
	}
	yn convertStringToYn(string ynString)
	{
		if (ynString == "yes" || ynString == "Yes" || ynString == "y" || ynString == "Y")
		{
			return yn::yes;
		}
		else
		{
			return yn::no;
		}
	}
	void print()
	{
		cout << "The name of the fruit is: " << name << endl;
		cout << "The color of the fruit is: " << colorToString(cl) << endl;

		printHelper("annual", annual);
		printHelper("perennial", perennial);
		printHelper("tropical", tropical);
	}
	string colorToString(color color)
	{
		switch (color)
		{
		case 0:
			return "brown";
		case 1:
			return "green";
		case 2:
			return "orange";
		case 3:
			return "red";
		case 4:
			return "yellow";
		}
		return "brown";
	}
	void printHelper(string type, yn yn)
	{
		cout << "The fruit is ";
		if (yn == yn::no)
		{
			cout << "not ";
		}
		cout << type << "." << endl;
	}
};
int main()
{
	const int numOfFruits = 5;
	const Fruit::color chosenColor = Fruit::color::green;
	const Fruit::color chosenColor2 = Fruit::color::orange;

	Fruit fruits[numOfFruits];
	for (int i = 0;i < numOfFruits;i++)
	{
		fruits[i].read();

	}
	cout << "----------------------------------------------" << endl;
	cout << "----------------The Fruits Are----------------" << endl;
	cout << "----------------------------------------------" << endl;
	for (int i = 0;i < numOfFruits;i++)
	{
		fruits[i].print();
		cout << "----------------------------------------------" << endl;

	}
	cout << "---------" << fruits[0].colorToString(chosenColor) << " and Annual Fruits Are----------" << endl;
	cout << "----------------------------------------------" << endl;

	Fruit fruits2[numOfFruits];
	int tempCounter = 0;
	for (int i = 0;i <= numOfFruits;i++)
	{
		if (fruits[i].getAnnual() == Fruit::yn::yes && fruits[i].getColor() == chosenColor)
		{
			fruits2[tempCounter] = fruits[i];
			tempCounter++;
		}
	}
	Fruit tempFruit;
	for (int i = 0; i < tempCounter; i++)
	{
		for (int j = i+1; j < tempCounter; j++)
		{
			if (strcmp(fruits2[i].getName(), fruits2[j].getName()) > 0)
			{
				tempFruit = fruits2[i];
				fruits2[i] = fruits2[j];
				fruits2[j] = tempFruit;		
			}
		}
	}
	for (int i = 0; i < tempCounter; i++)
	{
		fruits2[i].print();
		cout << "----------------------------------------------" << endl;
	}
	cout << "------Perennial, Tropical and " << fruits[0].colorToString(chosenColor2) << " Are------" << endl;
	cout << "----------------------------------------------" << endl;
	Fruit fruits3[numOfFruits];
	tempCounter = 0;
	for (int i = 0;i <= numOfFruits;i++)
	{
		if (fruits[i].getPerennial() == Fruit::yn::yes && fruits[i].getTropical() == Fruit::yn::yes && fruits[i].getColor() == chosenColor2)
		{
			fruits3[tempCounter] = fruits[i];
			tempCounter++;
		}
	}
	for (int i = 0; i < tempCounter; i++)
	{
		for (int j = i + 1; j < tempCounter; j++)
		{
			if (strcmp(fruits3[i].getName(), fruits3[j].getName()) < 0)
			{
				tempFruit = fruits3[i];
				fruits3[i] = fruits3[j];
				fruits3[j] = tempFruit;
			}
		}
	}
	for (int i = 0; i < tempCounter; i++)
	{
		fruits3[i].print();
		cout << "----------------------------------------------" << endl;
	}
	system("PAUSE");
	return 0;
}




// 40 pts


