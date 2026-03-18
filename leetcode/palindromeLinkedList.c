 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* reverseLinkedList(struct ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        struct ListNode* newHead = reverseLinkedList(head->next);
        struct ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(struct ListNode* head) {
        //step 1
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        //totois algo
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //step 2
        struct ListNode* newHead = reverseLinkedList(slow->next);
        //step 3
        struct ListNode* first = head;
        struct ListNode* second = newHead;
        while(second!=NULL){
            if(first->val != second->val){
                reverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newHead);
        return true;


        
    }