#include <bits/stdc++.h>
using namespace std;

bool BS_iterative(vector<int> &nums, int target) {
    int low = 0, high = nums.size()-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] == target) return true;
        else if(nums[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return false;
}

bool BS_recurr(vector<int>nums, int low, int high, int target) {
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(nums[mid] == target) return true;
    else if(nums[mid] > target) {
        return BS_recurr(nums,low,mid-1,target);
    }
    return BS_recurr(nums,mid+1,high,target);
}

int main() {
    vector<int> nums = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6; // target element to search

    cout << "element present(iterative): ? " << BS_iterative(nums,target) << endl;
    cout << "element present(recurrsive): ? " << BS_recurr(nums,0,nums.size()-1,target) << endl;
}