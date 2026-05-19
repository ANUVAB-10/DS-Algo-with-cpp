#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

int precedence(char ip) {
    if(ip == '^') return 3;
    else if(ip == '*' || ip == '/') return 2;
    else if(ip == '+' || ip == '-') return 1;
    else return 0;
}

string infixToPostfix(string ip) {
    stack<char> st;
    string ans = "";
    for(int i=0; i<ip.size(); i++) {
        
        // check for brackets
        if(ip[i] == '('){
            st.push(ip[i]);
        }
        else if(ip[i] == ')') {
            while(!st.empty() && st.top()!='(') {
                ans.push_back(st.top());
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop the '('
        }
        // if operand add to ans
        else if(!isOperator(ip[i])) {
            ans.push_back(ip[i]);
        }
        // operators
        else {
            if(st.empty() || (precedence(ip[i]) == precedence(st.top()))) st.push(ip[i]);
            else if(precedence(ip[i]) > precedence(st.top())) st.push(ip[i]);
            else {
                while(st.size() && (precedence(st.top()) > precedence(ip[i]))) {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(ip[i]);
            }
        }
    }

    // push remaining elements if stack not empty
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

string infixToPrefix(string ip) {
    // 1. reverse infix and change brackets to opposites
    reverse(ip.begin(),ip.end());

    for(auto &i:ip) { // the original string does NOT change because i is just a copy. so &i
        if(i == '(') i = ')';
        else if(i == ')') {
            i = '(';
        }
    }

    // 2. do infix to post fix
    string ans = infixToPostfix(ip);

    // 3. reverse the ans
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    string ip = "a+b*(c^d-e)";
    cout << "infix to prefix: " << infixToPrefix(ip) << endl;
}

// +a*b-^cde