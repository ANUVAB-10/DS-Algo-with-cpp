
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& a, int k) {
    if(a.size()==0) return;
    k = k%a.size(); // no.of rotations
    
    // store first k values into temp
    vector<int> temp ; 
    for(int i=0; i<k; i++) {
        temp.push_back(a[i]);
    }
    
    // shifting
    for(int i=k; i<a.size(); i++) {
        a[i-k]=a[i];
    }
    
    // replace back
    for(int i=a.size()-k; i<a.size(); i++) {
        a[i] = temp[i-(a.size()-k)];
    }
}

void rotateOptimal(vector<int>&a, int k) {
    k=k%a.size();
    if(!a.size())return;

    // reverse first k elm
    reverse(a.begin(), a.begin()+k);
    // revres k to n emls
    reverse(a.begin()+k, a.end());
    // reverse whole array
    reverse(a.begin(),a.end());

}


int main() {
    vector<int>a = {1,2,3,4,5,6,7};
    // rotate(a, 3);   // 4 5 1 2 3
    rotateOptimal(a, 3);   // 4 5 1 2 3

    for(auto i:a) cout << i << " ";
}