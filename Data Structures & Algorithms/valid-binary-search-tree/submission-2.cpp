class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode* root, long low, long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high)
            return false;

        return valid(root->left, low, root->val) &&
               valid(root->right, root->val, high);
    }
};