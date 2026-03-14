#include <bits/stdc++.h>
using namespace std;

void pattern(int n) {
    // A
    // A B
    // A B C
    // A B C D
    // A B C D E
    for(int i=0; i<n; i++) {
        char c = 'A';
        for(int j=0; j<=i; j++) {
            cout << c++ << " ";
        } cout << endl;
    }
}

void pattern1(int n) {
    // A B C D E
    // A B C D
    // A B C
    // A B
    // A
    for(int i=0; i<n; i++) {
        char c = 'A';
        for(int j=0; j<n-i; j++) {
            cout << c++ << " ";
        } cout << endl;
    }
}

int main() {
    // int a = int ('A');
    // cout << a << endl;
    // cout << char('A'+1);
    int n;
    cout << "Enter number of rows: ";
    cin >> n;


    pattern(n);
    pattern1(n);
}