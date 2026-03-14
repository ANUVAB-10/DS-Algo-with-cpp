#include <bits/stdc++.h>
using namespace std;

int f_BS_Insert_Position(vector<int>&nums, int target) {
    int low = 0, high = nums.size()-1;
    int ans = nums.size(); // must be at last

    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }return ans;
}

int main() {
    vector<int> nums = {3,5,8,15,19};
    int x = 9;
    cout << "insert position (index):  " << f_BS_Insert_Position(nums,x) << endl;
}