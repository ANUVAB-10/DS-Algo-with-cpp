#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void preCompute(vector<int>arr, unordered_map<int,int>&mp) {
    for(auto i : arr) mp[i]++;
    // encounter new element just add a pair
    // default values are 0
}

void findHighestAndLowestFreq(unordered_map<int,int>map) {
    int max=INT_MIN;
    int min=INT_MAX;
    for(auto i:map) {
        if(i.second > max) max=i.second;
        if(i.second < min) min = i.second;
    }
    for(auto i:map) {
        if(i.second==max) {
            cout << "max freq element(s): " << i.first << endl;
        }if(i.second==min) {
            cout << "min freq element(s): " << i.first << endl;
        }
    }
}

int main() {
    vector<int> arr = {1,2,3,1,3,3,2,12};
    vector<int> queries = {1,2,3,4,12};
    unordered_map<int,int> mp;
    preCompute(arr,mp); 
    findHighestAndLowestFreq(mp);
}