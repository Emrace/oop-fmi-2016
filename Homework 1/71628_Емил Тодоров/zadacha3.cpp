#include <iostream>
#include <string>
#include <cstring>
using namespace std;
enum color {brown, green, orange, red, yellow};
enum yesNo {yes, no};
string _yesNo;
string _color;

struct Fruit {
    char name[32];
    color cl;
    yesNo annual;
    yesNo perennial;
    yesNo tropical;
    void read(Fruit* arr,int size);
    void print(Fruit* arr,int size);

    Fruit(char* _name=" "){
    strcpy(name,_name);
    }
};



void Fruit::read(Fruit* arr,int size){
    for(int i=0;i<size;i++){
        cout<<"Enter fruit name: ";
        cin>>arr[i].name;
        color a;
        cout<<"Enter fruit color: ";
        cin>>_color;
        if(_color=="brown") {
            arr[i].cl=brown;
        }
        else if(_color=="green"){
            arr[i].cl=green;
        }
        else if(_color=="orange"){
            arr[i].cl=orange;
        }
        else if(_color=="red"){
            arr[i].cl=red;
        }
        else if(_color=="yellow"){
            arr[i].cl=yellow;
        }
        cout<<"Is it annual: ";
        cin>>_yesNo;
        if(_yesNo=="yes"){
            arr[i].annual=yes;
        }
          if(_yesNo=="no"){
            arr[i].annual=no;
        }
        cout<<"Is it perennial: ";
        cin>>_yesNo;
        if(_yesNo=="yes"){
            arr[i].perennial=yes;
        }
        if(_yesNo=="no"){
            arr[i].perennial=no;
        }
        cout<<"Is it tropical: ";
        cin>>_yesNo;
        if(_yesNo=="yes"){
            arr[i].tropical=yes;
        }
          if(_yesNo=="no"){
            arr[i].tropical=no;
        }
        cout<<endl;
    }
}



void Fruit::print(Fruit* arr,int size){
    for(int i=0;i<size;i++)
    {
        if(arr[i].name!=""){
            cout<<arr[i].name<<endl;
            switch (arr[i].cl){
                case brown: cout<< "Fruit's color: BROWN \n"; break;
                case green: cout<< "Fruit's color: GREEN \n"; break;
                case orange: cout<< "Fruit's color: ORANGE \n"; break;
                case red: cout<< "Fruit's color: RED \n"; break;
                case yellow: cout<< "Fruit's color: YELLOW \n"; break;
            }
            switch(arr[i].annual){
                case yes: cout<<"Annual \n"; break;
                case no: cout<<"Not Annual \n"; break;
            }
            switch(arr[i].perennial){
                case yes: cout<<"Perennial \n"; break;
                case no: cout<<"Not Perennial \n"; break;
            }
            switch(arr[i].tropical){
                case yes: cout<<"Tropical \n"; break;
                case no: cout<<"Not Tropical \n"; break;
            }
            cout<<endl;
        }
    }
}

void sortAnnualByColorAndByName(Fruit* arr,int size,Fruit* arr2,color c){
    int counter=0;
    for(int i=0;i<size;i++){
        if(arr[i].name==""){
            break;
        }
        else{
            if(arr[i].annual==yes && arr[i].cl==c ){
            strcpy(arr2[counter].name,arr[i].name);
            arr2[counter].cl=arr[i].cl;
            arr2[counter].annual=arr[i].annual;
            arr2[counter].perennial=arr[i].perennial;
            arr2[counter].tropical=arr[i].tropical;
            counter++;
            }
        }
    }
    int result;
    for(int i=0;i<size-1;++i)
    {
        for(int j=0;j<size-1;++j)
        {
            result=strcmp(arr2[j].name,arr2[j+1].name);
            if(result>0){
                char swap[32]="";
                strcpy(swap,arr2[j].name);
                strcpy(arr2[j].name,arr2[j+1].name);
                strcpy(arr2[j+1].name,swap);
            }
        }
    }
}

void sortedPerennialByColorAndNamesReversed(Fruit* arr,int size,Fruit* arr2,color c){
   int counter=0;
    for(int i=0;i<size;i++){
        if(arr[i].name==""){
            break;
        }
        else{
            if(arr[i].perennial==yes && arr[i].cl==c ){
            strcpy(arr2[counter].name,arr[i].name);
            arr2[counter].cl=arr[i].cl;
            arr2[counter].annual=arr[i].annual;
            arr2[counter].perennial=arr[i].perennial;
            arr2[counter].tropical=arr[i].tropical;
            counter++;
            }
        }
    }
    int result;
    for(int i=size-1;i>0;--i)
    {
        for(int j=size-1;j>0;--j)
        {
            result=strcmp(arr2[j].name,arr2[j-1].name);
            if(result>0){
                char swap[32]="";
                strcpy(swap,arr2[j].name);
                strcpy(arr2[j].name,arr2[j-1].name);
                strcpy(arr2[j-1].name,swap);
            }
        }
    }
}

int main(){
    const int numberOfFruits = 2;
    const color colorYouWantToSortBy=yellow;
    Fruit a[numberOfFruits];
    Fruit b[numberOfFruits];
    Fruit c[numberOfFruits];
    a[0].read(a,numberOfFruits);
    a[0].print(a,numberOfFruits);
    a[0].read(a,numberOfFruits);
    a[0].print(a,numberOfFruits);
    cout<<endl;
    cout<<"Yellow annual fruits sorted by name: " <<endl;
    cout<<"==================="<<endl;
    sortAnnualByColorAndByName(a,numberOfFruits,b,colorYouWantToSortBy);
    b[0].print(b,numberOfFruits);
    cout<<"Yellow perennial fruits sorted by name reversed: " <<endl;
    cout<<"==================="<<endl;
    sortedPerennialByColorAndNamesReversed(a,numberOfFruits,c,colorYouWantToSortBy);
    c[0].print(c,numberOfFruits);

    return 0;
}
// 40 pts