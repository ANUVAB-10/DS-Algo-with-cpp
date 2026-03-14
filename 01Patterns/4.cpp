#include <bits/stdc++.h>
using namespace std;

// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5

void pattern1(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout << i << " ";
        }cout << endl;
    }
}

int main() {
    int n;
    cout << "enter number of rows: " ;
    cin >> n;

    pattern1(n);
}