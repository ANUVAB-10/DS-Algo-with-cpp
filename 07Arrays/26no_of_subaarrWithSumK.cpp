#include<bits/stdc++.h>
#include<map>
using namespace std;

int subArrCount(vector<int>nums, int k) {
    map<int,int> mp; // [element, count];

    int count = 0;
    int preSum=0;
    mp.insert({0,1}); // initialize

    for(int i=0; i<nums.size(); i++) {
        preSum+=nums[i];

        int remSum=preSum-k;
        if(mp.find(remSum)!=mp.end()) {
            count += mp[remSum];
        }

        mp[preSum]++;
    }

    return count;
}


int main() {
    vector<int> nums = {3, 1, 2, 4};
    cout << "No. of subarray with sum k: " << subArrCount(nums,6);
}