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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = head->next;

        while(even != NULL){ //even will point to NULL in both cases
            if(even->next != NULL){
                odd->next = even->next;
                odd = odd->next; // want odd at the end of odd LL not NULL
            } 
            if(even->next != NULL){
                even->next = even->next->next;
            } 
            even = even->next; // even will point to NULL in both cases and thats what we want
        }
        odd->next = temp;
        return head;
    }
};