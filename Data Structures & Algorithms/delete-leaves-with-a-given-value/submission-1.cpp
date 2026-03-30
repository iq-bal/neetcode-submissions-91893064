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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* head = solution(root,target);
        if(!head->left && !head->right && head->val == target)
            return nullptr;
        return head;
    }
    TreeNode* solution(TreeNode* &root,int target){
        if(!root)
            return nullptr;
        
        TreeNode* left = solution(root->left,target);
        TreeNode* right = solution(root->right,target);

        if(left && !left->left && !left->right && left->val == target)
            root->left = nullptr;
        if(right && !right->left && !right->left && right->val == target)
            root->right = nullptr;
        
        return root; 
    }
};