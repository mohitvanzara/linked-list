#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};
Node* convertArr2DoubleLL(vector<int> &arr){
     Node* head = new Node(arr[0]); 
    // bydefault next and back are nullptr due to constructor
    Node* prev = head;
    for(int i =1; i <arr.size() ;i++){
        Node* temp =new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head; 
}
Node* insertionBeforeKth(Node* head,int val,int k){
    if(k==1){
         Node* NewHead = new Node(val, head,nullptr);
        head->back = NewHead;
        return NewHead;
    }
    Node* kNode =head;
    int cnt =0;
    while(kNode != NULL){
        cnt++;
        if(cnt==k) break;
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* NewNode =new Node(val,kNode,prev);
    prev->next =NewNode;
    kNode->back =NewNode;
    return head;
}
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    vector<int> arr ={1,2,3,4};
    Node* head = convertArr2DoubleLL(arr);
    head = insertionBeforeKth(head ,10, 1);
    print(head);

}