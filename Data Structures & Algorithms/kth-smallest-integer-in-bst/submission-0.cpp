/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        int curr = 1;
        int ans = 0; 
        while(!pq.empty()){
            if(curr==k){
                ans = pq.top();
                break;
            }   
            curr++;
            pq.pop();
        }
        return ans; 
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        pq.push(root->val);
        inorder(root->left);
        inorder(root->right);
    }
};
