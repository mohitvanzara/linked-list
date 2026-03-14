/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    
    struct ListNode* traveling = head->next ;// skip first zero
    struct ListNode* temp = head;
    int sum = 0;
    while(traveling != NULL){
        if(traveling->val == 0){
            temp->val = sum;
            temp->next = traveling->next;
            temp = temp->next;
            sum = 0;
        }
        else{
            sum = sum + traveling->val;
        }
        traveling = traveling->next;
    }
    return head;
}