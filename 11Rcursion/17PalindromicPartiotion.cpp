#include <bits/stdc++.h>
using namespace std;

void palindromicPartitioning(string ip, vector<string> temp, vector<vector<string>>& ans, int i) {
    // Base case: if we've reached the end of the string, add the current partition to results
    if (i == ip.length()) {
        ans.push_back(temp);
        return;
    }

    // Try all possible substrings starting from index i
    for (int j = i; j < ip.length(); j++) {
        // Extract substring from i to j
        string sub = ip.substr(i, j - i + 1);
        // Check if the substring is a palindrome by comparing it with its reverse
        if (sub == string(sub.rbegin(), sub.rend())) {
            // If palindrome, add to current partition and recurse for the next part
            temp.push_back(sub);
            palindromicPartitioning(ip, temp,ans,j+1);
            temp.pop_back();
        }
    }
}

int main() {
    string ip = "aab";
    vector<string> temp;
    vector<vector<string>> ans;
    palindromicPartitioning(ip ,temp,ans,0);
    for(auto i:ans) {
        for(auto j : i) {
            cout << j << " ";
        } cout << endl;
    }
}

