#include <bits/stdc++.h>
using namespace std;

// tc->O(n*n)  sc -> O(1)
vector<pair<int,int>> TwoSumBrute(vector<int>a, int target) {
    vector<pair<int,int>> ans;
    int n=a.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(a[i]+a[j] == target) {
                ans.push_back({i,j});
            } 
        }
    }
    return ans;
}

// tc->O(n)+O(1) average,bes, tc->O(n*n) worst, sc -> O(n)
vector<pair<int,int>> TwoSumBetter(vector<int>a, int target) {
    vector<pair<int,int>> ans;
    unordered_map<int,int> mp;

    for(int i=0; i<a.size(); i++) {
        int remSum=target-a[i];

        if(mp.find(remSum)!=mp.end()) {// present 
            ans.push_back({i,mp[remSum]});
        }

        // just store the current elm in map
        mp[a[i]] = i;
    }
    return ans;
}


// tc-> O(nlogn)+O(n)  sc -> O(1)
// this will be a false one if u send indexes cause arrays gets changed while sorting can send yes or n
string TwoSumOptimal_Greedy(vector<int>&a, int target) {
    // sort
    sort(a.begin(), a.end());

    int i=0,j=a.size()-1;
    
    while(i<j) {
        int sum = a[i]+a[j];
        if(sum==target) {
            return "YES";
        }
        else if(sum > target) {
            j--;
        }
        else i++;
    }
    return "NO";
}


int main() {
    vector<int> a = {2,6,5,8,11};
    int target = 14;

    // vector<pair<int,int>> ans = TwoSumBrute(a,14);
    // vector<pair<int,int>> ans = TwoSumBetter(a,14);
    
    // for(auto i:ans) {
    //     cout << i.first << " " << i.second << endl;
    // }
    
    string ans = TwoSumOptimal_Greedy(a,14);
    cout << " pair exists ? : " << ans;
}