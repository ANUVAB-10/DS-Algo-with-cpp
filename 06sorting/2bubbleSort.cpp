// t.c -> worst case: O(n*n) and best case O(n)
// after every iteration largest element is at the largest

#include<iostream>
using namespace std;

void print(int* arr, int n) {
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int* arr, int n) { // n=6
    for(int i=n-1; i>=1; i--) { // [5,1] 5 times
        bool flag=0;
        for(int j=0; j<=i-1; j++) { // [0,5],[0,4],[0,3],[0,2],[0,1]
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(!flag) break;
    }
}


int main () {
    int arr [7] = {1,2,3,1,3,2,12};
    bubbleSort(arr,7);
    print(arr,7);
}