#include <bits/stdc++.h>
using namespace std;

// tc -> O(n) sc-> O(n)
void rearrangeArrayElm_Better(vector<int>a) {
    int pos=0;
    int neg=1;
    vector<int>ans(a.size(),0);
    for(int i=0; i<a.size(); i++) {
        
        if(a[i]>0) {
            // even index
            ans[pos]=a[i];
            pos+=2;
        }
        else {
            ans[neg]=a[i];
            neg+=2;
        }
    }
    
    for(auto i:ans) cout << i << " ";
} 


// tc -> O(n) sc-> O(n)
void rearrangeArrayElm_Better_UneuqalNumber(vector<int>a) {
    int n=a.size();
    vector<int> pos, neg;

    for(auto i:a) {
        if(i>0) pos.push_back(i);
        else neg.push_back(i);
    }

    if(pos.size()>neg.size()) {
        for(int i=0; i<neg.size(); i++) {
            a[i*2] = pos[i];
            a[i*2+1] = neg[i];
        }
        // fill remaining pos array elm;
        for(int i=2*neg.size(); i<pos.size(); i++) {
            a.push_back(a[i]);
        }
    }

    else {
        for(int i=0; i<pos.size(); i++) {
            a[i*2] = pos[i];
            a[i*2+1] = neg[i];
        }
        // fill remaining pos array elm;
        for(int i=2*pos.size(); i<neg.size(); i++) {
            a.push_back(a[i]);
        }
    }

    for(auto i:a) cout << i << " ";
}


int main() {
    vector<int>a = {1,2,-3,-1,-2,-3};
    // rearrangeArrayElm_Better(a);
    rearrangeArrayElm_Better_UneuqalNumber(a);
}