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

vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> ans;
    
    if(!root) return ans;
    queue<vector<Node*>> q;
    q.push({root});
    bool rightToLeft=1;
    
    while(!q.empty()) {
        auto top = q.front();
        q.pop();

        // Current level values
        vector<int> temp;
        for (auto node : top)
            temp.push_back(node->val);

        // reverse the ans acc to flag
        if(rightToLeft) {
            reverse(temp.begin(),temp.end());
        }
        ans.push_back(temp);
        rightToLeft=!rightToLeft;
        
        // push the next level to queue
        vector<Node*>temp2;
        for(auto i:top) {
            if(i->left) temp2.push_back(i->left);
            
            if(i->right) temp2.push_back(i->right);
        }
        if(!temp2.empty()) q.push(temp2);
    }

    return ans;
}


int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,5};
    Node* root = constructTree(nums);
    
    vector<vector<int>> ans = zigzagLevelOrder(root);

    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    }

}
    