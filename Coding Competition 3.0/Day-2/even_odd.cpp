#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        next = NULL;
    }
};

void insertNode(Node* &head, int val){
    Node* n = new Node(val);

    if(head==NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void displayNode(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* divide(Node* &head) {
    Node* temp = head;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->val % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = temp;
                evenTail = temp;
            } 
            else {
                evenTail->next = temp;
                evenTail = temp;
            }
            if (prev == NULL) {
                head = temp->next;
            } 
            else {
                prev->next = temp->next;
            }
            temp = temp->next;
        } 
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    if (evenHead != NULL) {
        evenTail->next = head;
        head = evenHead;
    }
    return head;
}

int main(){
    Node* head = NULL;
    int a,b;
    cin >> a;
    while(a--){
        cin >>b;
        insertNode(head,b);
    }
    displayNode(divide(head));
}