#include<iostream>
#include<climits>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

void insertNode(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    } 

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

int twin(Node* head){
    Node* tail = head;
    int max = INT_MIN;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    while(head->prev!=tail || tail->next!=head){
        int sum = tail->data + head->data;
        if(sum>max){
            max = sum;
        }
        tail = tail->prev;
        head = head->next;
    }

    return max;
}

int main(){
    Node* head = NULL;
    int a,b;
    cin >> a;
    if(a==0){
        cout << "0" << endl;
        return 0;
    }
    while(a--){
        cin >> b;
        insertNode(head,b);
    }
    cout << twin(head) << endl;
}