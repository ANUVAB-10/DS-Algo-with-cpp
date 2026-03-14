#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
    int c=0;
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i==0) {
            c++;
            if(n/i != i) c++;
        }
    } return c==2;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

   cout << "Is prime? " << checkPrime(n);
}