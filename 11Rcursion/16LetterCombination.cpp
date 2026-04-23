#include <bits/stdc++.h>
using namespace std;

void generateCombination(string input, string temp, vector<string> &ans, vector<string> phoneMap,  int i) { 
    // j->for same digit, i->different digit

    if(temp.size() == input.size()) {
        ans.push_back(temp);
        return;
    }
    
    for(int k = 0 ; k < phoneMap[input[i]-'0'].size() ; k++) {
        // 1st for fist digit
        temp+=phoneMap[input[i]-'0'][k];
        generateCombination(input, temp, ans , phoneMap, i+1);
        temp.pop_back();
    }
}


int main() {
    vector<string> phoneMap = {
    "", "", "abc", "def", "ghi",   
    "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string input = "34";
    vector<string> ans;
    generateCombination(input, "" , ans, phoneMap, 0);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }cout << endl;
    }


}