#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int target = 73;
    int answer;
    do{
        cout << "Guess a number: ";
        cin >> answer;
        cout << ((answer > target) ? "lower" : ((answer < target) ? "higher" : "correct, you win")) << endl;
    } while(answer - target);

    return 0;
}