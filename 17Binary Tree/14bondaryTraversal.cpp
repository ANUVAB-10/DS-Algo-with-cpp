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

// not complete..
// https://excalidraw.com/#json=RcitLkQFe3Ay9A9xAcrcM,wUfN8VFMyMviRqQqTNyEHg

void boundary(Node* root, vector<int>&ans) {
    if(!root) return ;
    ans.push_back(root->val);

    if(root->left) boundary(root->left,ans);
    if(root->right) boundary(root->right, ans);
}

vector<int> boundaryTraversal(Node*root) {
    vector<int> l,r ;
    boundary(root,l);
    boundary(root->right,r);
    reverse(r.begin(),r.end());
    l.insert(l.end(),r.begin(),r.end());
    return l;
}
gj

int main() {
    // tree build
    vector<optional<int>> nums = {3,9,20,nullopt,nullopt,15,7};
    Node* root = constructTree(nums);
    
    vector<int> ans = boundaryTraversal(root);

    for(auto i:ans) {
        cout << i << " ";
    } cout << endl;

}
    