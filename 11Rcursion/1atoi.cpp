#include <bits/stdc++.h>
using namespace std;

// " 12334" -> 12334

long long MIN = -2147483648;
long long MAX = 2147483647;

int solve(string &s, int i, long long num, int sign) {
    // base case
    if(i >= s.length() || !isdigit((unsigned char)s[i])) {  //expect either EOF or a value in range 0 to 255
        long long ans = num * sign;
        ans = (ans > MAX) ? MAX : ans;
        ans = (ans < MIN) ? MIN : ans;
        return (int)ans;
    }

    // we got nums only
    // generate nums
    num = 10*num + (s[i]-'0');

    // edgecases
    if(sign == 1 && num > MAX) return (int)MAX;
    if(sign == -1 && -num < MIN) return (int)MIN;

    return solve(s,i+1,num,sign); // always increment then and there
}

int atoi(string &s, int i=0) {
    // pass all white space
    while(i<s.length() && s[i]==' ') {
        i++;
    }

    int sign=1;
    if(i < s.length() && (s[i]=='-' || s[i]=='+')) {
        sign = (s[i]=='-') ? -1 : 1;
        i++;
    }
    // after this if not + found then positve by default
    
    return solve(s, i, 0, sign);
}

int main() {
    string s = "4193 with words" ;
    cout << atoi(s);
}