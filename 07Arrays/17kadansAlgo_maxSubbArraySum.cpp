#include <bits/stdc++.h>
using namespace std;

// tc -> o(n*n) sc -> o(1)
int subArraySum(vector<int>a){
    int maxSum=INT_MIN;
    for(int i=0; i<a.size(); i++) {
        int sum=0;
        for(int j=i; j<a.size(); j++) {
            sum+=a[j];
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
}

// tc -> o(n) sc -> o(1)
int subArraySum_KadansAlgo(vector<int>a){
    int maxSum=INT_MIN;
    int sum=0;
    int start=0,ansStart=-1,ansEnd=-1;
    
    for(int i=0; i<a.size(); i++) {
        
        if(sum == 0) {
            start=i;
        }
        
        sum+=a[i];

        if(sum > maxSum) {
            maxSum=sum;
            ansStart=start;
            ansEnd=i;
        }

        if(sum<0) {
            sum=0;
        } 
    }

    // Printing the subarray
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << a[i] << " ";
    }
    cout << "]" << endl;

    return maxSum;
}





int main() {
    vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};
    cout << "Maximum subaaray Sum(Brute-Force): " << subArraySum(nums) << endl;
    cout << "Maximum subaaray Sum by Kadans Algo(Optimal): " << subArraySum_KadansAlgo(nums) << endl;
}