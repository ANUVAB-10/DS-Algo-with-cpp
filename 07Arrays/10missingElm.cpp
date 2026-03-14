#include <bits/stdc++.h>
using namespace std;
// tc -> O(N) sc -> O(1)
int missingNum(vector<int>a) {
    int n=a.size()+1;
    int arrSum=0;
    long expSum=0;

    // array sum
    for(auto i:a) {
        arrSum+=i;
    }

    // actual sum
    expSum = n*(n+1)/2;

    return expSum-arrSum;

}

int main() {
    vector<int> arr = {1, 2, 3, 5};  
    cout << missingNum(arr);  
    return 0;
}