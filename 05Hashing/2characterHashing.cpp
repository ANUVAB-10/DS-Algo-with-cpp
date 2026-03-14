#include<iostream>
using namespace std;

void preCompute(string s, vector<int>&hash) {
    for(auto i:s) hash[i-'a']++;
    // for(auto i:hash) cout << i << " ";
}


void computeFreq(string query, vector<int>hash) {
    for(auto i:query) cout << hash[i-'a'] << " ";
}


int main() {
    string s = "abcdabehf";
    string queries = "aghbc";
    vector<int> hash(26,0);
    // cout << 'b'-'a';
    preCompute(s,hash);
    computeFreq(queries, hash);

}



// incase of 256 characters what you have to do was: create hash[256] array 
// in case of preCompute -> do hash[i-0] because we need to start it from charcater having '0' ASCII value
// same for fetching -> do hash[i-0] 