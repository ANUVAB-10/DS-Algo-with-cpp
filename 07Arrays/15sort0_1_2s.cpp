#include <bits/stdc++.h>
using namespace std;

// better solution -> tc -> o(2n) sc -> 0(n)
void sortZeroOneTwo(vector<int>& nums) {
    // Count of 0s, 1s, and 2s
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    // First pass: Count the number of 0s, 1s, and 2s
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) cnt0++;
        else if (nums[i] == 1) cnt1++;
        else cnt2++;
    }

    // Second pass: Fill the array with 0s, then 1s, then 2s

    // Fill the first 'cnt0' elements with 0
    for (int i = 0; i < cnt0; i++) {
        nums[i] = 0;
    }

    // Fill the next 'cnt1' elements with 1
    for (int i = cnt0; i < cnt0 + cnt1; i++) {
        nums[i] = 1;
    }

    // Fill the remaining elements with 2
    for (int i = cnt0 + cnt1; i < nums.size(); i++) {
        nums[i] = 2;
    }
}

// optimal solution -> tc -> o(n) sc -> 0(n)
void sort012_DNF(vector<int>&a) {
    int low=0;
    int mid=0;
    int high=a.size()-1;

    while(mid<=high) {
        if(a[mid]==0) {
            swap(a[mid++],a[low++]);
        }
        else if(a[mid]==1) {
            mid++;
        }
        else {
            swap(a[mid],a[high]);
            high--;
        }
    }
}


int main() {
    vector<int> nums = {0, 2, 1, 2, 0, 1};

    // sortZeroOneTwo(nums);
    sort012_DNF(nums);

    cout << "After sorting:" << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

}
