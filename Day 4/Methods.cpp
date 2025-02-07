#include <iostream>
#include "main.h"

//the method or the method signature (void print2();) needs ot be before where it is called/referenced
void print2(){
    std::cout << "Hello World!" << std::endl;
}

int main(){
    print();
    print2();
    return 0;
}