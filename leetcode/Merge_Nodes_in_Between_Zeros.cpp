/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* traveling = head->next;
        ListNode* stay = head;
        int sum = 0;
        while(traveling!=NULL){

            if(traveling->val == 0){
                
                stay->val = sum;
                stay->next = traveling->next;
                stay = stay->next;
                sum =0;
            }  
            else{
                sum+= traveling->val;
            }
           traveling = traveling->next;
        }
        

         return head;
    }
};