// t.c -> worst case: O(n*n) and best case O(n)
// after every iteration largest element is at the largest

#include<iostream>
using namespace std;

void print(int* arr, int n) {
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int* arr, int n) { // n=6
    for(int i=0; i<n; i++) {
        int j = i; 
        while(j >0 && arr[j-1]>=arr[j]) {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}


int main () {
    int arr [7] = {1,2,3,1,3,2,12};
    insertionSort(arr,7);
    print(arr,7);
}