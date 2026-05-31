#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& m) {
    int n = m.size();
    int top = 0, bottom = n-1;

    while(top < bottom) {
        if(m[top][bottom]) { // top is no celebrity
            top++;
        } 
        else if(m[bottom][top]) {
            bottom--;
        }
        else top++;
    }  
    
    // now top=bottom, so use any
    // col scanning.
    for(int i=0; i<n; i++) {
        if(i==top) continue;
        else if(!m[i][top]) return -1;
    }
    //  row scanning
    for(int i=0; i<m[0].size(); i++) {
        if(m[top][i]) return -1;
    }

    return top;
}


int main() {
    vector<vector<int>> M = {
         {0, 1, 1, 0}, 
         {0, 0, 0, 0}, 
         {1, 1, 0, 0}, 
         {0, 1, 1, 0}
    };
    
    
    int ans = celebrity(M);
    
    cout << "The index of celebrity is: " << ans;
    
    return 0;
}