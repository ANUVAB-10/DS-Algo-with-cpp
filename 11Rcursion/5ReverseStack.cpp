#include <bits/stdc++.h>
using namespace std;

void insertElm(stack<int>&s, int temp) {
    if(s.empty()) {
        s.push(temp);
        return;
    }
    auto top=s.top();
    s.pop();
    insertElm(s,temp);
    s.push(top);
}

void reverse(stack<int>&s) {
    if(s.empty()) {
        return ;
    }
    auto top = s.top();
    s.pop();
    reverse(s);
    insertElm(s,top);

} 

// tc->O(n^2) sc->O(n) stack space
int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
    
    reverse(s);
    while(!s.empty()) {
        cout << s.top() << " " ;
        s.pop();
    }


    
}