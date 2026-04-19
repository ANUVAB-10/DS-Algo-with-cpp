#include<bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7 ;

// overflow stopping
long long pow_optimal(int x, int n) {
    long long ans = 1;
    while (n) {
        if(n%2) { // odd
            ans = (ans * x) % MOD;
        }
        x = (1LL * x * x) % MOD;    
        n=n/2;
    }
    return ans;
}

int countGoodNumbers(int n) {
    if(n==1) return 5;

    int oddDigits = n/2;
    int evenDigits = (1+n)/2;

    //     5^(5×10¹⁴)  →  astronomically large number
    //                 way beyond double's precision
                    
    // pow() returns wrong value
    // casting to long long gives garbage
    long long evenAns = pow_optimal(5,evenDigits);
    long long oddAns = pow_optimal(4,oddDigits);

    long long ans = (evenAns*oddAns) % MOD;
    return (int)ans;
}

int main() {
    int n=4;
    long long result = countGoodNumbers(n);
    cout << "Count of good numbers with " << n << " digits: " << result << endl;
    
    return 0;
}