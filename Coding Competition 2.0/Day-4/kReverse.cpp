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

void kReverseNode(Node* &head, int k){
    if(k<=1){
        return;
    }
    Node* temp = head;
    Node* anchor = NULL;
    Node* lastNode = NULL;
    while(temp!=NULL){  
        anchor = temp;
        for(int i=0;i<k;i++){
            if(temp!=NULL){
                temp=temp->next;
            }
            else{
                lastNode->next = anchor;
                return;
            }
        }
        Node* prev = NULL;
        Node* next = anchor;
        Node* current = anchor;
        while(current!=temp && next!=temp){
            next = current->next;
            current->next = prev;
            prev = current;
            if(next!=temp){
                current = next;
            }
        }
        if(anchor==head){
            head = current;
            lastNode = anchor;
        }
        else{
            lastNode->next = current;
            lastNode = anchor;
        }
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
    kReverseNode(head,temp);
    displayNode(head);
}