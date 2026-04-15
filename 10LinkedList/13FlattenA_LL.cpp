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
        mover->child = temp;
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
void traversal_child(Node*head) {
    Node* temp=head;
    if(!head)return;
    while(temp) {
        cout << temp->data << " ";
        temp=temp->child;
    }return;
}

Node* mergeLL(Node* h1, Node* h2) {
    Node* dummy=new Node(-1);
    Node* moverDum=dummy;
    while(h1 && h2) {
        if(h1->data <= h2->data) {
            moverDum->child=h1;
            h1=h1->child;
        }
        else {
            moverDum->child=h2;
            h2=h2->child;
        }
        moverDum=moverDum->child;
        moverDum->next=nullptr;
    }
    if(h1) {
        moverDum->child=h1;
    }else {
        moverDum->child=h2;
    }
    return dummy->child;
}
void flatten_Optimal(Node* &head) {
    if(!head || !head->next) return;
    if(head && head->next) {
        flatten_Optimal(head->next);
    }

    head = mergeLL(head,head->next);
    head->next=nullptr;
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
    // flatten_BF(head);
    flatten_Optimal(head);
    traversal_child(head);
}