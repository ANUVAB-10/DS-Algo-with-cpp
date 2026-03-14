#include<iostream>
using namespace std;

void print(int* arr, int n) {
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(int* arr, int n) {
    for(int i=0; i < n-1; i++) {
        int min=i;
        for(int j=i; j<n; j++) {
            if(arr[j] < arr[min]) min=j;
        }
        if(min!=i) swap(arr[i],arr[min]);
    }
}


int main () {
    int arr [7] = {1,2,3,1,3,2,12};
    selectionSort(arr,7);
    print(arr,7);
}

// t.c O(n*n) 
// after every iteration smallest element gets at the first