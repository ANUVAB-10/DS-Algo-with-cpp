#include <bits/stdc++.h>
using namespace std;

bool checkSort(vector<int>a, int i) {
    if(i>=a.size()-1) return true;

    if(a[i]>a[i+1]) return false;
    return checkSort(a,i+1); 

}

int main() {
    vector<int> a = {2,5,1,3,0};
    cout << "Is Sorted: " << checkSort(a,0);
}
