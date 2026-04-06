#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
    
    public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
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
void Traversal(Node* head) {
    Node* mover = head;

    while(mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }cout << endl;
}

void insertTail(Node* &head3, Node* &tail, int data) {
    Node* newNode = new Node(data);

    if(!head3) {
        head3 = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}
Node* Addll(Node* &head1, Node* &head2) {
    if(!head1) return head2;
    if(!head2) return head1;

    Node* t1=head1;
    Node* t2=head2;
    Node* head3 = nullptr;
    Node* tail = nullptr;
    // we will store the data in new ll
    int c=0;
    while(t1 && t2) {
        int sum=t1->data + t2->data + c;
        int digit = sum%10;
        c = sum / 10;
        insertTail(head3, tail ,digit);
        t1=t1->next;
        t2=t2->next;
    }
    // can happen that either exsist
    while(t1) {
        int sum = t1->data+c;
        int d=sum%10;
        c=sum/10;
        insertTail(head3,tail,d);
        t1=t1->next;
    }
    while(t2) {
        int sum = t2->data+c;
        int d=sum%10;
        c=sum/10;
        insertTail(head3,tail,d);
        t2=t2->next;
    }

    // still carry exists
    if(c) {
        insertTail(head3,tail,c);
    }
    return head3;
    
}

int main() {
    vector<int> nums = {2,4,9};
    vector<int> nums2 = {5,6,4,9};
    Node* head = ArrayToLinkedList(nums);
    Node* head2 = ArrayToLinkedList(nums2);
    Traversal(head);   
    Traversal(head2);
    Node* head3 = Addll(head,head2);
    Traversal(head3);
}