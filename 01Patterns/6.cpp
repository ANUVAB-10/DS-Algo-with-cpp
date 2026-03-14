#include <bits/stdc++.h>
using namespace std;

void pattern1(int n) {
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
    if(n%2) {
        for(int i=1; i<=(2*n-1); i++) {
            int k=i;
            if(i>n) k=2*n-i;

            for(int j=1; j<=k; j++) {
                cout << "*";
            } cout << endl;
        }
    } else {
        cout << "valid for odd rows" << endl;
    }
}


int main() {
    int n;
    cout << "enter number of rows: " ;
    cin >> n;

    pattern1(n);
}