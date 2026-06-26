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


int height(Node* root) {
    if(!root) return 0;
    // right height
    int l = height(root->left);
    // left height
    int r = height(root->right);

    return 1+max(l,r);
}

// BF -> O(n*n)
int diameter(Node*root) {
    if(!root) return 0;
    // left height
    int l = height(root->left);
    
    // right height
    int r = height(root->right);
    return max(l+r,diameter(root->left)+diameter(root->right)); // diameter
}

// Better -> O(N)
int calcDiameter(Node* root,int &best) {
    if(!root) return 0;

    int l=calcDiameter(root->left, best);
    int r=calcDiameter(root->right, best);
    best = max(best, l+r);
    return 1+max(l,r);
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,5};
    Node* root = constructTree(nums);
    
    // cout << "diameter of the tree " << diameter(root); 
    
    // beter
    int best=0;
    calcDiameter(root,best);
    cout << "diameter of the tree " << calcDiameter(root,best); 

}