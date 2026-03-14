#include <bits/stdc++.h>
using namespace std;

void pattern(int n) {
    // E
    // D E
    // C D E
    // B C D E
    // A B C D E
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            char ch = char('A'+n-(i+1));
            cout << char(ch+j) << " ";
        }cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    pattern(n);
}

