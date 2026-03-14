#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>&a) {
    int n = a.size();
    int j=-1;

    // find first 0
    for(int i=0; i<n; i++) {
        if(a[i]==0) {
            j=i; // label its index as j
            break;
        }
    }

    if(j==-1) return;

    // make another index i beside j
    int i=j+1;
    while(i<n) {
        // jsut swap if i has non zero emls
        if(a[i]!=0) {
            swap(a[i],a[j]);
            j++;
        }i++;
    }
}

int main() {
    vector<int> a = {1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
    moveZeroes(a);
    for(auto i:a) cout << i << " ";
}