#include <bits/stdc++.h>
using namespace std;


// intuition was pick up the min from the sorted part.
int minInRotatedSorted(vector<int> nums) {
    int low = 0, high = nums.size()-1;
    int ans = INT_MAX;

    while(low <= high) {
        int mid = low + (high-low)/2;

        // left half is sorted
        if(nums[low] <= nums[mid]) {
            ans = min(ans,nums[low]);
            // drop left half
            low = mid + 1;
        } else  {  // right half is sorted
            ans = min(ans,nums[mid]);
            high = mid - 1; // drop right half
        }
    }
    return ans;
}


int main() {
    vector<int> nums = {-4,5,6,7,0,-1,2,3 };
    cout << "Min in rotated sorted array: " << minInRotatedSorted(nums) << endl;
}