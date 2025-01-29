

#include <iostream>

//"using namespace std;" would let you remove the std:: prefix
//"using std::cout;" would let you remove the std:: prefix for cout

//"typedef std::cout std_cout;" would let you use std_cout instead of std::cout

int main() {

    //declaring a variable
    std::string name;
    //input into the variable
    std::cin >> name;
    //output the variable
    std::cout << "hello world " << name;

    // std::cout is an object of class ostream
    // std::endl is a manipulator that ends the line
    std::cout << "hello world" << std::endl;

    printf("hello world");

    return 0;
}