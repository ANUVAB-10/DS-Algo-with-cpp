#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>nums, int x) {
    int low = 0, high = nums.size()-1;

    while(low <= high) {
        int mid = low + (high - low)/2;
        if(nums[mid] == x) return true;

        // check if right part is sorted
        if(nums[mid] <= nums[high]) {
            // check if present
            if(nums[mid] < x && nums[high] >= x) {
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        // left is sorted
        else {
            // target lies in keft part
            if(nums[mid] > x && nums[low] <= x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    }

    return false;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int x = 90;

    cout << " element present?: " << search(nums,x);
}