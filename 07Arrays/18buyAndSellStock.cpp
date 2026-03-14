#include <bits/stdc++.h>
using namespace std;

int buyAndSell_Brute(vector<int>a) {
    int maxi=0;
    for(int i=0; i<a.size(); i++) {
        for(int j=i+1; j<a.size(); j++) {
            maxi=max(maxi, a[j]-a[i]);
        }
    }
    return maxi;
}

int buyAndSell_Optimal(vector<int>a) {
    int maxi=0;
    int mindSellDay=a[0];

    for(int i=0; i<a.size(); i++) {
        maxi = max(maxi,a[i]-mindSellDay);
        mindSellDay=min(mindSellDay,a[i]);
    }
    return maxi;
}




int main() {
    vector<int>a = {7,1,5,3,6,4};

    cout << "max profit: " << buyAndSell_Brute(a) << endl;
    cout << "max profit_Optimal: " << buyAndSell_Optimal(a) << endl;
}