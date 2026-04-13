#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* child;

    public:
    Node(int data, Node* next, Node* child) {
        this->data = data;
        this->next = next;
        this->child=child;
    }
    
    public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->child=nullptr;
    }
};
void Traversal(Node* head) {
    Node* mover = head;

    while(mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }cout << endl;
}
Node* ArrayToLinkedList(vector<int> nums) {
    Node* head = new Node(nums[0]);
    Node* mover = head;

    for(int i=1; i<nums.size(); i++) {
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void flatten_BF(Node*&head) {
    vector<int> a;

    Node* temp=head;
    Node* t2=head;
    while(temp) {
        t2=temp;
        while(t2) {
            a.push_back(t2->data);
            t2=t2->child;
        }
        temp=temp->next;
    }

    sort(a.begin(),a.end());

    head=ArrayToLinkedList(a);

}

int main() {
    Node* head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    Traversal(head);
    flatten_BF(head);
    Traversal(head);
}