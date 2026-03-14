
// same as previous ques but duplicates present

#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return true;

        // trim down
        else if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }

        // check if right part is sorted
        else if (nums[mid] <= nums[high]) {
            // check if present
            if (nums[mid] < target && nums[high] >= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // left is sorted
        else {
            // target lies in keft part
            if (nums[mid] > target && nums[low] <= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return false;
}



int main() {
    vector<int> nums = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int x = 3;

    cout << " element present?: " << search(nums,x);
}