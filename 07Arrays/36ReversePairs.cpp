#include<bits/stdc++.h>
using namespace std;


// tc -> O(n*n);
int reversePair_BRUTE_FORCE(vector<int>&nums) {
    int count = 0;

    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[i] > nums[j]*2) count++;
        }
    }
    return count;
}


// optimal

int merge(vector<int>&nums, int low, int mid, int high) {
    int c = 0;

    int i = low, j = mid+1;

    // calculate the pairs
    while(i <= mid && j <= high) {
        if(nums[i] > 2LL * nums[j]) {
            c += mid-i+1; // means if valid for curr i then all in its right is also valid
            j++;
        }
        else {
            i++;
        }
    }

    // merge
    i = low, j = mid+1;
    int k = 0;

    vector<int> ans (high-low+1,0);

    while(i <= mid && j <= high) {
        if(nums[i] <= nums[j]) {
            ans[k++] = nums[i++];
        }
        else {
            ans[k++] = nums[j++];
        }
    }

    while( i<= mid) {
        ans[k++] = nums[i++];
    }

    while( j<= high) {
        ans[k++] = nums[j++];
    }

    for(int i=low; i<=high; i++) {
        nums[i] = ans[i-low];
    }
    

    return c;
}

int mergeSort(vector<int>&nums, int low, int high) {
    int c=0;
    if(low==high) return c;

    int mid = (low+high)/2;
    c += mergeSort(nums, low, mid);
    c += mergeSort(nums, mid+1, high);

    c += merge(nums, low, mid, high);

    return c;
}

int reversePair_OPTIMAL(vector<int>&nums,int n) {
    return mergeSort(nums,0,n-1);
}


int main() {
    vector<int> nums = {40,25,19,12,9,6,2};

    cout << "total reverse pairs_BRUTE_FORCE: " << reversePair_BRUTE_FORCE(nums) << endl;
    cout << "total reverse pairs_OPTIMAL: " << reversePair_OPTIMAL(nums, nums.size()) << endl;
}