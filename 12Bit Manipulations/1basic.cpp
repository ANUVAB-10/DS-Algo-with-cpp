#include <bits/stdc++.h>
using namespace std;

void binary(int n, string &ans) {
    if(!n) {
        ans.push_back('0');
        return;
    }
    while(n!=1) {
        int rem = n%2;
        ans.push_back(rem+'0');
        n=n/2;
    }
    ans.push_back('1');
    reverse(ans.begin(),ans.end());
}

int main() {
    int n = 15;
    string ans = "";
    binary(n,ans);
    cout << ans;
}