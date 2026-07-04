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
    int maxPathSum(TreeNode* root) {
        int result=root->val;
        dfs(root,result);
        return result;
    }
    int dfs(TreeNode* root,int& result)
    {
        if(!root)
        {
            return 0;
        }
        int left=max(dfs(root->left,result),0);
        int right=max(dfs(root->right,result),0);
        result=max(result,root->val+left+right);
        return root->val+max(left,right);
    }
};