#include<bits/stdc++.h>
using namespace std;

// tc -> O(logn)^2 
int divide(int dividend, int divisor){ 

    // if equal
    if(dividend == divisor) return 1;

    // determine result sign
    bool sign = true;
    if(dividend <= 0 && divisor >=0) sign = false;
    if(dividend >= 0 && divisor <=0) sign = false;

    // abs values in 64-bit to avoid overflow
    long long n = abs(dividend); // dividend can be -2^31
    long long d = abs(divisor);

    long long ans = 0;
    // outer while
    while(n >= d) {
        int pwr = 0;
        // inner while
        while(d << (pwr+1) <= n) {
            pwr++;
        }
        ans += (1ll << pwr);
        n = n - (d*(1ll << pwr));
    }

    if(ans > INT_MAX && sign) return INT_MAX;
    if(ans < INT_MIN && sign==false) return INT_MIN;

    return sign ? ans : (-1)*ans;

}

int main () {
    int dividend = 22, divisor = 3;
    cout << "ans: " << divide(dividend, divisor) << endl;
}