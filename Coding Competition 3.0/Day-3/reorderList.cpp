#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};

void insertListNode(ListNode* &head, int val){
    ListNode* n = new ListNode(val);

    if(head==NULL){
        head = n;
        return;
    }

    ListNode* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void displayListNode(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void rearrange(ListNode* &head){
     ListNode* temp = NULL;
     ListNode* start = head;
     ListNode* prev = NULL;
     int trigger = 1;
     while(start!=NULL && start->next!=NULL){
        if(trigger==1){
            trigger = 0;
            temp = start;
        }
        if(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
            continue;
        }
        trigger = 1;
        prev->next = NULL;
        temp->next = start->next;
        start->next = temp;
        start = temp->next;
     }
}

int main(){
    ListNode* head = NULL;
    int a,b;
    cin >> a;
    while(a--){
        cin >>b;
        insertListNode(head,b);
    }
    rearrange(head);
    displayListNode(head);
}