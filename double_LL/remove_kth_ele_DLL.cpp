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
Node* deleteHead(Node* head){
    Node* temp1 = head;
    head = head->next;
    head->back = nullptr;
    temp1->next = nullptr;
    delete temp1;
    return head;

}
Node* deleteTail(Node* head){
    Node* temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    Node* prev2 = temp2->back;
    temp2->back = nullptr;
    prev2->next = nullptr;
    delete temp2;
    return head;

}
Node* removekthEle(Node* head, int k){
    if(head == NULL) return NULL;
    int cnt =0;
    Node* kNode = head;
    while(kNode != NULL){
        cnt++;
        if(cnt == k) break;
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;
    if(prev == NULL && front == NULL){
        //single element in DLL
        delete kNode;
        return head;
    }
    else if(prev == NULL){
        // standing on the head
        return deleteHead(head);
    }
    else if(front == NULL){
        // standing on the tail
        return deleteTail(head);
        
    }
    else{
        // between k( 1 to n )
        kNode->next = nullptr;
        kNode->back = nullptr; 
        prev->next = front;
        front->back = prev;
        delete kNode;
        return head;
    }

}
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    vector<int> arr ={1,2,3,4,5};
    Node* head = convertArr2DoubleLL(arr);
    head = removekthEle(head,5);
    print(head);
}