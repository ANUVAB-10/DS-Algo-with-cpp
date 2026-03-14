// logic is to subtract last and first occurrances
// last-first+1 -> ans

#include<bits/stdc++.h>
using namespace std;

int last_Ocurr(vector<int>nums, int x) {
    int last = -1;

    int low = 0, high = nums.size()-1;

    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] > x) {
            last = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    if(last == -1) return nums.size()-1;
    return last - 1; // because last points just after x
}

int first_Occrr(vector<int> nums, int x) {
    int first = -1;

    int low = 0, high = nums.size()-1;

    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] >= x) {
            first = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    if(first == -1 || nums[first] != x || first == nums.size()) return -1;
    return first;
}

int occurrances(vector<int>nums, int x ) {
    int first = first_Occrr(nums, x);
    if(first == -1) return 0;  // x not present

    int last = last_Ocurr(nums, x);

    return last - first + 1;
}

int main () {
    vector<int> nums = {1, 1, 2, 2, 2, 2, 2, 3};
    int x=2;

    cout << " total occurrances of x=2: " << occurrances(nums,x) << endl;
}