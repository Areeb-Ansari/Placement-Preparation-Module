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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* slow = list1;
        ListNode* fast = list1;
        for(int i=0; i<a-1; i++) slow = slow->next;
        for(int i=0; i<=b; i++) fast = fast->next;

        ListNode* temp  = list2;
        while(temp->next != NULL){
            temp = temp->next;
        }

        slow->next = NULL;
        slow->next = list2;
        temp->next = fast;
        return list1;
    }
};