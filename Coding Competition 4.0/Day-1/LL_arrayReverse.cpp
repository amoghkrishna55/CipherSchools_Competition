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

ListNode* arrayReverse(ListNode* &head, int arr[],int size,int n=0){
    if(n==size){
        return head;
    }
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    int count =0;
    while(curr!=NULL && count<arr[n]){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL){
        head->next = arrayReverse(next,arr,size,n+1);
    }
    return prev;
}

void deleteLL(ListNode* &head){
    ListNode* temp = head;
    while(temp!=NULL){
        ListNode* n = temp->next;
        delete temp;
        temp = n;
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
    cin >> a;
    int* arr = new int[a];
    for(int i=0;i<a;i++){
        cin >> arr[i];
    }
    head = arrayReverse(head,arr,a);
    displayListNode(head);
    delete [] arr;
    deleteLL(head);
    return 0;
}