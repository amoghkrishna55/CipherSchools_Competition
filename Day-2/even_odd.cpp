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

void segregateNode(Node* &head){
    Node* odd = head;
    Node* even = head->next;
    Node* currEven = even;
    Node* temp = even->next;
    Node* current = NULL;
    int index = 1;
    while(temp!=NULL){
        if(index%2!=0){
            current = temp->next;
            temp->next = even;
            odd->next = temp;
            odd = temp;
        }
        else{
            current = temp->next;
            temp->next = NULL;
            currEven->next = temp;
            currEven = temp;
        }
        temp = current;
        index++;
    }
}

int main(){
    Node* head = NULL;
    int a,b;
    cin >> a;
    if(a<=0){
        cout << 0;
        return 0;
    }
    if(a==1){
        cin >> b;
        cout << b;
        return 0;
    }
    while(a--){
        cin >> b;
        insertNode(head,b);
    }
    segregateNode(head);
    displayNode(head);
}