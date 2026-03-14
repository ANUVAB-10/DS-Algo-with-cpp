#include <bits/stdc++.h>
using namespace std;
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
void pattern(int n) {
    for(int i=1; i<=2*n-1; i++) {

        int stars, spaces;

        if(i>n) {
             stars = 2*n-i;
             spaces = 2*i-2*n;
        }
        else if(i<=n) {
            stars = i;
            spaces = 2*n-2*i;
        }

        // stars
        for(int j=1; j<=stars; j++) {
            cout << "*";
        }
        // spaces
        for(int j=1; j<=spaces; j++) {
            cout << " ";
        }
        // stars
        for(int j=1; j<=stars; j++) {
            cout << "*";
        } cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    pattern(n);
}