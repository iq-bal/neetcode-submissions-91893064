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
    int cnt = 0;
    int goodNodes(TreeNode* root) {
        traverse(root,root->val);
        return cnt;
    }
    void traverse(TreeNode* root, int so_far_largest){
        if(!root)
            return;
        if(root->val>=so_far_largest)
            cnt++;
        traverse(root->left,max(root->val,so_far_largest));
        traverse(root->right,max(root->val,so_far_largest));
    }
};
