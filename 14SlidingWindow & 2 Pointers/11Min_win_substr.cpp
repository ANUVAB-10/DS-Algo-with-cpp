#include<bits/stdc++.h>
using namespace std;

string minWindow_BF(string s, string t) {
    int minLen = INT_MAX;
    int stInd = -1;

    for(int i = 0; i < s.size(); i++) {
        unordered_map<char, int> mp;

        for(char c : t)
            mp[c]++;

        int count = 0;

        for(int j = i; j < s.size(); j++) {
            if(mp[s[j]] > 0)
                count++;

            mp[s[j]]--;

            if(count == t.size()) {
                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    stInd = i;
                }
                break;
            }
        }
    }

    return stInd == -1 ? "" : s.substr(stInd, minLen);
}

string minWindow_OP(string s, string t) {
    int l=0, r=0, cnt=0, minLen=INT_MAX, stInd=-1;
    
    // prestore
    unordered_map<char,int> mp;
    for(char i:t) mp[i]++;

    while(r < s.length()) {
        
        if(mp[s[r]] > 0) {
            cnt++;
        }

        mp[s[r]]--;

        while(cnt == t.length()) {
            if(r-l+1 < minLen) {
                minLen = r-l+1;
                stInd = l;
            }
            mp[s[l]]++;
            if(mp[s[l]] > 0) cnt--;
            l++;
        }

        r++;
    }
    return stInd == -1 ? "" : s.substr(stInd, minLen);
}


int main() {
    string s="ADOBECODEBANC";
    string t = "ABC";

    cout << "min window substring(BF): " << minWindow_BF(s,t) << endl;
    cout << "min window substring(OP): " << minWindow_OP(s,t) << endl;

}