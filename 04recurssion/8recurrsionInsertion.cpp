#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&a, int i, int n) {
    if(i==n-1) return;
    int j=i;
    while(j>=0 && a[j] > a[j+1]) {
        swap(a[j],a[j+1]);
        j--;
    }
    insertionSort(a,i+1,n);
}


int main() {
    vector<int> a = {4,69,2,5,87,9,0,3};
    insertionSort(a,0,a.size());

    for(auto i:a) cout << i << " ";
}