#include<bits/stdc++.h>
using namespace std;

// Heapify the subtree rooted at index i to maintain the max-heap property.
// Assumes the children of i are already max-heaps.
void heapifyDownMax(vector<int>&nums, int i) {
    int largest = i;
    int lChild = (2*i+1 < nums.size()) ? 2*i+1 : -1;
    int rChild = (2*i+2 < nums.size()) ? 2*i+2 : -1;
    if(lChild == -1 && rChild == -1) {
        return;
    }
    
    if(nums[largest] < nums[lChild]) largest = lChild;
    if(nums[largest] < nums[rChild]) largest = rChild;
    if(largest != i) {
        swap(nums[largest], nums[i]);
        heapifyDownMax(nums, largest);
    }
    
}


void minToMaxHeap(vector<int>&nums) {
    for(int i=nums.size()/2-1 ;i>=0; i--) { // loop on non leaves
        heapifyDownMax(nums,i);
    }
}


int main() {
    vector<int> nums = {1,5,3,10,8};
    cout << " min heap: ";
    for(auto i:nums){
        cout  << i << " ";
    } cout << endl;

    minToMaxHeap(nums);

    cout << " max heap: ";
    for(auto i:nums){
        cout  << i << " ";
    } cout << endl;
}