#include <bits/stdc++.h>
using namespace std;

// The lower bound is the smallest index, ind, where arr[ind] >= x
int f_BS_lowerBound(vector<int>nums ,int x) {
    int ans = nums.size();  // default index if not found
    int low=0, high = nums.size()-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] >= x) { // condition means ans may also exits on left.
            ans=mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

// The upper bound is the smallest index, ind, where arr[ind] > x.
int f_BS_upperBound(vector<int>nums ,int x) {
    int ans = nums.size();  // default index if not found
    int low=0, high = nums.size()-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] > x) { // condition means ans may also exits on left.
            ans=mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int main() {
    vector<int> nums = {3,5,8,15,19};
    int x = 9;
    cout << "lower bound (index):  " << f_BS_lowerBound(nums,x) << endl;
    cout << "upper bound (index):  " << f_BS_upperBound(nums,x) << endl;
}