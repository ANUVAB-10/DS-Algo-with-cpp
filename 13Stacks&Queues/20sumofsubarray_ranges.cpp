#include <bits/stdc++.h>
using namespace std;

// NSE: Next Smaller Element - finds index of next element smaller than current (from right)
vector<int> NSE(vector<int>& nums) {
    stack<int> st; int n = nums.size();
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

// PSEE: Previous Smaller or Equal Element - finds index of previous element <= current (from left)
vector<int> PSEE(vector<int>& nums) {
    stack<int> st; int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

// NGE: Next Greater Element - finds index of next element greater than current (from right)
vector<int> NGE(vector<int>& nums) {
    stack<int> st; int n = nums.size();
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

// PGEE: Previous Greater or Equal Element - finds index of previous element >= current (from left)
vector<int> PGEE(vector<int>& nums) {
    stack<int> st; int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

// Calculate sum of all subarray ranges (max - min for each subarray)
// Time: O(n), Space: O(n)
long long sumSubarray_Range(vector<int>& nums) {
    int n = nums.size();

    // Get helper arrays using monotonic stack techniques
    vector<int> nse  = NSE(nums);   // Next smaller element indices
    vector<int> pse  = PSEE(nums);  // Previous smaller/equal element indices
    vector<int> nge  = NGE(nums);   // Next greater element indices
    vector<int> pgee = PGEE(nums);  // Previous greater/equal element indices

    long long sumMin = 0, sumMax = 0;

    for (int i = 0; i < n; i++) {
        // Calculate contribution of nums[i] as minimum in subarrays
        long long left  = i - pse[i];   // Count of subarrays where nums[i] is minimum
        long long right = nse[i] - i;
        sumMin += (long long)nums[i] * left * right;

        // Calculate contribution of nums[i] as maximum in subarrays
        long long leftMax  = i - pgee[i];  // Count of subarrays where nums[i] is maximum
        long long rightMax = nge[i] - i;
        sumMax += (long long)nums[i] * leftMax * rightMax;
    }

    return sumMax - sumMin;
}

int main() {
    vector<int> nums = {1,2,3};
    cout << sumSubarray_Range(nums) << endl;
}