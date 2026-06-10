#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;


class Heap {
    public:
    int *arr;
    int size;
    int capacity=100;

    Heap() {
        size = 0;
        arr = new int[capacity];
    }

    // will be performig minHeap

    int parent(int i) {
        return (i-1)/2;
    }
    
    int lChild(int i) {
        return (2*i+1);
    }
    
    int rChild(int i) {
        return (2*i+2);
    }

    // insert 
    void insert(int val) {
        if(size == capacity) {
            cout << "Overflow" << endl;
            return;
        }
        arr[size] = val;
        int k=size;
        size++;
        
        while(k > 0 && arr[parent(k)] > arr[k]) {
            swap(arr[k], arr[parent(k)]);
            k=parent(k);
        }
    }

    // display
    void display() {
        if(size == 0) {
            cout << "pls insert element" << endl;
            return;
        }
        for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }
};


int main() {
    auto start = high_resolution_clock::now();
    
    Heap *h = new Heap();
    h->display();
    h->insert(2);
    h->insert(4);
    h->insert(3);
    h->insert(1);
    
    h->display();
    
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
}