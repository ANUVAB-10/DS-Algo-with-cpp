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

void f(Node* root, vector<int>&ans, int level) {
        if(!root)return ;
        if(ans.size() == level) {
            ans.push_back(root->val);
        }
        f(root->right,ans,level+1);
        f(root->left,ans,level+1);
}
vector<int> rightSideView(Node* root) {
    vector<int> ans;
    f(root,ans,0);
    return ans;
}


int main() {
    // tree build
    vector<optional<int>> nums = {1,2,7,3,nullopt,nullopt,8,nullopt,4,9,nullopt,5,6,10,11};
    Node* root = constructTree(nums);
    
    vector<int> ans = rightSideView(root);

    for(auto i:ans) {
        cout << i << " ";
    } cout << endl;

}
    