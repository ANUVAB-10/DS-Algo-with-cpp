// divide the array is 2 halves [greater and smaller] or vice-versa
// takes tow pointers low,hig 1st half [low -> mid], [mid+1 -> high]

#include<iostream>
using namespace std;

void merge(int* arr, int low, int mid, int high) {
    int ans[high-low+1];
    int i=low, j=mid+1, k=0;

    while(i<=mid && j<=high) {
        if(arr[i] <= arr[j]) {
            ans[k++] = arr[i++];
        }
        else {
            ans[k++] = arr[j++];
        }
    }


    while(i<=mid) {
        ans[k++] = arr[i++];
    }
    while(j <= high) {
        ans[k++] = arr[j++];
    }

    // put back in original arr
    for(int i=low; i<=high; i++) {
        arr[i]=ans[i-low];
    }
}

void mergeSort(int* arr, int low, int high) {

    if(low==high) return;

    int mid = (low+high)/2;
    mergeSort(arr,low,mid);  // left part
    mergeSort(arr,mid+1,high); // right part

    merge(arr,low,mid,high); // merge
}

int main() {
    int arr[5] = {3,2,4,1,3};
    mergeSort(arr,0,4);
    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
}

