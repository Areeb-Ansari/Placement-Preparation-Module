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
    int pairSum(ListNode* head) {
        if(head->next->next == NULL) return head->val + head->next->val;

        int maxsum = 0;
        int currsum = 0;

        // find mid
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;

        //rev after mid
        ListNode* prev = NULL;
        ListNode* curr = temp;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        slow->next = prev;

        //comparing twins
        while(prev != NULL){
            currsum = head->val + prev->val;
            maxsum = max(maxsum, currsum);
            head = head->next;
            prev = prev->next;
        }

        return maxsum;

    }
};