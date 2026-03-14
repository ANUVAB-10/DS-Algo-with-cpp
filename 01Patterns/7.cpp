#include <bits/stdc++.h>
using namespace std;

// flipping 1 to 0
void pattern2(int n) {
    // 1
    // 0 1
    // 1 0 1
    // 0 1 0 1
    // 1 0 1 0 1
    int start=1;
    for(int i=0; i<n; i++) {
        if(i%2==0) start=1;
        else start=0;

        for(int j=0; j<=i; j++) {
            cout << start << " ";
            start=1-start;
        } cout << endl;
    }
}

int main() {
    int n;
    cout << "enter number of rows: " ;
    cin >> n;

    pattern2(n);
}