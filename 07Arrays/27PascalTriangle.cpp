#include <bits/stdc++.h>
using namespace std;

int PascalElement(int r, int c) {
    
    int ans=1;
    for(int i=0; i<c-1; i++) {
        ans*=(r-i-1);
        ans/=(i+1);
    }
    return ans;
}

vector<int> WholeRow(int r) {
    vector<int>temp;
    int ans=1;
    temp.push_back(ans);
    for(int i=1; i<r; i++) {
        ans *= (r-i);
        ans /= i;
        temp.push_back(ans);
    } 
    return temp;
}


void entirePascal(int r) {
    vector<int>ans;
    cout << "PAscal triangle upto " << r << "th row" << endl;
    for(int i=1; i<=r; i++) {
        vector<int> temp;
        ans = WholeRow(i);
        for(auto i: ans) cout << i << " ";
        cout << endl;
    } 
}


int main() {
    // 1st type find req element at grivrn r and c
    int r=5, c=3;
    cout << "Exact element: " << PascalElement(r,c) << endl;


    // 2nd type print whole row
    cout << "Whole Row 6: "  << endl;
    vector<int> ans = WholeRow(6);
    for(auto i:ans) cout  << i << " ";
    cout << endl;

    // 3rd type print entire pascal for given r;
    entirePascal(r);
}