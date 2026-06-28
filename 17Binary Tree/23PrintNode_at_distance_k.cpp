// brute -> compute level orfer and return the max size of level

#include<bits/stdc++.h>
#include "optional.hpp"
// #include<optional>
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

// traverse from target
void dfs(Node* root, int k, vector<int> &ans, int d, unordered_map<Node*, Node*> &parent, unordered_map<Node*,bool> &visited) {
    if(!root || visited[root]) return; 
    // increase distance & store the curr value in visited
    visited[root]=1;
    // check if reached distance
    if(d==k) {
        ans.push_back(root->val);
        return;
    }
    dfs(root->left,k,ans,d+1,parent,visited);
    dfs(root->right,k,ans,d+1,parent,visited);
    dfs(parent[root],k,ans,d+1,parent,visited);
}   

vector<int> distanceK(Node* root, Node* target, int k) {
    // fist find the parent Nodes map
    unordered_map<Node*, Node*> parent;
    queue<Node*> q; q.push(root);parent[root]=nullptr;
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        // map the ans;
        if(top->left) {
            parent[top->left]=top;
            q.push(top->left);
        }
        if(top->right) {
            parent[top->right]=top;
            q.push(top->right);
        }
    }   

    // parent map is ready
    // traverse the parent map
    vector<int> ans;
    unordered_map<Node*,bool> visited;
    dfs(target,k,ans,0,parent,visited); // 0 -> 0 distance

    return ans;
}

int main() {
    // tree build

    vector<optional<int>> nums = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    Node* root = constructTree(nums);

    vector<int> ans = distanceK(root,root->left, 2);

    for(auto i:ans) {
        cout << i << " ";
    } cout << endl;

    
}
