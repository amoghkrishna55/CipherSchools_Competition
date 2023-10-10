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

void insert(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=n;
}

int solution(Node* head, int arr[], int arrSize){
    bool state = false;
    int connections = 0;
    Node* temp = head;
    while(temp!=NULL){
        bool find = false;
        for(int i=0; i<arrSize; i++){
            if(temp->val == arr[i]){
                find = true;
                break;
            }
        }
        if(!state && find){
            state = true;
            connections++;
        }
        else if(state && !find){
            state = false;
        }
        temp = temp->next;
    }
    return connections;
}

int main(){
    Node* head = NULL;
    int a,b,arr[103];
    cin >> a;
    while(a--){
        cin >> b;
        insert(head,b);
    }
    cin >> a;
    for(int i=0;i<a;i++){
        cin >> arr[i];
    }
    cout << solution(head,arr,a);
}