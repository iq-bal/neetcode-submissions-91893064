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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int>ans;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n-1; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            TreeNode* rightmost = q.front();
            q.pop();

            ans.push_back(rightmost->val);

            if(rightmost->left)
                q.push(rightmost->left);
            if(rightmost->right)
                q.push(rightmost->right);
        }
        return ans;
    }
};
