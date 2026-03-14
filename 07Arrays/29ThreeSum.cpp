#include <bits/stdc++.h>
using namespace std;

// tc->O(n*n*n*logn*nlogn)  sc ->  O(n+n)
vector<vector<int>> ThreeSumBrute(vector<int>a) {
    vector<vector<int>> ans;
    set<vector<int>> st;

    int n=a.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(a[i]+a[j]+a[k] == 0) {
                    vector<int> temp = {a[i],a[j],a[k]};
                    sort(temp.begin(),temp.end());
                    st.insert({temp});
                }
            }
        }
    }
    return vector<vector<int>> (st.begin(),st.end()) ;
}

// tc-> O(n*n*logn*nlogn) , sc -> O(2n) 
vector<vector<int>> ThreeSumBetter(vector<int>a) {
    vector<vector<int>> ans;
    set<vector<int>> st;

    for(int i=0; i<a.size(); i++) {
        set<int> hashSet; // for storing sum

        for(int j=i+1; j<a.size(); j++) {
            int remSum = -a[i]-a[j];
            if(hashSet.find(remSum) != hashSet.end()) { // present
                vector<int> temp = {a[i],a[j],remSum};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            // insert curr j elm
            hashSet.insert(a[j]);
        }
    }
    
    for(auto i:st) ans.push_back(i);
    return ans;
    
}


// tc-> O(nlogn)+O(n*n)  sc -> O(no. uniuqe elm)
vector<vector<int>> ThreeSumOptimal(vector<int>&a) {
    vector<vector<int>> ans;
    // sort
    sort(a.begin(), a.end());

    for(int i=0; i<a.size(); i++) {
        if(i > 0 && a[i] == a[i-1]) continue;
        int j=i+1;
        int k=a.size()-1;

        
        while(j<k) {
            int sum = a[i]+a[j]+a[k];
            if(sum > 0) {
                k--;
            }   
            else if(sum < 0) {
                j++;
            }
            else {
                ans.push_back({a[i],a[j],a[k]});
                j++;
                k--;
                while(j < k && a[j]==a[j-1]) j++;
                while(j < k && a[k]==a[k+1]) k--;
            }
        }
    }
    return ans;
}


int main() {
    vector<int> a = {-100,-70,-60,110,120,130,160};

    // vector<vector<int>> ans = ThreeSumBrute(a);
    // vector<vector<int>> ans = ThreeSumBetter(a);
    vector<vector<int>> ans = ThreeSumOptimal(a);
    
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }cout << endl;
    }
    
}