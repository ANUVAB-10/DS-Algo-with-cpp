#include<bits/stdc++.h>
using namespace std;


// tc -> O(n*n*n*n)* [O(nlog n) + O(logn)]
// sc -> O(unique quadraples) 
vector<vector<int>> FourSum_BRUTE_FORCE(vector<int> nums, int target) {
    set<vector<int>> st;
    int n = nums.size();
    for(int i=0; i<n ; i++) {
        for (int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                for(int l = k+1; l<n; l++) {
                    if(nums[i]+nums[j]+nums[k]+nums[l] == target) {
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert({temp});
                    }
                }
            }
        }
    }
    return vector<vector<int>> (st.begin(),st.end());
}

// tc -> O(n*n*n)* [O(nlog n) + O(logn)]
// sc -> O(unique quadraples) 
vector<vector<int>> FourSum_BETTER(vector<int> nums, int target) {
    set<vector<int>> st;
    int n = nums.size();
    for(int i=0; i<n ; i++) {
        for (int j=i+1; j<n; j++) {
            set<int> hashSet;
            for(int k=j+1; k<n; k++) {
                long long remSum = (long long)target - nums[i] - nums[j] - nums[k];
                if(hashSet.find(remSum)!=hashSet.end()) {
                    vector<int> temp = {nums[i],nums[j],nums[k],(int)remSum};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[k]);
            }
        }
    }
    return vector<vector<int>> (st.begin(),st.end());
}


// tc -> O(n*n*n). sc -> O(1). only vector is used to return the ans;
vector<vector<int>> FourSum_OPTIMAL(vector<int>nums, int target) {
    int n = nums.size();
    // sort array
    sort(nums.begin(),nums.end());

    // ans vector
    vector<vector<int>> ans;

    // loop for i
    for(int i=0; i<n; i++) {
        if(i>0 && nums[i]==nums[i-1]) continue; // skip if same

        // loop for j
        for(int j=i+1; j<n; j++) {
            if( j>i+1 && nums[j]==nums[j-1]) continue; // skip if same

            // fix k and l
            int k = j+1;
            int l = n-1;

            while(k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if(sum > (long long)target) {
                    l--;
                }
                else if(sum < (long long)target) {
                    k++;
                }
                else {
                    // sum matches
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++,
                    l--;
                    // update k and l until they are not same
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}


int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    // vector<vector<int>> ans = FourSum_BRUTE_FORCE(nums,target);
    // vector<vector<int>> ans = FourSum_BETTER(nums,target);
    vector<vector<int>> ans = FourSum_OPTIMAL(nums,target);

    for(auto i:ans) {
        for (auto j:i) {
            cout << j << " ";
        }cout << endl;
    }
}