
#include <iostream>
#include <vector>
#include <random>
#include <algorithm> //library for sort
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::shuffle;


int main(){
    vector<int> v; //initialize an empty vector
    vector < vector<int> > v2d; //initialize an empty vector of vectors
    v.push_back(9); //add 9 to the end of the vector
    v.push_back(21);
    v.push_back(4);
    //v[34] = 1; //change the first element to 1

    // v.push_back(7);
    // v.push_back(3);

    sort(v.begin(), v.end()); //sort the vector

    cout << "Sorted:" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }


    int seed = 0;
    shuffle(v.begin(), v.end(), std::default_random_engine(seed)); //shuffle the vector

    cout << "Shuffled:" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }

    //cout << v[34] << endl;

    return 0;
}