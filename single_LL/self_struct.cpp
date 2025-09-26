#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
    node(int data1,node* next1){
        data = data1;
        next = next1;
        
    }
    
};
int main(){
    vector<int> arr ={2,3,5};
    node* y = new node(arr[0],nullptr);
    cout<<y->next;
    node* y1 = new node(arr[1],nullptr);
    cout<<y1;
}