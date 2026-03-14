#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>a) {
    int gc=0,c=0;
    for(auto i:a) {
        if(i) c++;
        if(!i) c=0;
        gc=max(gc,c);
    }
    return gc;
} 

int main() {
    vector<int> a = {1, 1, 0, 1, 1, 1};
    cout << "max consecutive 1's: " << findMaxConsecutiveOnes(a);
}