#include <bits/stdc++.h>
using namespace std;

int f_BS_Floor(vector<int>&nums, int target) {
    int low = 0, high = nums.size()-1;
    int ans = nums.size(); // must be at last

    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] <= target) {
            ans = nums[mid];
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }return ans;
}

int f_BS_Ceil(vector<int>&nums, int target) {
    int low = 0, high = nums.size()-1;
    int ans = nums.size(); // must be at last

    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] >= target) {
            ans = nums[mid];
            high = mid - 1;
        }
        else low = mid + 1;
    }return ans;
}

int main() {
    vector<int> nums = {3,5,8,15,19};
    int x = 9;
    cout << "floor value of 9:  " << f_BS_Floor(nums,x) << endl;
    cout << "ceil value of 9:  " << f_BS_Ceil(nums,x) << endl;
}