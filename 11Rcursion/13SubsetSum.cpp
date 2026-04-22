#include <bits/stdc++.h>
using namespace std;

void combinationSum(vector<int>nums, vector<int>temp,vector<vector<int>>& ans, int i) {

    int sum = accumulate(temp.begin(), temp.end(), 0);

    // base case
    if(i == nums.size()) {
        ans.push_back(temp);
        return;
    }
    // pick (same index to allow duplicates)
    temp.push_back(nums[i]);
    combinationSum(nums,temp, ans,i+1);
    
    // skip (move to next index)
    temp.pop_back();
    combinationSum(nums, temp, ans,i+1);
    
}

int main() {
    vector<int> nums = {5,2,1};
    int target = 7;
    vector<int> temp;
    vector<vector<int>> ans;
    combinationSum(nums,temp,ans,0);
    sort(ans.begin(),ans.end());
    for(auto i:ans) {
        cout << accumulate(i.begin(), i.end(), 0) << " ";
    }
}