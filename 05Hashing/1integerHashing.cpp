#include<iostream>
using namespace std;
#include<vector>

void preCompute(vector<int>a, vector<int>&hash){
    for(auto i:a) hash[i]++;
}

void fetchFor(vector<int>checkFor, vector<int>hash) {
    for(auto i:checkFor) cout << hash[i] << " ";
}

int main() {

    // hashing -> prestore + fetching
    // lets say the ip array is -> [1 3 2 1 3]
    // check freq for [1 4 2 3 12]
    vector<int> a = {1,3,2,1,3};
    vector<int> checkfor = {1,4,2,3,12};

    vector<int> hash(13,0);

    preCompute(a,hash);
    fetchFor(checkfor, hash);

}