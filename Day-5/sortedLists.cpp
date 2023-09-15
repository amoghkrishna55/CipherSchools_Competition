#include<iostream>
#include<stack>
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
    if(head==NULL){
        cout << "Empty";
        return;
    }
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void sortedNode(Node* &head){
    bool val = true;
    while(val){
        bool test = true;
        Node* temp = head;
        while(temp->next!=NULL){
            if(temp->val>temp->next->val){
                swap(temp->val,temp->next->val);
                test = false;
            }
            temp = temp->next;
        }
        if(test){
            val = false;
        }
    }
}

Node* sortedLists(stack<Node*> s){
    Node* head = NULL;
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        if(head==NULL){
            head = temp;
            continue;
        }
        else{
            Node* temp2 = head;
            while(temp2->next!=NULL){
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
        sortedNode(head);
    }
    return head;
}

int main(){
    int a;
    cin >> a;
    if(a<0){
        cout << "Invalid";
        return 0;
    }
    stack<Node*> s;
    while(a--){
        Node* head = NULL;
        int n;
        cin >> n;
        if(n<0){
            cout << "Invalid";
            return 0;
        }
        while(n--){
            int val;
            cin >> val;
            insertNode(head, val);
        }
        s.push(head);
    }
    Node* head = sortedLists(s);
    displayNode(head);
}