#include<bits/stdc++.h>
using namespace std;

void nextPermute_STL(vector<int>nums) {
    next_permutation(nums.begin(),nums.end());

    cout << "Next Permutation by STL: ";
    for(auto i:nums) cout << i << " ";
    cout << endl;
}

void nextPermuation(vector<int>nums) {
    // 1. find breakpoint
    int idx=-1;
    for(int i=nums.size()-2; i>=0; i--) {
        if(nums[i] < nums[i+1]) {
            idx=i;
            break;
        }
    }

    // edgecase for last permutation
    if(idx==-1) reverse(nums.begin(),nums.end());

    // 2. find the element just grater than nums[idx]

    for(int i=nums.size()-1; i>idx; i--) {
        if(nums[i] > nums[idx]) {
            swap(nums[i],nums[idx]);
            break;
        }
    }

    // 3. sort the elements from idx+1 -> n
    sort(nums.begin()+idx+1, nums.end());


    // print them
    cout << "Next Permutation implement: ";
    for(auto i:nums) cout << i << " ";
    cout << endl;

}

int main() {
    vector<int> nums = {2,1,5,4,3,0,0};
    // nextPermute_STL(nums);
    nextPermuation(nums);
    
}