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
    // ListNode* findMiddle(ListNode* head){
    //     ListNode* slow = head;
    //     ListNode* fast = head->next;
        
    //     while(fast != NULL && fast->next != NULL){
    //         fast = fast->next->next;
    //         slow = slow->next;
    //     }
    //     return slow;
    // }
    
    // ListNode* reverse(ListNode* head){
    //     ListNode* curr = head;
        
    //     ListNode* prev = NULL;
        
    //     while(curr != NULL){
    //         ListNode* forward = curr->next;
            
    //         curr->next = prev;
    //         prev = curr;
    //         curr = forward;
    //     }
    //     return prev;
    // }

    ListNode* listmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        
        /*
        METHOD - 1
        vector<int> arr;
        ListNode* temp = head;
        
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        int l=0;
        int h=arr.size()-1;
        
        while(l<h){
            if(arr[l] != arr[h]){
                return false;
            }
            h--;
            l++;
        }
        return true;
        */
        
        //METHOD - 2
        // if(head == NULL || head->next == NULL)
        //     return true;
        
        // //finding mid
        // ListNode* middle = findMiddle(head);
        
        // //reversing the second half
        // middle->next = reverse(middle->next);
        
        // //comparing one by one
        // ListNode* head1 = head;
        // ListNode* head2 = middle->next;
        
        // while(head2 != NULL){
        //     if(head1->val != head2->val)
        //         return false;
        //     head1 = head1->next;
        //     head2 = head2->next;
        // }
        // //reversing second half again so the LL remains intact
        // middle->next = reverse(middle->next);
        // return true;

        //Attempt 2
        if(head == NULL || head->next == NULL) return true;
        ListNode* mid = listmiddle(head);
        mid->next = reverse(mid->next);

        ListNode* head1 = head;
        ListNode* head2 = mid->next;

        while(head2 != NULL){
            if(head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        mid->next = reverse(mid->next);
        return true;
    }
};