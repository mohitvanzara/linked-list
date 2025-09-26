#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }


};
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1 ;i<arr.size();i++){
        Node* temp =new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* removeKthPosition(Node* head,int k){
    //edge cases
    if(head == NULL) return NULL;
    if(k==1){
        //only one element present
        Node* temp = head;
        head =head->next;
        delete temp;
        return head;
    }
    // other case
    int cnt =0;
    Node* prev = NULL;
    Node* temp =head;
    while(temp!=NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            delete temp;
            break;

        }
        prev = temp;
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> arr ={10};
    Node* head = convertArr2LL(arr);
    head = removeKthPosition(head,1);
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    

}