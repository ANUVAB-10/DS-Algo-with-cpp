#include<bits/stdc++.h>
using namespace std;

int LCS_length_BruteForce(vector<int>nums) {
    int l=1;

    for(int i=0; i<nums.size(); i++) {
        int keyElm=nums[i]+1;
        int cnt = 1;
        bool flag=true;
        while(flag) {
            flag=false;

            for(int j=0; j<nums.size(); j++){
                if(nums[j]==keyElm) {
                    cnt++;
                    flag=true;
                    keyElm++;
                    break;// here flag value is true and start again
                }
            }
            
        }
        l=max(l,cnt);
    }

    return l;

}


int LCS_length_Better(vector<int>nums) {

    if(nums.size()==0) return 0;

    // first sort
    sort(nums.begin(),nums.end());

    // 2. start algo

    int count = 0;
    int last_Smaller = INT_MIN;
    int longestLength=0;

    for(int i=0; i<nums.size(); i++) {
        if(nums[i]-1==last_Smaller) {
            count++;
            last_Smaller=nums[i];
        }
        else if(nums[i]-1!=last_Smaller) {
            count=1;
            last_Smaller=nums[i];
        }
        longestLength = max(longestLength, count);
    }

    return longestLength;
}


int LCS_length_Optimal(vector<int>nums) {

    if(nums.size()==0) return 0;

    int length = 1;
    int count = 1;

    set<int> s;

    // sore all element in set
    for(auto i:nums) s.insert(i);

    // iterate through set
    for(auto i:s) {
        if(s.find(i-1)==s.end()) {
            while(s.find(i+1)!=s.end()) {
                i=i+1;
                count++;
            }
        }
        else {
            count = 1;
        }

        length = max(length, count);
    }

    return length;

}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    // cout << "lenght(BRUTE-FORCE): " << LCS_length_BruteForce(nums) << endl;
    // cout << "lenght(BETTER): " << LCS_length_Better(nums) << endl;
    cout << "lenght(OPTIMAL): " << LCS_length_Optimal(nums) << endl;
    
}