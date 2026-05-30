#include <bits/stdc++.h>
using namespace std;


// O(n-k)*O(k)
vector<int> slidingWindow_Brute_Force(vector<int>&nums, int k) {
    vector<int> maxis;
    int n = nums.size();

    for(int i=0; i<=n-k; i++) {
        int maxElm = INT_MIN;
        for(int j=i; j<i+k; j++) {
            maxElm = max(maxElm, nums[j]);
        }
        maxis.push_back(maxElm);
    }

    return maxis;
}

vector<int> max_sliding_window_optimised(vector<int>&nums, int k) {
    vector<int> maxis;  
    deque<int> dq; // storing indices

    for(int i=0; i<nums.size(); i++) {
        // pop from front if window exceeds.
        if(!dq.empty() && i-dq.front() >= k) dq.pop_front();

        // pop from back , maintaining monotonic stack
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);

        // update maxis on first window formation
        if(i >= k-1) {
            maxis.push_back(nums[dq.front()]);
        }
    }
    return maxis;
}

int main() {
    vector<int> nums = {4,0,-1,3,5,3,6,8};
    int k=3;
    vector<int> ans = max_sliding_window_optimised(nums, k);
    for(auto i:ans) cout << i << " ";
    cout << endl;
    return 0;
}