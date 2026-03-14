#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int n) {
    int c=0;
    while(n) {
        int digit=n%10;
        c=c*10+digit;
        n/=10;
    }return c;
}


//palindrome

bool palindrome(int n) {
    return n==reverseNumber(n);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Reversed number: " << reverseNumber(n) << endl;
    cout << "Palindrome number? " << palindrome(n) << endl;

}