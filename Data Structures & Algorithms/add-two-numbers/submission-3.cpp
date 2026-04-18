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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; 
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            tail->next = new ListNode(sum%10);
            carry = sum / 10;
            tail = tail->next; 
            l1 = l1->next; 
            l2 = l2->next;
        }
        if(l1){
            while(l1){
                int sum = l1->val + carry;
                tail->next = new ListNode(sum%10);
                carry = sum / 10;
                tail = tail->next; 
                l1 = l1->next;
            }
        }
        if(l2){
            while(l2){
                int sum = l2->val + carry;
                tail->next = new ListNode(sum%10);
                carry = sum / 10;
                tail = tail->next; 
                l2 = l2->next;
            }
        }
        if(carry==1){
            tail->next = new ListNode(1);
        }
        return dummy.next;
    }
};
