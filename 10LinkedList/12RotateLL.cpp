#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int x) {
        data = x;
        next=NULL;
    }

    public:
    Node(int x, Node* n) {
        data = x;
        next=n;
    }
};
Node* ArrayToDLL(vector<int> nums) {
    Node* head = new Node(nums[0]);
    Node* temp = head;

    for(int i=1; i<nums.size(); i++) {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}
void traversal(Node* head) {
    Node* temp = head;

    while(temp) {
        cout << temp->data << " ";
        temp=temp->next;
    }cout << endl;
}
Node* reverseLL_Recursive(Node* head) {
    // base case
    if(!head || !head->next) {
        return head;
    }
    Node* newHead = reverseLL_Recursive(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newHead;
}
void rotateLL(Node*&head, int k) {
    Node* tail=head;
    int c=1;
    while(tail->next){ 
        c++;
        tail=tail->next;
    }
    
    
    k=k%c;
    if(k==0) return;
    
    // connect tail
    tail->next=head;
    int i=1;
    Node* temp=head;
    while(i!=c-k) {
        temp=temp->next;
        i++;
    }

    if(temp->next)head=temp->next;
    temp->next=nullptr;

    return;

}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    Node* head = ArrayToDLL(nums);
    traversal(head);
    rotateLL(head,3);
    traversal(head);
    
}