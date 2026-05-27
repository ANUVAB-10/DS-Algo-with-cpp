#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    
    if(k >= num.length()) return "0";

    stack<char> st;
    
    int i=0;
    while(k && i != num.length()) {
        if(st.empty() || num[i] >= st.top()) {
            st.push(num[i++]);
        }
        else {
            while(k && !st.empty() && st.top() > num[i]) { // cehk the top of stack
                st.pop();
                k--; 
            }
            st.push(num[i++]);
        }
    }

    // check 
    while(i!=num.length()) {
        st.push(num[i++]);
    }

    while(k) {
        st.pop();
        k--;
    }

    string ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());


    // remove all leading zeroes
    while(ans.size() >= 1 && ans[0]=='0') {
        ans.erase(0,1);
    }
    // check even after removing all the leading zeroes if ans is empty then it is zero
    if(ans == "") return "0";
    return ans;
}

int main() {
    string s = "10";
    int k = 1;

    cout << removeKdigits(s,k) << endl;
}