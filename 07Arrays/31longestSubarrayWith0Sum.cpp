#include <bits/stdc++.h>
using namespace std;

// tc -> O(n*n);
int longestSubArray_BRUTE_FORCE(vector<int> nums, int k) {
    int maxLength = -1;
    for(int i=0; i<nums.size(); i++) {
        int sum = 0;
        for(int j=i; j<nums.size(); j++) {
            sum+=nums[j];
            int len = j-i+1;
            if(sum == k) {
                maxLength=max(maxLength, len);
            }
        }
    }
    return maxLength;
}



int longestSubArray_BETTER(vector<int> nums, int k) {
    int maxLength = -1;
    int prefixSum = 0;

    // hashMap
    map<int,int> hashMap;

    for(int i=0; i<nums.size(); i++) {
        prefixSum += nums[i];

        // prefix sum is k
        if(prefixSum == k) {
            maxLength = max(maxLength, i+1);
        }

        // check if sum is present
        if(hashMap.find(prefixSum) != hashMap.end()) {
            maxLength = max(maxLength, i - hashMap[prefixSum]);
        }

        // update map if it is not present only
        else if(hashMap.find(prefixSum) == hashMap.end()) {
            hashMap[prefixSum] = i;
        }
    }

    return maxLength;
}


int main() {
    vector<int> nums = {9, -3, 3, -1, 6, -5};
    int sum = 0;
    cout << "Sub array length with sum 0 (BRUTE-FORCE): " << longestSubArray_BRUTE_FORCE(nums, sum) << endl;
    cout << "Sub array length with sum 0 (BETTER): " << longestSubArray_BETTER(nums, sum) << endl;
}