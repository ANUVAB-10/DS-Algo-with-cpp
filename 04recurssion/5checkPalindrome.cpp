#include<iostream>
using namespace std;


// use of one variable
bool checkPalindrome(string a, int i) {
    if(i >= a.size()/2) return true;
    if(a[i]!=a[a.size()-i-1]) return false;
    return checkPalindrome(a,i+1);
}

int main() {
    string s = "madam";
    cout << "Isplaindrome : " << checkPalindrome(s,0);
}