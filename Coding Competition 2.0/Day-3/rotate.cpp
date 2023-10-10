#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val=val;
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

void rotateNode(Node* &head, int k){
    if(head->next==NULL){
        return;
    }
    for(int i=0;i<k;i++){
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next;
        temp->next = NULL;
    }
}

int main(){
    Node* head = NULL;
    int sizeOfNode,temp;
    cin >> sizeOfNode;
    if(sizeOfNode<=0){
        cout << "Invalid" << endl;
        return 0;
    }
    while(sizeOfNode--){
        cin >> temp;
        insertNode(head,temp);
    }
    cin >> temp;
    rotateNode(head,temp);
    displayNode(head);
}