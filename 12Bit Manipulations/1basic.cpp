#include <bits/stdc++.h>
using namespace std;

// decimal to binary
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


// binary to decimal
double decimal(string s) {
    int ans=0;
    int p=1;

    // 101
    for(int i=s.length()-1; i>=0; i--) {
        if(s[i]=='1') {
            ans+=(s[i]-'0')*p;
        }
        p*=2;
    }
    return (double)ans;
}


int main() {
    int n = 15;
    string ans = "";
    binary(n,ans);
    cout << ans << endl;

    cout << decimal("1111") << endl;
    
}