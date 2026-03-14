#include <bits/stdc++.h>
using namespace std;

// vector is implemented as a single ll

void print(vector<int>a) {
    // easy
    for(auto i:a) {
        cout << i << " ";
    } cout << endl;
}

int main() {
    vector<int> a = {10,20,30,40};

    // begin
    vector<int>::iterator it = a.begin();
    it++;
    cout << *it << endl ;

    // a.end() points after the last element 
    vector<int>::iterator b = a.end();
    cout << *(--b) << endl;

    for(vector<int>::iterator it = a.begin(); it!=a.end(); it++) {
        cout << *it << " ";
    } cout << endl;
    

    // erase
    // onr way
    a.erase(a.begin()); // reshuffles after erase
    print(a);


    // portion erase
    a.erase(a.begin(), a.begin()+2) ;// [start,end)
    print(a);

    // insert 
    a.insert(a.begin(),61);
    print(a);

    // insert multiple element;
    a.insert(a.begin()+1, 2, 5); // insert 2 5's after begin
    print(a);

    // inserting a whole ass vector
    vector<int> copy = {15,7};
    a.insert(a.end(), copy.begin(),copy.end());
    print(a);

    // other functions
    cout << a.size() << endl;

    a.pop_back();

    a.swap(copy);

    a.clear();

    
}