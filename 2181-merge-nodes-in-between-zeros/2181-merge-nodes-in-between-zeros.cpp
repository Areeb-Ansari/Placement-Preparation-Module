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
        ListNode* prev = head;
        ListNode* curr = head->next;
        int currsum = 0;

        while(curr != NULL){
            if(curr->val){
                currsum += curr->val;
            }
            else{
                prev->val = currsum;
                currsum = 0;
                if(curr->next != NULL){
                    prev = prev->next;
                }   
            }
            curr = curr->next;
        }
        prev->next = NULL;
        return head;
    }
};