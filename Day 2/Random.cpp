#include <iostream>
#include <cstdlib> //library for random number generation
#include <ctime> //library for time
using std::cout;
using std::endl;

int main(){
    srand48(time(0)); //seed the random number generator
    cout << drand48() << endl;
    cout << (int)(drand48() * 100) << endl;

    srand(time(0)); //seed the random number generator
    // for(int i = 0; i < 20; i++){
    //     cout << rand() << endl;
    // }
    cout << rand() << endl;
}