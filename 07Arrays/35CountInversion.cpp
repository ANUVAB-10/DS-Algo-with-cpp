#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&nums, int low, int mid, int high) {
    vector<int>ans(high-low+1,0);
    int count = 0;
    int i=low,j=mid+1;
    
    // count inversion
    while(i <= mid && j <= high) {
        if(nums[i] > nums[j]) {
            count += mid-i+1;
            j++;
        }
        else {
            i++;
        }
    }
    
    
    // sort it
    int k=0;
    i=low, j=mid+1;

    while( i<= mid && j <= high) {
        if(nums[i] <= nums[j]) {
            ans[k] = nums[i];
            i++;
            k++;
        }
        else {
            ans[k] = nums[j];
            k++;
            j++;
        }
    }

    while(i<=mid) {
        ans[k++] = nums[i++];
    }
    while(j <= high) {
        ans[k++] = nums[j++];
    }

    for(int i=low; i<=high; i++) {
        nums[i] = ans[i-low];
    }

    return count;

}


int mergeSort(vector<int>&nums, int low, int high) {
    int cnt = 0;
    if(low == high) return cnt;
    int mid = (low+high)/2;
    cnt += mergeSort(nums,low,mid);
    cnt += mergeSort(nums, mid+1,high);
    cnt += merge(nums,low,mid,high);

    return cnt;
}

int numberOfInversions(vector<int>&nums, int n) {
    return mergeSort(nums,0,n-1);
}

int main() {
    // Input array
    vector<int> a = {3,2,4,1,3};
    int n = a.size();

    // Count inversions
    int cnt = numberOfInversions(a, n);

    cout << "The number of inversions are: " << cnt << endl;
}