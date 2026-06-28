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

int childrenSum(Node* root) {
    if(!root) return 0;
    if(root) return root->val;
    int l=childrenSum(root->left);
    int r=childrenSum(root->right);

    // returned from children
    if(left && right) {
        if(l+r > root->val) {
            root->val=l+r;
        } else {
            // change any childs value
            root->left->val = root->val - root->right->val;
        }
    }
    if(!left || !right) {
        if(!left) {
            if(l > root->val) root->val=l;
            else root->left->val = root->val;
        }
        else {
            if(r > root->val) root->val=r;
            else root->right->val = root->val;
        }k
    }
}

int main() {
    // tree build
    vector<optional<int>> nums = {2, 35, 10, 2, 3, 5, 2};

    Node* root = constructTree(nums);
    
    childrenSum(root);

    
}
