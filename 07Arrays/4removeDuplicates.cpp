#include <bits/stdc++.h>
using namespace std;

// t.c -> O(n) s.c -> O(n)
int removeDuplicate(vector<int>a) {
    set<int> seen;
    int c=0;

    for(auto i:a){
        // check if present or not
        if(seen.find(i)==seen.end()) {
            seen.insert(i);
            a[c]=i;
            c++;
        }
    }return c;
}

// t.c -> O(n) s.c -> O(1)
int uniqueElms(vector<int>a) {
    int i=0, j=i+1;
    while(j<=a.size()-1) {
        if(a[i]!=a[j]) {
            a[i+1]=a[j];
            i++;
        }
        else {
            j++;
        }
    }
    return i+1; // because i we are doing it as index
}


int main() {
    vector<int>a={1,1,2,2,2,3,3};
    cout  << " unique elements: "  << removeDuplicate(a);
    cout  << " unique elements(optimal): "  << uniqueElms(a);
}