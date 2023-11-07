#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int val){
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

void insertListNode(ListNode* &head, ListNode* &tail, int val){
    ListNode* n = new ListNode(val);
    if(head==NULL){
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void displayListNode(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* partition(ListNode* &head, ListNode* &tail){
    int pivotValue = head->val;
    ListNode* pivot = head;
    ListNode* temp = head->next;

    while (temp != tail->next) {
        if (temp->val < pivotValue) {
            pivot = pivot->next;
            swap(temp->val, pivot->val);
        }
        temp = temp->next;
    }

    swap(head->val, pivot->val);
    return pivot;
}


void quickSortListNode(ListNode* &head, ListNode* &tail) {
    if (head != NULL && tail != NULL && head != tail && head != tail->next) {
        ListNode* p = partition(head, tail);
        quickSortListNode(head, p->prev);
        quickSortListNode(p->next, tail);
    }
}


void deleteLL(ListNode* &head){
    ListNode* temp = head;
    while(temp){
        ListNode* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
}

int main(){
    int a;
    cin >> a;
    while(a--){
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int val;
            cin >> val;
            insertListNode(head,tail,val);
        }
        quickSortListNode(head,tail);
        displayListNode(head);
        deleteLL(head);
    }
    return 0;
}