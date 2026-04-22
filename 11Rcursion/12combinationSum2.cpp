#include <bits/stdc++.h>
using namespace std;

void combinationSum2(vector<int>nums,int target, vector<int>temp, vector<vector<int>>& ans, int i) {

    // base case
    if(target == 0) {
        ans.push_back(temp); 
        return;
    }
    if(i == nums.size() || target < 0) {
        return;
    }

    // pick
    for(int j=i; j<nums.size(); j++) {
        if(j > i && nums[j] == nums[j-1]) continue;

        else {
            temp.push_back(nums[j]);
            combinationSum2(nums,target - nums[j], temp, ans, j+1);
            temp.pop_back();
        }
    }
    
}

int main() {
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    sort(nums.begin(), nums.end());
    vector<int> temp;
    vector<vector<int>> ans;
    combinationSum2(nums,target,temp,ans,0);
    for(auto i:ans) {
        for(auto j : i) {
            cout << j << " ";
        } cout << endl;
    }
}