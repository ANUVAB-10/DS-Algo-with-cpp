#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left=nullptr;
    Node* right=nullptr;

    Node(int x) {
        this->data=x;
    }

    Node(int x, Node* l, Node* r) {
        this->data=x;
        this->left=l;
        this->right=r;
    }
};

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->left = new Node(3);

}