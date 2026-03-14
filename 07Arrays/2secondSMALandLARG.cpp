#include <bits/stdc++.h>
using namespace std;

pair<int,int> f(vector<int>a) {
    int max=INT_MIN;
    int min=INT_MAX;
    for(auto i:a) {
        if(i>max) max=i;
        if(i<min) min=i;
    }
    int secondMax=INT_MIN, secondMin=INT_MAX;
    for(auto i:a) {
        if(i>secondMax && i!=max) {
            secondMax=i;
        }
    } for(auto i:a) {
        if(i<secondMin && i!=min) {
            secondMin=i;
        }
    }
    return make_pair(secondMax,secondMin);
}

int main() {
    vector<int> a = {2,5,1,3,0};
    cout << "second largest: " << f(a).first << " second smallest: " << f(a).second;
}
