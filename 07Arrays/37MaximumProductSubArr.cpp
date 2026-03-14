#include <bits/stdc++.h>
using namespace std;

// tc -> O(n*n);
int maxProduct_BRUTE_FORCE(vector<int> nums) {
    int maxProd = 1;
    for(int i=0; i<nums.size(); i++) {
        int prod = 1;
        for(int j=i; j<nums.size(); j++) {
            prod*=nums[j];
            maxProd = max(maxProd,prod);
        }
    }
    return maxProd;
}


// tc -> O(n)
int maxProduct_OPTIMAL(vector<int> nums) { 
    int maxProd = INT_MIN;
    int prefix = 1;
    int suffix = 1;

    for (int i=0; i<nums.size(); i++) {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;

        prefix = prefix * nums[i];
        suffix = suffix * nums[nums.size()-i-1];

        maxProd = max(maxProd, max(prefix, suffix));
    }
    return maxProd;
}


int main() {
    vector<int> nums = {1,2,3,4,5,0};
    cout << "max product sub arr (BRUTE-FORCE): " << maxProduct_BRUTE_FORCE(nums) << endl;
    cout << "max product sub arr (OPTIMAL): " << maxProduct_OPTIMAL(nums) << endl;
}