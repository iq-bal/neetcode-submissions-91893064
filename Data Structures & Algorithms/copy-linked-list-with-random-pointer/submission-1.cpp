/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        
        vector<Node*>v;
        map<Node*,Node*>m;
        Node* curr = head;
        while(curr){
            Node* node = new Node(curr->val);
            v.push_back(node);
            m[curr]=node;
            curr = curr->next;
        }
        while(head){
            Node* node = m[head];
            node->next = m[head->next];
            node->random = m[head->random];
            head = head->next;
        }
        return v[0];
    }
};
