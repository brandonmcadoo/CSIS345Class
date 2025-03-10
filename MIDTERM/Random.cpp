#include <iostream>
using namespace std;

int main(){
    int *x;
    x = new int;
    *x = 7;
    cout << x << " " << *x << " " << &x << endl;

    return 0;
}
//output:      0x144e05eb0 7 0x16d0f70a0
//x: the adress of the memory location where the value 7 is stored
//*x: the value stored in the memory location
//&x: the adress of the memory location where the adress of the memory location where the value 7 is stored