#include "number.h"
#include <iostream>

using std::cout;
using std::endl;


Number::Number(){
    cout << "Constructor called" << endl;
    number = new int;
    *number = 7;
}

Number::Number(const Number &n){
    cout << "Copy constructor called" << endl;
    if(n.number == NULL){
        number = NULL;
        return;
    }
    number = new int;
    *number = *(n.number);
}

Number::~Number(){
    delete number;
    cout << "Destructor called" << endl;
}