#include <bits/stdc++.h>
using namespace std;

double GasStationSolver_BF(vector<int> nums, int k) {

    int n=nums.size();
    // no. of spots
    vector<int> howMany(n-1,0);

    for(int gasStation=0; gasStation<k; gasStation++) {
        double maxDis = -1;
        int maxInd=-1;

        for(int i=0; i<n-1; i++) {
            double dis = (nums[i+1]-nums[i]) /(double)(howMany[i]+1);
            if(dis > maxDis) {
                maxDis = dis;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    // after this the howmany are set
    double ans = -1;
    for(int i=0; i<n-1; i++) {
        double dis = (nums[i+1]-nums[i]) / (howMany[i]+1);
        ans = max(ans,dis);
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int k=4;

    cout << "the maximum difference between adjacent gas stations is (BF):" << GasStationSolver_BF(nums,k) << endl;
}