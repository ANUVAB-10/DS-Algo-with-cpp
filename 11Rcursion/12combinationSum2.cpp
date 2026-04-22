#include <bits/stdc++.h>
using namespace std;

void combinationSum2(vector<int>nums,int target, vector<int>temp,set<vector<int>>& ans, int i) {

    int sum = accumulate(temp.begin(), temp.end(), 0);

    // base case
    if(sum == target) {
        sort(temp.begin(),temp.end()); // o(nlogn)
        ans.insert(temp); // o(logn)
        return;
    }
    if(i == nums.size() || sum > target) {
        return;
    }

    // pick
    temp.push_back(nums[i]);
    combinationSum2(nums,target,temp,ans,i+1);
    
    // skip 
    temp.pop_back();
    combinationSum2(nums,target,temp,ans,i+1);
    
}

int main() {
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    vector<int> temp;
    set<vector<int>> ans;
    combinationSum2(nums,target,temp,ans,0);
    for(auto i:ans) {
        for(auto j : i) {
            cout << j << " ";
        } cout << endl;
    }
}