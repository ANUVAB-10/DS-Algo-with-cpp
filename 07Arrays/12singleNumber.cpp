#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>a) {
    int ans=0;
    for(auto i:a) ans=ans^i;
    return ans;
}

int main() {
    vector<int> a = {4,1,2,1,2};
    cout << "single number: " << singleNumber(a);
}