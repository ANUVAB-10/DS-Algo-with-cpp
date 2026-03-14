#include <bits/stdc++.h>
using namespace std;

// keys are unique

int main() {
    map<int, int> mp;
    mp[1]=2;
    // mp.emplace({3,1});
    mp.insert({2,4});
    // map stores unque keys in sorted orders

    auto it = mp.find(4);
    // returns iterator if not found points to after the map


}