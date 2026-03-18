/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int stack[100000]; // drawback in memory
    int top =-1;
    struct ListNode* temp =head;
    while(temp!=NULL){
        stack[++top] = temp->val;
        temp = temp->next;
    }
    temp =head;
    while(temp!=NULL){
        if(temp->val != stack[top]){
            return false;
        }
        top--;
        temp = temp->next;
    }
    return true;
    
}