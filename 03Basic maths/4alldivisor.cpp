#include <bits/stdc++.h>
using namespace std;

void printAllDivisor(int n) {
    for(int i=1; i<=n; i++) {
        if(n%i == 0) {
            cout << i << " ";
        }
    }cout << endl;
}

// optimised

// 1(n%i) other 36(n/i)
// 2(n%i) other 18(n/i)
// 3(n%i) other 12(n/i)
// 4(n%i) other 9(n/i)
// 6(n%i) other 6(n/i)
// repeat so upto sqrt(n)
// 9(n%i) other 6(n/i)

void printDivisor(int n) {
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i==0) {
            cout << i << " ";
            if(n/i != i) cout << n/i << " ";
        }
    } cout << endl;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

   printAllDivisor(n);
   printDivisor(n);
}