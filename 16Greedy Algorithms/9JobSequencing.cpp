#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

bool cmp(const vector<int> &p, const vector<int> &q) {
    if(p[1] == q[1]) return p[2] > q[2]; // if deadline same return acc to max Profit
    return p[1] < q[1]; // retrun acc to min deadline
}

pair<int,int> JobSequence(vector<vector<int>> &Job) {

    sort(Job.begin(), Job.end(), cmp);

    // for first job
    int c=1;
    int profit = Job[0][2];
    // remaining jobs

    for(int i=1; i<Job.size(); i++) {
        if(Job[i][1]  == Job[i-1][1]) continue; // same deadline
        else {
            c++;
            profit+=Job[i][2];
        }
    }

    return {c,profit};
}

int main() {
    auto start = high_resolution_clock::now();
    
    vector<vector<int>> Job = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

    pair<int,int> ans = JobSequence(Job);
    cout << "no. of jobs: " << ans.first << " max profit: " << ans.second << endl;
    
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
}


/*
    2,1,10
    3,2,40
    4,2,30
    1,4,20

    profit=10+40+20,c=1+1+1
*/