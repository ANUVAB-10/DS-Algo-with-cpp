#include <bits/stdc++.h>
using namespace std;

void pattern1(int n) {
    
    // 1->n-1space ,1 star,n-1space
    // 2->n-2space, 3 (2i-1) star
    // 3->n-2space, 5(2i-1) star
    // 4->n-1 space, 7(2i-1) star
    //    *
    //   ***
    //  *****
    // *******
    // *********
    for(int i=1; i<=n; i++) {
        for(int j=1;j<=n-i;j++) {
            cout << " ";
        } 
        for(int k=1; k<=(2*i-1); k++) {
            cout << "*" ;
        } cout << endl;
    }
}


void pattern2(int n) {
    // 1->(5)2n-i+1 star (0) i-1 space
    // 2->(3)2n-i+1 star (1) i-1 space
    // 3 ->(1) 2i-1
    for(int i=1; i<=n; i++) {
        for(int j=1;j<=i-1;j++) {
            cout << " ";
        } 
        for(int k=(2*n-2*i+1); k>=1; k--) {
            cout << "*" ;
        } 
        for(int j=1;j<=i-1;j++) {
            cout << " ";
        } cout << endl;
    }
}
int main() {
    int n;
    cout << "enter number of rows: " ;
    cin >> n;

    pattern1(n);
    pattern2(n);
}