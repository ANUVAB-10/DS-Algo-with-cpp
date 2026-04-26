#include <bits/stdc++.h>
using namespace std;

void addOperators(string &nums, int target, int i, long long eval, long long prev, vector<string> &ans, string temp) {

    if(i==nums.size()) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        return;
    }

    for(int idx = i; idx < nums.length(); idx++) {
        string part = nums.substr(i,idx-i+1);
        if(part[0] == '0' && part.length()>1) {
            break;
        }

        long long num = stoll(part);
        if(i==0) {
            addOperators(nums,target-num,idx+1,num,num,ans,part);
        }
        else {
            // +
            addOperators(nums,target-num, idx+1, eval+num, num, ans, temp+"+"+part);
            // -
            addOperators(nums,target+num, idx+1, eval-num, -num, ans, temp+"-"+part);
            // -
            addOperators(nums, target+prev-prev*num, idx+1, eval-prev+prev*num, prev*num, ans, temp+"*"+part);
        }


    }
    
}

int main() {
    string nums = "123";
    int target = 6;
    vector<string> ans;
    string temp="";
    
    addOperators(nums,target,0,0,0,ans,temp);
    
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    }
}