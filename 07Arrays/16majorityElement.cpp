#include<bits/stdc++.h>
using namespace std;

// tc -> O(n*n)  sc -> o(1)
int majorityElem_BruteForce(vector<int>a) {
    for(int i=0; i<a.size(); i++) {
        int count=0;
        // for every i check throughout the arr
        for(int j=0; j<a.size(); j++) {
            if(a[i]==a[j]) count++;
        }
        if(count > a.size()/2) return a[i];
    }return -1;
}

// tc -> O(n) better,averge O(n*n) worst  sc -> o(n)
int majorityElm_Better(vector<int>a) {
    unordered_map<int,int>mp;

    for(int i=0; i<a.size(); i++) { 
        if(mp.find(a[i])==mp.end()) mp[a[i]]=1;
        else mp[a[i]]++;
    }

    // now iterate in map
    for(auto it:mp) {
        if(it.second > a.size()/2) return it.first;
    }
    return -1;
    
}

int majorityElm_Optimal_MooresVotingAlgorithm(vector<int>a) {
    int count=0;
    int elm;

    for(int i=0; i<a.size(); i++) {
        if(count==0) {
            count=1;
            elm=a[i];
        }
        
        else if(a[i]==elm) count++;

        count--;
    }

    // now we have a count and elm;
    int checkCount=0;
    for(int i=0; i<a.size(); i++) {
        if(a[i]==elm) checkCount++;
    }

    if(checkCount > a.size()/2) return elm;
    return -1;
}

int main() {
    vector<int> nums = {6,5,5};

    // cout << "majority element in array(Brute-Force): " << majorityElem_BruteForce(nums) << endl;;
    // cout << "majority element in array(Better): " << majorityElm_Better(nums) << endl;
    cout << "majority element in array(Optimal): " << majorityElm_Optimal_MooresVotingAlgorithm(nums) << endl;
}