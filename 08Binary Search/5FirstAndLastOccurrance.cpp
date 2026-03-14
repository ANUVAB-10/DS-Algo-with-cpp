#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int first = -1, last = -1;
    vector<int> ans;
    // lower bound
    int low = 0, high = nums.size()-1;

    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] >= target) {
            first = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    // upper bound
    low = 0, high = nums.size()-1;

    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] > target) {
            last = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    // check validity
    if(first == -1 || first == nums.size() || nums[first] != target) {
        return {-1, -1};
    }

    if(last == -1) last = nums.size();

    return {first, last - 1};
}

int main() {

    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    cout << "First Position: " << ans[0] << endl;
    cout << "Last Position: " << ans[1] << endl;

}