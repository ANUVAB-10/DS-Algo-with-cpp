#include <bits/stdc++.h>
using namespace std;

void generate_subsequnce(string s, string curr, vector<string> &ans, int i) {
    if(i==s.length()) {
        ans.push_back(curr);
        return;
    }

    // pick
    generate_subsequnce(s,curr+string(1,s[i]),ans,i+1);

    // then skip
    generate_subsequnce(s,curr,ans,i+1);
    

}   

int main() {
    string s = "abc";
    string curr = "";
    vector<string> ans;
    generate_subsequnce(s,curr,ans, 0);
    for (string& s : ans) {
        cout << s << " ";
    }
    cout << endl;
}