#include <bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2) {
    while(n1 && n2) {
        if(n1>n2) n1=n1%n2;
        else n2=n2%n1;
    }
    if(!n2) return n1;
    return n2;
}

int main() {
    int n1,n2;
    cout << "Enter number: ";
    cin >> n1 >> n2;

   cout << "GCD is: " << gcd(n1,n2);
}