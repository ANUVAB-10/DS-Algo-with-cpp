#include <bits/stdc++.h>
using namespace std;

void unionArrs(vector<int>a, vector<int>b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> unionArr;

    int i=0,j=0;
    while(i<n1 && j<n2) {
        if(a[i] <= b[j]) {
            if(unionArr.empty() || unionArr.back()!=a[i] ) {
                unionArr.push_back(a[i]);
            }
            i++;
        } 
        else {
            if( unionArr.empty() || unionArr.back()!=b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while(i<n1) {
        if(unionArr.back()!=a[i]) {
            unionArr.push_back(a[i]);
        }i++;
    }

    while(j<n2) {
        if(unionArr.back()!=b[j]) {
            unionArr.push_back(b[j]);
        }j++;
    }

    for(auto i:unionArr) cout << i << " ";

}

int main() {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {2,3,4,4,5};

    unionArrs(a,b);
}