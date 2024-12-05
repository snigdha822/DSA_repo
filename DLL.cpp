#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* back;
    
    public:
    node(int data1,node* next1,node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
// convrert an array to linkedlist
node* convertArr2DLL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* prev = head;
    for(int i=1; i<arr.size(); i++){
        node* temp = new node(arr[i], nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(node* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }   
}
//Delete head from LL
node* deleteHead(node* head){
    if(head == NULL || head->next == NULL) {
        return NULL;
      }
    node* prev = head;
    head = head->next;
    
    prev->next = nullptr;
    head->back = nullptr;
    free(prev);
    return head;
}
// Delete tail from LL
node* deleteTail(node* head){
    if(head == NULL || head->next == NULL) return NULL;
    node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }
    node* prev = tail->back;
    tail->back = nullptr;
    prev->next = nullptr;
    delete tail;
    return head;
}
// Delete Kth element from LL
node* deleteKthEle(node* head,int k){
    if(head == NULL) return NULL;
    node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    node* prev = temp->back;
    node* front = temp->next;

    if(prev == NULL && front == NULL) return temp;
    else if(prev == NULL){
        deleteHead(head);
        return head;
    }
    else if(front == NULL){
        deleteTail(head);
        return head;
    }
        prev->next = front;
        front->back = prev;
        temp->back = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    
}
// delete the node from LL (node != head)
void deleteNode(node* temp){
    node* prev = temp->back;
    node* front = temp->next;
    
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->back = temp->next = nullptr;
    delete temp;
}

// Insertion of a node 
node* insertBeforeTail(node* head, int val){
    node* tail = head;

    while(tail->next != nullptr){
        tail = tail->next;
    }
    node* prev = tail->back;
    node* newNode = new node(val,tail,prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}
int main(){
    vector<int> arr = {2,1,5,23,9};
    node* head = convertArr2DLL(arr);
    // head = deleteHead(head);
    // head = deleteKthEle(head,5);
    head = insertBeforeTail(head,10);
    // deleteNode(head->next);
    print(head);
    return 0;
}