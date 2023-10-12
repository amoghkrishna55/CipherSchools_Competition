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

void divide(Node* &head, int n){
    Node* temp = head;
    Node* even = NULL;
    Node* prev = temp;
    while(temp!=NULL){
        if(temp->val%2==0){
            if(temp==head){
                even = head;
            }
            else if(even==NULL){
                Node* anchor = temp->next;
                prev->next = anchor;
                temp->next = head;
                head = temp;
                even = head;
                temp = anchor;
            }
            else{
                Node* anchor = temp->next;
                prev->next = anchor;
                temp->next = even->next;
                even->next = temp;
                even = temp;
            }
        }
        if(prev!=temp) prev=temp;
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    int a,b;
    cin >> a;
    while(a--){
        cin >>b;
        insertNode(head,b);
    }
    divide(head,1);
    displayNode(head);
}