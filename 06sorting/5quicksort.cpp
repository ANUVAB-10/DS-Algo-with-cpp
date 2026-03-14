// tc -> O(nlogn)
// sc -> o(1)

#include<bits/stdc++.h>
using namespace std;

int Fpartitioning(vector<int>&a, int low, int high) {
    int pivot = a[low];
    int i=low;
    int j=high;

    while(i<j) {
        while(a[i]<=pivot && i <= high-1) i++;
        while(a[j]>pivot && j >= low+1) j--;
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}


void quickSort(vector<int> &a, int low, int high) {
    if(low>=high) return;

    int p = Fpartitioning(a,low,high);
    quickSort(a,low,p-1);
    quickSort(a,p+1,high);

}

int main() {
    vector<int> a = {4,6,2,5,7,9,1,3};
    quickSort(a,0,a.size()-1);

    for(auto i:a) cout << i << " ";
}