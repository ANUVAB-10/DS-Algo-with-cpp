#include <bits/stdc++.h>
using namespace std;

void leftRotate(vector<int>&a) {
    int temp=a[0];
    for(int i=1; i<=a.size()-1; i++) {
        a[i-1]=a[i];
    }a[a.size()-1]=temp;
    
    for(auto i:a) cout << i << " ";
}

int main() {
    vector<int>a = {1,2,3,4,5};
    leftRotate(a);
}