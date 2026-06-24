#include<bits/stdc++.h>
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
  

vector<int> IterativePreOrder(Node* root) {
    vector<int> ans;

    if(!root) return ans;
 
    // use stack for maintaining order
    stack<Node*> sp;

    // push the root
    sp.push(root);

    // run until stack is not empty
    while(!sp.empty()) {
        // put the root
        Node* top = sp.top();
        sp.pop();
        ans.push_back(top->val);

        // put the right first
        if(top->right) sp.push(top->right);
        // put the left then;
        if(top->left) sp.push(top->left);
    }

    return ans;
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,5,nullopt,8,nullopt,nullopt,6,7,9};
    Node* root = constructTree(nums);
    
    vector<int> ans = IterativePreOrder(root);

    for(auto i:ans) {
        cout << i << " ";
    } cout << endl;
}