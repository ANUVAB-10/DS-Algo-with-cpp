#include <bits/stdc++.h>
using namespace std;

void intersection(vector<int>a, vector<int>b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> ans;

    int i=0,j=0;
    while(i<n1 && j<n2) {
        if(a[i] < b[j]) {
            i++;
        } 
        else if(a[i] > b[j]) {
            j++;
        }
        else {
            if(ans.empty() || ans.back()!=a[i]) {
                ans.push_back(a[i]);
            } 
            i++;
            j++;
        }
    }

    for(auto i:ans) cout << i << " ";

}

int main() {
    vector<int> a = {1,2,2,3,3,4,5,6};
    vector<int> b = {2,3,3,5,6,6,7};

    intersection(a,b);
}