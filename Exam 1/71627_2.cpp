#include <iostream>
#include <cstring>
using namespace std;

struct Product
{
private:
    string name;
    double cenaNaProdajba;
    double cenaNaKupuvane;
    int kolichestvo;
    int skladirane;

public:
    Product(){
    int kolichestvo = 100;
    int skaldirane = 0;
    double cenaNaKupuvane = 0;
    double cenaNaProdajba = 0;
    }

    Product (string _name , double _cenaNaProdajba = 0, double _cenaNaKupuvane = 0)
    {
        setName(_name);
        setCenaNaKupuvane (_cenaNaKupuvane);
        setCenaNaProdajba(_cenaNaProdajba);
        setKolichestvo(100);
        setSkladirane(0);
    }

    void setName(string _name)
    {
        name = _name;
    }

    void setCenaNaProdajba ( double _cenaNaProdajba )
    {
        cenaNaProdajba = _cenaNaProdajba;
    }

    void setCenaNaKupuvane ( double _cenaNaKupuvane )
    {
        cenaNaKupuvane = _cenaNaKupuvane;
    }

    void setKolichestvo (int _kolichestvo)
    {
        kolichestvo = _kolichestvo;
    }

    void setSkladirane (int _skladirane )
    {
        skladirane = _skladirane;
    }

    string getName()
    {
        return name;
    }

    double getCenaNaProdajba ()
    {
        return cenaNaProdajba;
    }

    double getCenaNaKupuvane()
    {
        return cenaNaKupuvane;
    }

    int getKolichestvo()
    {
        return kolichestvo;
    }

    int getSkladirane()
    {
        return skladirane;
    }

    void print()
    {
        cout << getName() << " " << " kup " << getCenaNaKupuvane() << " pr "
        << getCenaNaProdajba() << " kol " << getKolichestvo() << " sklad " << getSkladirane();
    }
};


struct Cafeteria
{
private:

    int klienti;
    double oborot;
    double harchene;

public:
    Product produkti[20];

    static const int MAX_SIZE = 100;

    Cafeteria()
    {
        klienti = 0;
        oborot = 0;
        harchene = 0;
    }

    int getKlienti()
    {
        return klienti;
    }

    double getOborot()
    {
        return oborot;
    }

    double getHarchene()
    {
        return harchene;
    }

    void setKlienti( int _klienti )
    {
        klienti = _klienti;
    }

    void setHarchene(double _harchene)
    {
        harchene = _harchene;
    }

    void setOborot(double _oborot)
    {
        oborot = _oborot;
    }

    void buy()
    {
        for(int i = 0; i < 20; i++ )
        {
            if (produkti[i].getKolichestvo() < 100 )
            {
                setHarchene( produkti[i].getCenaNaKupuvane() * (MAX_SIZE - produkti[i].getKolichestvo()) );
                produkti[i].setKolichestvo(MAX_SIZE);
                produkti[i].setSkladirane(0);
            }
        }
    }

    void sell( string _name , int _kolichestvoZaProdajba)
    {
        bool imaLiTakovaIme = 0;
        for(int i = 0; i < 20; i++ )
        {
            if( produkti[i].getName() == _name )
            {
                if( _kolichestvoZaProdajba > produkti[i].getKolichestvo() )
                {
                    _kolichestvoZaProdajba = produkti[i].getKolichestvo();
                }

                imaLiTakovaIme = 1;
                setOborot ( getOborot() + ( produkti[i].getCenaNaProdajba() * _kolichestvoZaProdajba  ) );
                setKlienti(getKlienti() + 1);
                produkti[i].setKolichestvo( produkti[i].getKolichestvo() - _kolichestvoZaProdajba );

            }
        }
        if ( !imaLiTakovaIme)
        {
            cout << " nqma produkt s tova ime " << endl;
        }

    }


   string getMostPopularProduct() // Product getMostPopular()
    {
        string _name;
        int tmpMinKolichestvo;
        for(int i = 0; i < 20; i++)
        {
            if( i == 0 )
            {
                _name = produkti[i].getName();
                tmpMinKolichestvo = produkti[i].getKolichestvo();
            }

            if(produkti[i].getKolichestvo() < tmpMinKolichestvo )
            {
                _name = produkti[i].getName();
                tmpMinKolichestvo = produkti[i].getKolichestvo();
            }
        }


        return _name;
    }

    void PrintStatistics()
    {

    for(int i = 0; i < 20; i++)
    {
        produkti[i].print();
        cout<<endl;


        cout<<endl;
    }
        cout << "klienti: " << getKlienti() << " razhodi "
        << getHarchene() << " oborot " << getOborot() <<endl;
        cout <<" pechalba " <<(  getOborot() - getHarchene() )<< endl;


    }

};


int main()
{
    /*
        string name;
    double cenaNaProdajba;
    double cenaNaKupuvane;
    int kolichestvo;
    int skladirane;
    */
/*
    Cafeteria test;
    Product product1("ime1" , 5 , 3 );
    Product product2("ime2" , 13 , 7 );
    Product product3("ime3" , 7.5 , 5 );
    Product product4("ime4" , 3 , 2 );
    Product product5("ime5" , 1 , 0.5 );


    test.produkti[0] = product1;
    test.produkti[1] = product2;
    test.produkti[2] = product3;
    test.produkti[3] = product4;
    test.produkti[4] = product5;
    test.sell("ime2",5);
    cout<< test.getMostPopularProduct();
    test.buy();
    cout<<endl;
    test.PrintStatistics();

*/
    return 0;
}
