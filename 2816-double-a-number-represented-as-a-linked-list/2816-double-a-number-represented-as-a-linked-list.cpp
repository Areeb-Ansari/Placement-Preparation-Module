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
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            int dig = curr->val * 2;
            if(dig < 10){
                curr->val = dig;
            }
            else{
                curr->val = dig%10;
                if(prev == NULL){
                    ListNode* newnode = new ListNode(1);
                    head = newnode;
                    head->next = curr;
                }
                else{
                    prev->val += 1;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
        // string n = ""; // not working
        // ListNode* temp = head;
        // while(temp->next != NULL){
        //     // n = n*10 + head->val;
        //     n = to_string(temp->val) + n;
        //     temp = temp->next;
        // }
        // ListNode* nxt = NULL;
        // ListNode* curr;
        // for(int i=n.size()-1; i>=0; i--){
        //     int dig = n[i] - '0';
        //     ListNode* curr = new ListNode(dig);
        //     curr->next = nxt;
        //     nxt = curr;
        // }
        // // while(n.size()){
        // //     int s = n.size();
        // //     int dig = n;
        // //     n /= 10;
        // //     ListNode* curr = new ListNode(dig);
        // //     curr->next = nxt;
        // //     nxt = curr;
        // // }
        // return curr;
    }
};