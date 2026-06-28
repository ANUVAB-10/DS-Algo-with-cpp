#include<bits/stdc++.h>
#include "optional.hpp"
// #include<optional>
using namespace std;
#include <chrono>
using namespace chrono;


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

bool printPath(Node* root, int data, vector<Node*>& ans) {
    if(!root) return false;
    ans.push_back(root);
    if(root->val == data) return true;

    if( printPath(root->left,data,ans) || printPath(root->right,data,ans) ) 
        return true;

    // backtrack
    ans.pop_back();
    return false;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    vector<Node*> path1 ,path2;
    printPath(root,p->val,path1);
    printPath(root,q->val,path2);

    int i=0;
    Node* ans;
    while(i<path1.size() && i<path2.size() && path1[i] == path2[i]) {
        ans=path1[i];
        i++;
    }
    return ans;
}

// better 
Node* LCA(Node* root, Node* p, Node* q) {
    if(!root || root==p || root==q) {
        return root;
    }
    Node* left = LCA(root->left,p,q);
    Node* right = LCA(root->right, p, q);

    if(left && right) {
        return root;
    }

    return left ? left : right;
}

int main() {
    auto start = high_resolution_clock::now();
    // tree build
    vector<optional<int>> nums = {3,5,1,6,2,0,8, nullopt, nullopt, 7,4};

    Node* root = constructTree(nums);
    
    cout << "Lowest Common Ancestor: " << lowestCommonAncestor(root,root->left,root->right)->val << endl;
    cout << "Lowest Common Ancestor: " << LCA(root,root->left,root->right)->val << endl;

    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
}
