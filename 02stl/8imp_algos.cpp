#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // if second same
    return p1.first > p2.first;
}

int main() {

    // -------- Integer array ----------
    int arr[] = {5, 2, 8, 1, 9};
    int n = 5;

    sort(arr, arr+n);

    vector<int> v = {10, 3, 6, 2};
    sort(v.begin(), v.end());

    sort(arr+2, arr+4);

    // descending
    sort(arr, arr+n, greater<int>());

    // -------- Pair array ----------
    pair<int,int> p[] = {{1,2},{2,1},{4,1}};
    int m = 3;

    sort(p, p+m, comp);
    // Expected: (4,1), (2,1), (1,2)

    // -------- builtin_popcount ----------
    int num = 7;
    int cnt = __builtin_popcount(num);
    cout << "Set bits in 7: " << cnt << endl;

    // -------- next_permutation ----------
    string s = "123";
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));

    // -------- max_element ----------
    pair<int,int> maxi = *max_element(p, p+m);
    cout << "Max pair: (" << maxi.first << "," << maxi.second << ")" << endl;

}