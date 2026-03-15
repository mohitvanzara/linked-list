/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* createNode(int val){
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
 }
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* t1 = l1;
    struct ListNode* t2 = l2;
    struct ListNode* dummyNode = createNode(-1);
    int carry =0;
    struct ListNode* curr = dummyNode;

    while(t1!= NULL || t2!= NULL){
        int sum = carry;
        if(t1){
            sum+=t1->val;

        }
        if(t2){
            sum+=t2->val;
        }
        struct ListNode* NewNode = createNode(sum%10);
        carry = sum/10;
        curr->next = NewNode;
        curr = curr->next;
        if(t1){
            t1 = t1->next;
        }
        if(t2){
            t2 = t2->next;
        }
        if(carry){
            struct ListNode* NewNode = createNode(carry);
            curr->next = NewNode;
        }
    }
    return dummyNode->next;
    
}