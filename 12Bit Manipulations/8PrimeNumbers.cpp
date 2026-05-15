#include<bits/stdc++.h>
using namespace std;

// tc -> O(sqrt(n) + logn)
vector<int> primeFactor(int n) {
    vector<int> ans;

    for(int i=2; i<=sqrt(n); i++) {
        if(n % i == 0) {
            ans.push_back(i);
            while(n % i == 0) n/=i;
        }
    }
    if(n!=1) ans.push_back(n);
    return ans;
}

int main() {
    int n = 16;

    vector<int> ans = primeFactor(n);

    cout << "prime factors: " ;
    for(auto i:ans) {
        cout << i << " ";
    } cout << endl;
}