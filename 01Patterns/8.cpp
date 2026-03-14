#include <bits/stdc++.h>
using namespace std;
void pattern2(int n) {
    // 1       1
    // 12     21
    // 123   321
    // 1234 4321
    // 1234554321
    for(int i=1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout << j  ;
        }
        for(int k=1; k<2*n-2*i; k++) {
            cout << " " ;
        }
        for(int j = i; j>=1; j--) {
            cout << j ;
        } cout << endl;
    }
}

int main() {
    int n;
    cout << "enter number of rows: " ;
    cin >> n;

    pattern2(n);
}