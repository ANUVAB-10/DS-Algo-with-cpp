#include <iostream>
using namespace std;

// print 1 to N but not bu i+1
void print1_N(int n) {
    if(n < 1) return ;
    print1_N(n-1);
    cout << n << " ";
} 

// print N to 1 but not bu i-1
void printN_1(int i, int n) {
    if(i>n) return ;
    printN_1(i+1,n);
    cout << i << " ";
}

int main() {
    int n;
    cout << " Enter limit: ";
    cin >> n;

    print1_N(n);
    cout << endl;
    printN_1(1,n);
}