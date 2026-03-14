#include <bits/stdc++.h>
using namespace std;

void pattern(int n) {
    for(int i=0; i<n; i++) {
        char c = 'A';
        for(int j=0; j<=i; j++) {
            cout << char(c+i) ;
        }cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    pattern(n);
}