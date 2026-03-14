#include<bits/stdc++.h>
using namespace std;

// tc -> O(n), sc -> O(n)
pair<int,int> f_BETTER(vector<int>&nums) {
    int dup=-1;
    int miss=-1;
    // pair<int,int> ans;
    vector<int> hash(nums.size()+1, 0);

    for(int i=0; i<nums.size(); i++) {
        hash[nums[i]]++;
    }
    
    for(int i=1; i<=hash.size(); i++) {
        if(hash[i]==0) {
            miss=i;
        }
        else if(hash[i]==2) {
            dup=i;
        } 

        if(dup != -1 && miss != -1) break;
    }

    return {miss,dup};
}

// tc -> O(n), sc -> O(1)
pair<int,int> f_OPTIMAL1(vector<int>&nums) {
    long long n = nums.size();

    long long arrSum=0, arrSqareSum=0, s1=0, s2=0;

    for(auto i:nums) {
        arrSum+=i;
        arrSqareSum+=(long long)i * (long long)i;
    }
    s1 = (n*(n+1))/2;
    s2 = (n*(n+1)*(2*n+1))/6;

    long long val1 = s1 - arrSum;
    long long val2 = s2 - arrSqareSum;
    val2 = val2/val1;

    int x = (val1+val2)/2;
    int y = val2 - x;

    return {x,y}; // {repeating, missing}

}


int main() {
    vector<int> nums = {3, 5, 4, 1, 1};

    // pair<int,int> ans = f_BETTER(nums);
    pair<int,int> ans = f_OPTIMAL1(nums);

    cout << " missing: " << ans.second << " duplicate: " << ans.first  << endl;
}