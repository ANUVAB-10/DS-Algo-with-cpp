#include <bits/stdc++.h>
using namespace std;


void pattern1(int n) {
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout << j << " ";
        } cout << endl;
    }
}
void pattern2(int n) {
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
    for(int i=0; i<n; i++) {
        for(int j=1; j<=n-i; j++) {
            cout << j << " ";
        } cout << endl;
    }
}

int main() {
    int n;
    cout << "enter number of rows: " ;
    cin >> n;

    // pattern1(n);
    pattern2(n);
}