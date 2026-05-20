#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater2_BF(vector<int> &nums) {
   vector<int> ans(nums.size(),0);

   int n = nums.size();
   for(int i=0; i<n; i++) { // for every elem
    for(int j = i+1; j<i+n-1; j++) { // finding every possibility
        int ind = j%n;
        if(nums[ind] > nums[i]) {
            ans[i] = nums[ind];
            break;
         }
      }
   }

   return ans;
}

vector<int> NextGreater_2_optimised(vector<int>&nums) {
    vector<int> ans(nums.size(),-1);
    stack<int> st;  
    int n = nums.size();

    for(int i = 2*n-1; i>=0; i--) {
        int ind = i%n;
        while(!st.empty() && nums[ind] >= st.top()) {
            st.pop();
        }
        // push to array only when 
        ans[ind] = st.empty() ? -1 : st.top(); 
        st.push(nums[ind]);
    }
    return ans;
}


int main() {
    vector<int> nums = {2,10,12,1,11};
    vector<int> ans = NextGreater_2_optimised(nums);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}