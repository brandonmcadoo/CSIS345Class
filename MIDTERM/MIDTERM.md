# Pointers 
```cpp
#include <iostream>
using namespace std;
int main(){
    int *x;
    x = new int;
    *x = 7;
    cout << x << " " << *x << " " << &x << endl;
    return 0;
}
```

Returns: 0x144e05eb0 7 0x16d0f70a0 <br>
x returns "0x144e05eb0" as the memory location where the 7 is stored<br>
*x returns "7" as the value stored in that memory location<br>
&x returns 0x16d0f70a0 as the memory location where adress of <br>the memory location of 7 is stored

# Class Objects
## Header
```cpp
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using std::ostream;

class Fraction {
public:
	int *num;
	int *den;
	Fraction();
	Fraction(int num);
	Fraction(int num, int den);
    Fraction(const Fraction &f);
	void print();
	void add(Fraction &f);
	void lowestTerms();
	~Fraction();
};
#endif
```
## Cpp
```cpp
#include "Fraction.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ostream;

Fraction::Fraction(){
    num = new int;
    den = new int;
    *num = 0;
    *den = 1;
}
    
Fraction::Fraction(int n){
    num = new int;
    den = new int;
    *num = n;
    *den = 1;
}
    
Fraction::Fraction(int n, int d){
    num = new int;
    den = new int;
    *num = n;
    if(d == 0) {
        *den = 1;
    } else {
        *den = d;
    }
}

Fraction::Fraction(const Fraction &f) {
    num = new int;
    den = new int;
    *num = *f.num;
    *den = *f.den;
}

void Fraction::print() {
    cout << *this->num << "/" << *this->den << endl;
}

void Fraction::add(Fraction &f) {
    int* tempNum = new int;
    int* tempDem = new int;
    
    *tempNum = *(f.num);
    *tempDem = *(f.den);
    
    int newDen = *this->den * *tempDem;
    *this->num *= *tempDem;
    *tempNum *= *this->den;
    *this->num += *tempNum;
    *this->den = newDen;
}

void Fraction::lowestTerms() {
    for(int i = *this->num; i > 0; i--){
        if(*this->num % i == 0 && *this->den % i == 0){
            *num /= i;
            *den /= i;
            break;
        }
    }
}
    
Fraction::~Fraction() {
    delete num;
    delete den;
}
```


# Operator Overload
## Header
```cpp
const Fraction& operator=(const Fraction &f);
const Fraction& operator+(const Fraction &f);
const Fraction& operator-(const Fraction &f);
const Fraction& operator*(const Fraction &f);
const Fraction& operator/(const Fraction &f);
friend Fraction operator+(const Fraction& lhs, int rhs);
friend Fraction operator+(int lhs, const Fraction& rhs);
const Fraction& operator++();
const Fraction operator++(int);
friend ostream& operator<<(ostream& out, const Fraction& f);
const Fraction operator ^ (int);
```
## Cpp
```cpp
const Fraction& Fraction::operator=(const Fraction &f){
    if(this != &f){
        if(num){
            delete num;
        }
        if(den){
            delete den;
        }
        if(f.num){
            num = new int;
            *num = *(f.num);
        } else {
            num = NULL;
        }
        if(f.den){
            den = new int;
            *den = *(f.den);
        } else {
            den = NULL;
        }
    }
    return *this;
}
const Fraction& Fraction::operator+(const Fraction &f){
    Fraction* temp = new Fraction;
    *temp = *this;
    temp->add(*const_cast<Fraction*>(&f));
    temp->lowestTerms();
    return *temp;
}

const Fraction& Fraction::operator-(const Fraction &f){
    Fraction* temp = new Fraction;
    *temp = *this;
    *temp->num *= -1;
    temp->add(*const_cast<Fraction*>(&f));
    temp->lowestTerms();
    return *temp;
}

const Fraction& Fraction::operator*(const Fraction &f){
    Fraction* temp = new Fraction;
    *temp = *this;
    *temp->num *= *f.num;
    *temp->den *= *f.den;
    temp->lowestTerms();
    return *temp;
}

const Fraction& Fraction::operator/(const Fraction &f){
    Fraction* temp = new Fraction;
    *temp = *this;
    *temp->num *= *f.den;
    *temp->den *= *f.num;
    temp->lowestTerms();
    return *temp;
}

Fraction operator+(const Fraction& lhs, int rhs) {
    int newNum = (*lhs.num) + (rhs * *lhs.den);
    int newDen = *lhs.den;
    return Fraction(newNum, newDen);
}

Fraction operator+(int lhs, const Fraction& rhs) {
    int newNum = (lhs * *rhs.den) + *rhs.num;
    int newDen = *rhs.den;
    return Fraction(newNum, newDen);
}

const Fraction& Fraction::operator++() {
    *num += *den;
    return *this;
}

const Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    *num += *den;
    return temp;
}

ostream& operator<<(ostream& out, const Fraction& f) {
    out << *f.num << "/" << *f.den;
    return out;
}

const Fraction Fraction::operator ^ (int power){
    int newNumerator = 1;
    int newDenominator = 1;
    if(power > 0){
        for(int i = 1; i < power; i++){
            newNumerator *= *num;
            newDenominator *= *den;
        }
    }
    Fraction retval(newNumerator, newDenominator);
    return retval;
}
```
### Freind method
Friend methods are used when the LHS of the signature is not a member of the class

# Inheritance
## Header
```cpp
#ifndef AA_TROOP_H
#define AA_TROOP_H

#include <iostream>
using namespace std;

class AATroop {
    public:
        int aRoll;
        int dRoll;
        int cost;
        string name;

    public:
        AATroop();
        AATroop(int aRoll, int dRoll, int cost, string name);
        AATroop(const AATroop &t);
        ~AATroop();
        void print();
        bool attackHit();
        bool defenseHit();
};

class Bomber: public AATroop {
    protected:
        int *aRoll;
        int *dRoll;
        int *cost;
        string name;

    public:
        Bomber();
        Bomber(const Bomber &t);
        ~Bomber();
        bool attackHit();
        bool defenseHit();
};

class Fighter: public AATroop {
    protected:
        int *aRoll;
        int *dRoll;
        int *cost;
        string name;

    public:
        Fighter();
        Fighter(const Fighter &t);
        ~Fighter();
        bool attackHit();
        bool defenseHit();
};

class Infantry: public AATroop {
    protected:
        int *aRoll;
        int *dRoll;
        int *cost;
        string name;

    public:
        Infantry();
        Infantry(const Infantry &t);
        ~Infantry();
        bool attackHit();
        bool defenseHit();
};

class Tank: public AATroop {
    protected:
        int *aRoll;
        int *dRoll;
        int *cost;
        string name;

    public:
        Tank();
        Tank(const Tank &t);
        ~Tank();
        bool attackHit();
        bool defenseHit();
};

#endif
```
## Cpp
```cpp
#include <iostream>
#include <random>
#include <ctime>
#include "AATroop.h"

using namespace std;

AATroop::AATroop() {

    aRoll = 0;
    dRoll = 0;
    cost = 0;
    name = "";
    srand(time(0));
}

AATroop::AATroop(int aRol, int dRol, int cos, string nam) {
    aRoll = aRol;
    dRoll = dRol;
    cost = cos;
    name = nam;
}

AATroop::~AATroop() {
   
   // delete &name;
}

void AATroop::print() {
    cout << "Name: " << name << endl;
    cout << "Attack: " << aRoll << endl;
    cout << "Defense: " << dRoll << endl;
    cout << "Cost: " << cost << endl;
}

bool AATroop::attackHit() {
    int roll = rand() % 6 + 1;
    //cout << "Attack roll: " << roll << endl;
    if(aRoll >= roll) {
        return true;
    } else {
        return false;
    }
}

bool AATroop::defenseHit() {
    int roll = rand() % 6 + 1;
    //cout << "Defense roll: " << roll << endl;
    if(dRoll >= roll) {
        return true;
    } else {
        return false;
    }
}

Bomber::Bomber():AATroop(4, 1, 15, "Bomber") {
}

Bomber::~Bomber() {
    delete aRoll;
    delete dRoll;
    delete cost;
    delete &name;
}

Fighter::Fighter():AATroop(3, 4, 12, "Fighter") {
}

Fighter::~Fighter() {
    delete aRoll;
    delete dRoll;
    delete cost;
    delete &name;
}

Infantry::Infantry():AATroop(1,2,3,"Infantry"){
}

Infantry::~Infantry() {
    delete aRoll;
    delete dRoll;
    delete cost;
    delete &name;
}

Tank::Tank():AATroop(3, 2, 5, "Tank") {
}

Tank::~Tank() {
    delete aRoll;
    delete dRoll;
    delete cost;
    delete &name;
}
```