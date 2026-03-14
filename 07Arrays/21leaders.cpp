#include<bits/stdc++.h>
using namespace std;

void leaders_BruteForce(vector<int>nums) {
    vector<int> ans;

    for(int i=0; i<nums.size()-1; i++) {
        bool flag=true;

        for(int j=i+1; j<nums.size(); j++) {
            if(nums[i] <= nums[j]) {
                flag=false;
            }
        }

        if(flag) {
            ans.push_back(nums[i]);
        }
    }

    // include last element
    ans.push_back(nums[nums.size()-1]);

    // print them
    cout << "leaders(Brute-Force): ";
    for(auto i:ans) cout << i << " ";
    cout << endl;

}

void leaders_Optimal(vector<int>nums) {
    int maxi=INT_MIN;
    vector<int> leaders;

    for(int i=nums.size()-1; i>=0; i--) {
        if(nums[i] > maxi) {
            maxi = max(maxi, nums[i]);
            leaders.push_back(maxi);
        }
    }
    
    // reverse leaders array to retain the order
    reverse(leaders.begin(),leaders.end());

    // print them
    cout << "leaders(Optimal): ";
    for(auto i:leaders) cout << i << " ";
    cout << endl;

}

int main() {
    vector<int> nums = {10,22,12,3,0,6};
    // leaders_BruteForce(nums);
    leaders_Optimal(nums);
    
}