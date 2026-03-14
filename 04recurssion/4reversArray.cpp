#include<iostream>
#include<vector>
using namespace std;


// use of one variable
void reverseArray(vector<int>&a, int i) {
    if(i >= a.size()/2) return;
    swap(a[i], a[a.size()-i-1]);
    return reverseArray(a,i+1);
}

int main() {
    vector<int> a={1,2,3,4,5};
    reverseArray(a,0);

    for(auto i:a) cout << i << " ";
}