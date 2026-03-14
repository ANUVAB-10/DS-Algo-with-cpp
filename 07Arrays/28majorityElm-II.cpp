#include<bits/stdc++.h>
using namespace std;

// bruteForce to get majority element > N/3

// tc -> O(n*n)  sc -> O(n)
void majorityElm_BRUTE_FORCE(vector<int>nums) {

    if(nums.size()==0) {
        cout << "Majority Elements > N/3 BRUTE_FORCE: " << -1 << endl;
        return;
    }
 
    vector<int>ans;
    
    for(int i=0; i<nums.size(); i++) {
        int count=0;
        for(int j=i; j<nums.size(); j++) {
            if(nums[i]==nums[j]) {
                count++;
            }
        }
        if(count > nums.size()/3 ){
            bool exists=0;
            for(auto i:ans) {
                if(i==nums[i]) {
                    exists=1;
                    break;
                }
            }
            if(!exists) {
                ans.push_back(nums[i]);
            }
        }
    }



    cout << "Majority Elements > N/3 BRUTE_FORCE: ";
    for(auto i:ans) cout << i << " ";
    cout << endl;

}

// tc -> O(n). sc -> O(n)
void majorityElm_BETTER(vector<int>nums ) {
    unordered_map<int,int> mp;

    if(nums.size()==0) {
        cout << "Majority Elements > N/3 BETTER: " << -1 << endl;
        return;
    }

    // insert elements
    for(auto i:nums) {
        mp[i]++;
    }

    // take out who are greater than N/3
    cout << "Majority Elements > N/3 BETTER: ";
    for(auto it:mp) {
        if(it.second > nums.size()/3) {
            cout << it.first << " ";
        }
    } cout << endl;

}

// tc -> O(n) sc -> O(1)
void majorityElm_OPTIMAL(vector<int>nums) {

    if(nums.size()==0) {
        cout << "Majority Elements > N/3 OPTIMAl: " << -1 << endl;
        return;
    }

   int cnt1=0, cnt2=0;
   int el1=-1, el2=-1;
   
   for(auto i:nums) {
    if(cnt1==0 && i != el2)  {
        cnt1=1;
        el1=i;
    }   
    else if(cnt2==0 && i != el1) {
        cnt2=1;
        el2 = i;
    }
    else if(i == el1) {
        cnt1++;
    }
    else if (i == el2) {
        cnt2++;
    }
    else {
        cnt1--,cnt2--;
    }
   }


   // manual checking
   int actualCnt1=0, actualCnt2=0;
   for(auto i:nums) {
    if(i==el1) {
        actualCnt1++;
    }
    else if(i==el2) {
        actualCnt2++;
    }
   }

   cout << "Majority Elements > N/3 OPTIMAL: ";
   if(actualCnt1 > nums.size()/3) {
    cout << el1 << " ";
    }
    if(actualCnt2 > nums.size()/3) {
        cout << el2 << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 1, 1, 3, 2, 2};
    majorityElm_BRUTE_FORCE(nums);
    majorityElm_BETTER(nums);
    majorityElm_OPTIMAL(nums);
}