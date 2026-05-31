#include<bits/stdc++.h>
using namespace std;

int maxLen_BF(string s) { // sc->o(256) tc->O(2n)
    int hash[256] = {0}; // hash

    int maxLen=0;
    int len = 0;
    for(int i=0; i<s.length(); i++) {
        string substr="";
        for(int j=i; j<s.length(); j++) {
            // if not seen then only add
            if(hash[int(s[j])] == 0) {
                substr += string(1,s[j]);
                hash[int(s[j])] = 1;
                len=max(len,j-i+1);
            }
            else break;
        }
    }
    return len;
}

int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    unordered_map<char,int> mp;
    
    int l=0,r=0, len=0;
    while(l<s.length() && r<s.length()) {
        // not found
        if(mp.find(s[r]) == mp.end()) {
            mp[s[r]] = r;
        }
        else { // found
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l=mp[s[r]] + 1;
                mp[s[r]] = r;
            }
            else {
                mp[s[r]] = r;
            }
        }
        len = max(len,r-l+1);
        r++;
    }
    return len;
}


int main( ) {
    string s = "cadbzabcd";

    cout << "max len(bf): " << maxLen_BF(s) << endl ;
    cout << "max len(bf): " << lengthOfLongestSubstring(s) << endl ;
}