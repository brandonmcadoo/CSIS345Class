#include <iostream>
#include "number.h"

using std::cout;
using std::endl;

int main(){
    Number n1;
    Number n2 = n1;
    Number n3, n4;
    n3 = n4;
    cout << "Hello World" << endl;
    return 0;
}