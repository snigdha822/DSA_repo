#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    public:
    node(int data1,node* next1) {
        data = data1;
        next = next1;
    }

    public:
     node(int data1) {
        data = data1;
        next = nullptr;
     }
};
node* convertArr2LL(vector<int> &arr) {
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        node* temp = new node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}
int lenghtOfLL(node* head) {
    int cnt = 0;
    node* temp = head;
    while(temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
int checkIfPresent(node* head, int val) {
    node* temp = head;
    while(temp) {
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

  void print(node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head->next;
    }
    cout << endl;
  }

node* removeHead(node* head) {
    if(head == NULL) return head;
    node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

node* deeleteTail(node* head){
    if(head == NULL || head->next == NULL) return NULL;
    
    node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;

    return head;
}
//deletion based on its position
node* removeK(node* head,int k){
    if(head == NULL) return head;
    if(k == 1){
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    node* temp = head;
    node* prev = NULL;
    while( temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev  = temp;
        temp = temp->next;
    }
    return head;

}
//deletion based on its value
node* removeEl(node* head,int el){
    if(head == NULL) return head;
    if(head->data == el){
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node* temp = head;
    node* prev = NULL;
    while( temp != NULL){
        
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev  = temp;
        temp = temp->next;
    }
    return head;
}
// inserting an element at the head
node* insertVal(node* head,int val){
    node* temp = new node (val,head);
    return temp;
}
// // inserting an element at Tail
node* insertTail(node* head,int val){
    if(head == NULL){
        return new node(val);
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    node* newNode = new node(val);
    temp->next = newNode;
    return head;
}
// inserting at kth position
node* insertKthPosn(node* head, int el, int k){
    if(head == NULL){
        if(k == 1) return new node(el);
        else return NULL;
    }
    if(k == 1){
        node* newNode = new node(el,head);
        return head;
    }
    int cnt = 0;
    node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            node* x = new node(el,temp->next);
            temp->next = x;
            return head;
            break;
        }
        temp = temp->next;
    }
    return head;
}
// inserting the basis of value
node* insertValue(node* head, int el, int val){
    if(head == NULL){
        return NULL;
    }
    if(head->data == val){
        node* newNode = new node(el,head);
        return head;
    }
    node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            node* x = new node(el,temp->next);
            temp->next = x;
            return head;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {2,1,5,23,9};
    node* head = convertArr2LL(arr);
    head = insertKthPosn(head,12,6);
    // cout << checkIfPresent(head,14);
    print(head);
}
