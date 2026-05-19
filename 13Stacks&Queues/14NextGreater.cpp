#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> nums){
    stack<int> st;
    vector<int> ans(nums.size(),0);
    for(int i = nums.size()-1; i>=0; i--) {
        if(st.empty()) {
            ans[i] = -1;
        }
        else if(st.top() > nums[i]) {
            ans[i] = st.top();
        }
        // pop out until st.top > nums[i]
        else {
            while(st.top() < nums[i]) {
                st.pop();
            }
            ans[i] = st.top();
        }
        // push the curr element
        st.push(nums[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {4, 5, 2, 10};
    vector<int> ans = nextGreater(nums);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}