#include <iostream>

using namespace std;

//way 1
class myClass1 {
    public:
        void myMethod1() {
            cout << "Hello World!" << endl;
        }
};


//way 2
class myClass2 {
    public:
        void myMethod();
};

void myClass2::myMethod() {
    cout << "Hello World!" << endl;
}


//constructor example
class myClass {
    public:
        myClass() { //constructor
            cout << "Hello World!" << endl;
        }
};


class Car {
    public:
        string brand;
        string model;
        int year;
        Car(string x, string y, int z) {
            brand = x;
            model = y;
            year = z;
        }
};



int main() {
    myClass1 myObj;
    myObj.myMethod1();
    myClass2 myObj2;
    myObj2.myMethod();

    Car carObj1("BMW", "X5", 1999);
    Car carObj2("Ford", "Mustang", 1969);

    return 0;
}