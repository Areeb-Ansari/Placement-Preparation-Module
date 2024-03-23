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
private:
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool oddeven(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len%2;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* mid = findmid(head);
        mid->next = reverse(mid->next);
        bool oe = oddeven(head);
        ListNode* head1 = head;
        ListNode* fhead1 = head->next;
        ListNode* head2 = mid->next;
        ListNode* fhead2 = head2->next;

        while(head2 != NULL){
            if(fhead2 == NULL){
                if(oe){
                    head1->next = head2;
                    head2->next = fhead1;
                    fhead1->next = NULL;
                    head2 = NULL;
                }
                else{
                    head1->next = head2;
                    head2->next = NULL;
                    head2 = NULL;
                }
            }
            else{
                head1->next = head2;
                head2->next = fhead1;
                head1 = fhead1;
                fhead1 = fhead1->next;
                head2 = fhead2;
                fhead2 = fhead2->next;
            }
        }
    }
};