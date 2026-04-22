#include <bits/stdc++.h>
using namespace std;

void combinationSum(vector<int>nums,int target, vector<int>temp,vector<vector<int>>& ans, int i) {

    int sum = accumulate(temp.begin(), temp.end(), 0);

    // base case
    if(sum == target) {
        ans.push_back(temp);
        return;
    }
    if(i == nums.size() || sum > target) {
        return;
    }

    // pick (same index to allow duplicates)
    temp.push_back(nums[i]);
    combinationSum(nums,target,temp,ans,i);
    
    // skip (move to next index)
    temp.pop_back();
    combinationSum(nums,target,temp,ans,i+1);
    
}

int main() {
    vector<int> nums = {2,3,6,7};
    int target = 7;
    vector<int> temp;
    vector<vector<int>> ans;
    combinationSum(nums,target,temp,ans,0);
    for(auto i:ans) {
        for(auto j : i) {
            cout << j << " ";
        } cout << endl;
    }
}