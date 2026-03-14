#include <bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    if(!n) return 1;
    int c=0;
    while(n) {
        c++;
        n/=10;
    }return c;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Digits are: " << countDigits(n);
}