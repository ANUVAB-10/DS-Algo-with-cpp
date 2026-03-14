#include <iostream>
using namespace std;

// parameterized recursion
int sumtoN(int n, int sum) {
    if(n<1) return sum;
    return sumtoN(n-1,sum+n);
} 


int main() {
    int n,sum=0;
    cout << " Enter limit: ";
    cin >> n;

    cout << " Sum is: " << sumtoN(n,sum);
}