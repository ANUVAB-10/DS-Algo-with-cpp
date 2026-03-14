#include<iostream>
#include<vector>
#include<map>
using namespace std;

// map stores in sorted order
void preCompute(vector<int>arr, map<int,int>&mp) {
    for(auto i : arr) mp[i]++;
    // encounter new element just add a pair
    // default values are 0
}

void computeFreq(vector<int> queries, map<int,int>mp) {
    for(auto i:queries) cout << i << "->" << mp[i] << endl;
}

int main() {
    vector<int> arr = {1,2,3,1,3,2,12};
    vector<int> queries = {1,2,3,4,12};
    map<int,int> mp;
    preCompute(arr,mp); 
    computeFreq(queries,mp);
    cout << " hello";
}



// unordered-map -> fetching+storing -> best,avg O(1), worst O(n); because all ements collide to same hash index
// ordered-map -> fecthing+storing -> all cases o(logn)

// because map uses red-black-tree (BST) 
// unordered-map uses linear hashing

// in map any data-type can be a key but not in unordered map