#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

bool lemonadeChange(vector<int>& bills) {
    int five=0, ten=0;
    for(auto i:bills) {
        if(i == 5) five++;
        else if(i == 10) {
            if(five) {
                five--;
                ten++;
            }
            else return false;
        }
        else {
            if(five && ten) {
                ten--;
                five--;
            }
            else if(five >= 3) {
                five-=3;
            }
            else return false;
        }
    }
    return true;
}

int main() {
    auto start = high_resolution_clock::now();
    
    vector<int> nums = {5,5,5,10,20};
    // each lemonade costs $5, nums -> customer's denomination
    cout << "possible to pay: " << lemonadeChange(nums) << endl;
    
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
}