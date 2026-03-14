#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> MergeOverlapping_BRUTE(vector<vector<int>> nums) {
    vector<vector<int>> ans;

    sort(nums.begin(),nums.end()) ;

    for(int i=0; i<nums.size(); i++) {
        int start = nums[i][0];
        int end = nums[i][1];

        if(!ans.empty() && end <= ans.back()[1]) continue;

        for(int j=i+1; j<nums.size(); j++) {
            if(nums[j][0] <= end) {
                end = max(end, nums[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start,end});
    }

    return ans;
}


vector<vector<int>> MergeOverlapping_OPTIMAL(vector<vector<int>> nums) {
    // sort the array
    sort(nums.begin(),nums.end()) ;

    vector<vector<int>> ans;

    // include the first one
    ans.push_back({nums[0][0],nums[0][1]});

    for(int i=1; i<nums.size(); i++) {
        int start = nums[i][0];
        int end = nums[i][1];

        if(!ans.empty() && ans.back()[1] > start) {
            ans.back()[1] = max(ans.back()[1], end);
        }

        else {
            ans.push_back({start, end});
        }
    }

    return ans;
}


int main() {
    vector<vector<int>> nums = {{1,3}, {2,6}, {8,10}, {15,18}};

    // vector<vector<int>> ans = MergeOverlapping_BRUTE(nums);
    vector<vector<int>> ans = MergeOverlapping_OPTIMAL(nums);

    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }cout << endl;
    }
}