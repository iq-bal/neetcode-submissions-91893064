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
    int ans = 0; 
    int diameterOfBinaryTree(TreeNode* root) {
        int height = getHeight(root);
        return ans; 
    }
    int getHeight(TreeNode* root){
        if(!root)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        ans = max(ans, left + right);
        return max(left,right)+1;
    }
};
