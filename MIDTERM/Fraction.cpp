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