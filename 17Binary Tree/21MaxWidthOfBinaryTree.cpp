// brute -> compute level orfer and return the max size of level

#include<bits/stdc++.h>
// #include "optional.hpp"
#include<optional>
using namespace std;

class Node {
    public:
    int val;
    Node* left=nullptr;
    Node* right=nullptr;

    Node(int x) {
        this->val=x;
    }

    Node(int x, Node* l, Node* r) {
        this->val=x;
        this->left=l;
        this->right=r;
    }

};

Node* constructTree(const vector<optional<int>>& nums) {
    if (nums.empty() || !nums[0].has_value())
        return nullptr;

    Node* root = new Node(*nums[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nums.size()) {
        Node* curr = q.front();
        q.pop();

        // left child
        if (i < nums.size()) {
            if (nums[i].has_value()) {
                curr->left = new Node(*nums[i]);
                q.push(curr->left);
            }
            ++i;
        }

        // right child
        if (i < nums.size()) {
            if (nums[i].has_value()) {
                curr->right = new Node(*nums[i]);
                q.push(curr->right);
            }
            ++i;
        }
    }

    return root;
}

int maxWidth(Node* root) {
    long long maxWidth=0;
    if(!root) {
        return maxWidth;
    }
    queue<vector<pair<Node*,long long>>> q;
    q.push({{root,0}});

    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        //calculate min index among all
        long long minI = INT_MAX;
        for(auto i:top) { // [{},{}..]
            if(minI > i.second) minI=i.second;
        }
        //max index
        long long maxI = top.back().second;

        maxWidth = max(maxWidth,maxI-minI+1);

        vector<pair<Node*, long long>> temp;
        for(auto i:top) {  // [{},{}..]
            // 1 based indexing
            long long rebased = i.second - minI;
            if(i.first->left) {
                temp.push_back({i.first->left, 2*rebased});
            }
            if(i.first->right) {
                temp.push_back({i.first->right, 2*rebased+1});
            }
        }
        if(!temp.empty()) q.push(temp); 
    }

    return (int)maxWidth;
}

int main() {
    // tree build
    vector<optional<int>> nums = {1, 2, 3, 4, 5, nullopt, nullopt, 6,7};

    Node* root = constructTree(nums);
    
    cout << "max width of binary tree: " << maxWidth(root) << endl;
}
