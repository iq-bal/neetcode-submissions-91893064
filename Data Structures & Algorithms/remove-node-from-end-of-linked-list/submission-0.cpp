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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next)
            return nullptr;
        
        ListNode* curr = head;
        int num = 0;
        while(curr){
            num++;
            curr = curr->next;
        }
        curr = head;
        int curr_node = 0;
        if(curr_node == num-n){
            return head->next; 
        }
        while(curr){
            curr_node++;
            if(curr_node == num-n){
                curr->next = (curr->next)->next;
            }
            curr = curr->next; 
        }
        return head;
    }
};
