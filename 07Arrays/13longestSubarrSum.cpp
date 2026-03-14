#include <bits/stdc++.h>
using namespace std;

int longestSubarray_Length(vector<int>a, int k) {
    int maxL=0;

    for(int i=0;i<a.size();i++) {
        for(int j=i;j<a.size();j++) {
            int sum=0;
            for(int k=i; k<=j; k++) {
                sum+=a[k];
            }
            if(sum==k) {
                maxL = max(maxL,j-i+1);
            }
        }
    }
    return maxL;
}


int longestSubarrayWithSumK(vector<int>a, long long k) {
    unordered_map<long long,int> mp;
    int len=0;
    long long prefixSum=0;

    for(int i=0; i<a.size(); i++) {
        prefixSum+=a[i];
        
        // return if we get the sum as k
        if(prefixSum==k) {
            len = max(len, i+1);
        }

        // apply reverse maths thinking
        if(mp.find(prefixSum-k)!=mp.end()) {
            len = max(len, i-mp[prefixSum-k]);
        }
        // update only if sum is  not present
        if(mp.find(prefixSum)==mp.end()){ 
            mp[prefixSum]=i;
        }
    }
    return len;
}

int longestSubarrayWithSumK_Optimal(vector<int>a, long long k) {
    long long sum=0;
    int len=0;
    int i=0,j=0;

    while(j<a.size()) {
        sum+=a[j];
        if(sum==k) {
            len=max(len, j-i+1);
        }

        while(sum > k) {
            sum=sum-a[i];
            i++;
            if(sum==k) {
                len=max(len, j-i+1);
            }
        }
        j++;
    }
    return len;
}


int main() {
    vector<int> a = {10, 5, 2, 7, 1, 9};
    int k=15;

    // cout << " length of longest sub-array(Brute-force): " << longestSubarray_Length(a,k) << endl;
    // cout << " length of longest sub-array(contains all positive negetive ans 0s): " << longestSubarrayWithSumK(a,k) << endl;
    cout << " length of longest sub-array(contains all positive negetive and 0s): " << longestSubarrayWithSumK_Optimal(a,k) << endl;
}