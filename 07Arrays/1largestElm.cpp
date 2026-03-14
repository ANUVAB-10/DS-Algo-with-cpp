#include <bits/stdc++.h>
using namespace std;

int maxElm(vector<int>a) {
    int max=INT_MIN;
    for(auto i:a) {
        if(i>max) max=i;
    }return max;
}

int main() {
    vector<int> a = {2,5,1,3,0};
    cout << maxElm(a);
}
