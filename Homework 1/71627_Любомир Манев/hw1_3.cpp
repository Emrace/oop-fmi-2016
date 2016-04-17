#include <iostream>
#include <cstring>
using namespace std;
/*
зад. 3
struct Fruit
{
	char name[32]; 			//име на плод, тук вече трябва да ползвате char масив
	color cl;				//цвят на плод
	yn annual; 				//едногодишен плод
	yn perennial; 			//многогодишен плод
	yn tropical;			//тропически плод
};

където
	enum color {brown, green, orange, red, yellow};
	enum yn {yes, no};

Да се напише функция, която:
а) създава едномерен масив от плодове;
б) извежда едномерен масив от плодове;
в) извежда едногодишните плодове с даден цвят, записани в масива, сортирани във възходящ ред по име на плода
г) извежда многогодишните тропически плодове с даден цвят, сортирани в низходящ ред по име на плода
*/

    enum color {brown, green, orange, red, yellow};
	enum yn {yes, no};
struct Fruit
{

	char name[32]; 			//име на плод, тук вече трябва да ползвате char масив
	color cl;				//цвят на плод
	yn annual; 				//едногодишен плод
	yn perennial; 			//многогодишен плод
	yn tropical;			//тропически плод

	Fruit(){}
	Fruit( char newName[32] , color newColor , yn newAnnual , yn newPerennial, yn newTropical )
	{
	    strcpy(name,newName);
	    cl = newColor;
	    annual = newAnnual;
	    perennial = newPerennial;
	    tropical = newTropical;
	}

	void print()
	{
	    cout<< name << " ";
	    switch(cl)
        {
        case 0:
            cout<<"brown ";
            break;
        case 1:
            cout<< "green ";
            break;
        case 2:
            cout<< "orange " ;
            break;
        case 3:
            cout<< "red " ;
        case 4:
            cout<< "yellow " ;
        }
        if( annual == yes )
        {
            cout<< "annual" << " ";
        }
        else
        {
            cout<<"not annual" << " ";
        }

        if( perennial == yes )
        {
            cout<< "perennial" << " ";
        }
        else
        {
            cout<<" not perennial" << " ";
        }

        if( tropical == yes )
        {
            cout<< "tropical" << " ";
        }
        else
        {
            cout<<" not tropical" << " ";
        }

    }



    void read()
    {
        cout<< "Enter name ";
        cin>> name;

        int tempColor;
        cout<< "brown - 1, green - 2, orange - 3, red - 4, yellow - 5 ? " <<endl;
        cin>> tempColor;
        switch(tempColor)
        {
        case 1:
            cl = brown;
            break;
        case 2:
            cl = green;
            break;
        case 3:
            cl = orange;
            break;
        case 4:
            cl = red;
        case 5:
            cl = yellow;
        }

        int tempAnnual;
        cout<< "annual - 1 yes , other - no ? ";
        cin>> tempAnnual;
        if( tempAnnual == 1 )
        {
            annual = yes;
        }else
        {
            annual = no;
        }

        int tempPerennial;
        cout<< "perennial - 1 yes, other - no ? ";
        cin>> tempPerennial;
        if( tempPerennial == 1 )
        {
            perennial = yes;
        }else
        {
            perennial = no;
        }


        int tempTropical;
        cout<< "tropical - 1 yes, other - no ? ";
        cin>> tempTropical;
        if( tempTropical == 1 )
        {
            tropical = yes;
        }else
        {
            tropical = no;
        }

    }
};


//условие а)

Fruit *createSetOfFruits( Fruit emptySet[], int howMany )
{
    for( int i = 0; i < howMany; i++ )
    {
        emptySet[i].read();
    }
return emptySet;
}

//условие б)
void printSetOfFruits (Fruit setOfFruits[] , int sizeOfSet)
{
    for(int i = 0; i < sizeOfSet; i++ )
    {
        setOfFruits[i].print();
    }
}

int getAnnualFruitsWithACertainColor ( Fruit setOfFruits[], Fruit emptySet[], int sizeOfSet , color inputColor )
{
    int counter = 0;
    for(int i = 0; i < sizeOfSet; i++)
    {
        if( setOfFruits[i].cl == inputColor && setOfFruits[i].annual == yes)
        {

            emptySet[counter] = setOfFruits[i];
            counter ++;
        }
    }
    return counter;
}

void sortFruitsByName (Fruit emptySet[] , int sizeOfSet , bool AscendingOrDescending)
{
    for(int j = 0; j < sizeOfSet - 1; j++)
    {
        char tmp[32];
        for (int i = 0; i < sizeOfSet-1; i++)
        {
            if(AscendingOrDescending)
            { //Descending
            if(strcmp(emptySet[i].name,emptySet[i+1].name) < 0 )
            {
                strcpy(tmp,emptySet[i].name);
                strcpy(emptySet[i].name,emptySet[i+1].name);
                strcpy(emptySet[i+1].name,tmp);
            }
            }
            else
            {
              //Ascending
                if(strcmp(emptySet[i].name,emptySet[i+1].name) > 0 )
            {
                strcpy(tmp,emptySet[i].name);
                strcpy(emptySet[i].name,emptySet[i+1].name);
                strcpy(emptySet[i+1].name,tmp);
            }
            }
        }
    }
}

// условие в)
//в) извежда едногодишните плодове с даден цвят, записани в масива, сортирани във възходящ ред по име на плода
void printAnnualFruitsWithColor (Fruit setOfFruits [], int sizeOfSet , color inputColor)
{
    Fruit emptySet[sizeOfSet];

    int n = getAnnualFruitsWithACertainColor(setOfFruits, emptySet, sizeOfSet , inputColor);
    sortFruitsByName(emptySet, n , 1);

    for(int i = 0; i < n; i++ )
    {
        emptySet[i].print();
        cout<<endl;
    }
}


//условие г)
//г) извежда многогодишните тропически плодове с даден цвят, сортирани в низходящ ред по име на плода
int getPerennialTropicalFruitsWithColor ( Fruit setOfFruits[], Fruit emptySet[], int sizeOfSet , color inputColor )
{
    int counter = 0;
    for(int i = 0; i < sizeOfSet; i++)
    {
        if( setOfFruits[i].cl == inputColor && setOfFruits[i].perennial == yes && setOfFruits[i].tropical == yes)
        {
            emptySet[counter] = setOfFruits[i];
            counter ++;
        }
    }
    return counter;
}

void printPerennialTropicalFruitsWithColor (Fruit setOfFruits [], int sizeOfSet , color inputColor)
{
    Fruit emptySet[sizeOfSet];

    int n = getPerennialTropicalFruitsWithColor(setOfFruits, emptySet, sizeOfSet , inputColor);
    sortFruitsByName(emptySet, n , 0);

    for(int i = 0; i < n; i++ )
    {
        emptySet[i].print();
        cout<<endl;
    }
}

int main()
{
    Fruit setOfFruits [20];
    int n = 5;
    /*
    cin>> n;
    for(int i = 0; i < n; i++ )
    {
        setOfFruits[i].read();
    }
    */

    Fruit a("psd1",brown,yes,yes,yes);
    Fruit b("ae",brown,yes,no,yes);
    Fruit c("fsd3",orange,no,yes,yes);
    Fruit d("abd4",brown,no,yes,yes);
    Fruit e("lk",brown,no,yes,yes);
    Fruit f("hj",brown,yes,no,yes);
    Fruit g("nsa",brown,yes,yes,no);

    setOfFruits[0] = a;
    setOfFruits[1] = b;
    setOfFruits[2] = c;
    setOfFruits[3] = d;
    setOfFruits[4] = e;
    setOfFruits[5] = f;
    setOfFruits[6] = g;

    printAnnualFruitsWithColor(setOfFruits,7,brown);
    cout<<endl;
    printPerennialTropicalFruitsWithColor(setOfFruits,7,brown);

    return 0;
}

//40 pts