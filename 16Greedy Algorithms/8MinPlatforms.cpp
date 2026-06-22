#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;


int MinPlatforms(vector<int> arr, vector<int>dept) {
    // sort acc to dept
    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());

    int c=0, i=0, j=0, maxC=INT_MIN;
    while(i<arr.size() && j < arr.size()) {
        if(arr[i] <= dept[j]) {
            i++;
            c++;
            maxC = max(maxC, c);
        }
        else {
            j++;
            c--;
        }
    }

    return maxC;
}

int main() {
    auto start = high_resolution_clock::now();
    
    vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int>dept = {920, 1200, 1130, 1150, 1900, 2000};


    cout << "no. of min platforms: " << MinPlatforms(arr, dept) << endl;
    
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
}