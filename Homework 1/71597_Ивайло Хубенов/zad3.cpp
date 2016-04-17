#include<iostream>
#include<string.h>
using namespace std;
enum yn{no, yes};
enum color {brown, green , orange , red , yellow };

string swColor(short a) {
    switch (a) {
        case 0: return "brown";
        case 1: return "green";
        case 2: return "orange";
        case 3: return "red";
        case 4: return "yellow";
    }
}
string swYn(bool a) {
    if(a==0) return "no";
    if(a==1) return "yes";
}
color enterColor() {
    short a;
    do {
        cout <<"Enter color(brown = 0, green = 1, orange = 2, red = 3, yellow = 4): ";
        cin >> a;
    } while(a!= 0 && a!= 1 && a!= 2 && a!= 3 && a!= 4);
    return color(a);
}
yn enterYn() {
    short a;
    do {
        cout <<"Enter (no = 0, yes = 1): ";
        cin>>a;
    } while(a!=0 && a!=1);
    return yn(a);
}

struct Fruits {
    char name[32];
	color cl;
	yn annual;
	yn perennial;
	yn tropical;

    void input() {
        cout <<"Enter name: "; cin>>name;
        cl = enterColor();
        cout <<"Is the fruit annual? "; annual = enterYn();
        cout <<"Is the fruit perennial? "; perennial = enterYn(); //value of perennial can be deduced from the value of annual
        cout <<"Is the fruit tropical? "; tropical = enterYn();
    }
    void print() {
        cout << name <<" - "<< swColor(cl) << endl;
        cout <<"annual: " << swYn(annual) << endl;
        cout <<"perennial: " << swYn(perennial) << endl;
        cout <<"tropical: " << swYn(tropical) << endl;
    }
};

void input(Fruits* a, int n) {
    for(int i=0 ; i<n ; i++) {
        a[i].input();
    }
}

void print(Fruits a[], int n) {
    for(int i=0 ; i<n ; i++) {
        a[i].print();
    }
}

bool comp(char a[], char b[]) {  //you can just use strcmp
    int n;
    if(strlen(a) > strlen(b)) n = strlen(a);
    else n = strlen(b);
    for(int i=0 ; i<n ; i++) {
        if(a[i]<b[i]) return 1; //what happens when b[i] > a[i]?  -5pts
    }
    return 0;
}
void annualFruits(Fruits a[], int n) {
    cout<<"\nPrint all annual (color) fruits \n";
    Fruits b[10];
    int k=0;
    color c;
    c = enterColor();
    for(int i=0 ; i<n ; i++) {
        if((a[i].annual == 1) && (a[i].cl == c)) {b[k] = a[i]; k++; }
    }
    for(int i=0 ; i<k-1 ; i++) {
        char min[32];
        Fruits swap;
        strcpy(min,b[i].name);
        int p = i;
        for(int j=(i+1) ; j<k ; j++) {
            if(comp(b[j].name, min)) {strcpy(min, b[j].name); p = j;}
        }
        swap = b[i];
        b[i] = b[p];
        b[p] = swap;
    }
    print(b, k);
}

void perennialFruits(Fruits a[], int n) {
    cout<<"\nPrint all perennial (color) fruits \n";
    Fruits b[10];
    int k=0;
    color c;
    c = enterColor();
    for(int i=0 ; i<n ; i++) {
        if((a[i].perennial == 1) && (a[i].cl == c)) {b[k] = a[i]; k++; }
    }
    for(int i=0 ; i<k-1 ; i++) {
        char min[32];
        Fruits swap;
        strcpy(min,b[i].name);
        int p = i;
        for(int j=(i+1) ; j<k ; j++) {
            if(!comp(b[j].name, min)) {strcpy(min, b[j].name); p = j;}
        }
        swap = b[i];
        b[i] = b[p];
        b[p] = swap;
    }
    print(b, k);
}

int main() {
    Fruits a[10];
    int n;
    cout<<"number of fruits: "; cin >> n;
    input(a,n);
    print(a,n);
    annualFruits(a,n);
    perennialFruits(a,n);
    return 0;
}

// 35 pts