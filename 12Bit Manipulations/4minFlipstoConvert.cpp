#include<bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    return __builtin_popcount(start ^ goal);
}

int main() {
    int st = 16, goal = 15;
    cout << minBitFlips(st,goal) << endl;
}