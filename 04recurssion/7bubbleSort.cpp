#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&a, int n) {
    if(n==1) return;
    for(int j=0; j<n-1; j++) {
        if(a[j] > a[j+1]) swap(a[j],a[j+1]);
    }
    bubbleSort(a,n-1);
}


int main() {
    vector<int> a = {4,6,2,5,87,9,1,3};
    bubbleSort(a,a.size());

    for(auto i:a) cout << i << " ";
}