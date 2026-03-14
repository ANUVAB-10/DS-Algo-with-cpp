#include <bits/stdc++.h>
using namespace std;

void pattern(int n) {
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
    for(int i=1; i<=n; i++) {
        //space -> n-i
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }
        // left side alphabets -> 1to<=i;
        for(int j=1; j<=i; j++) {
            cout << char('A'+j-1);
        } 
        // right side alphabets -> 1 to <i
        char ch='A';
        for(int j=i-1; j>=1; j--) {
            cout << char('A' + j - 1);

        } cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    pattern(n);
}