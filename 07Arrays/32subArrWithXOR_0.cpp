#include<bits/stdc++.h>
using namespace std;

int f_BRUTE(vector<int> nums, int k) {
    int count = 0;
    for(int i=0; i<nums.size(); i++) {
        int xorSum=0;
        for(int j=i; j<nums.size(); j++) {
            xorSum = xorSum ^ nums[j];
            if(xorSum==k) {
                count++;
            }
        }
    }
    return count;
}


int f_OPTIMAL(vector<int>nums, int k) {
    map<int,int> hashmap;
    int count = 0;
    int pre_xorSum = 0;

    for(int i=0; i<nums.size(); i++) {
        pre_xorSum = pre_xorSum ^ nums[i];

        if(pre_xorSum == k) count++;

        if(hashmap.find(pre_xorSum^k)!=hashmap.end()) {
            count+=hashmap[pre_xorSum^k]++;
        }

        else if(hashmap.find(pre_xorSum^k)==hashmap.end()) {
            hashmap[pre_xorSum]++;
        }
    }
    return count;
} 

int main() {
    vector<int> nums = {5, 6, 7, 8, 9};
    int k = 5;
    cout << "subarray with xor valued as 6: " << f_BRUTE(nums, k) << endl;
    cout << "subarray with xor valued as 6: " << f_OPTIMAL(nums, k) << endl;
}