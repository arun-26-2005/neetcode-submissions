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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> a;
        inorder(root,a);int b;
        return a[k-1];
    }
    void inorder(TreeNode* root,vector<int> &a)
    {
        if(root!=NULL)
        {
            inorder(root->left,a);
            a.push_back(root->val);
            inorder(root->right,a);
        }
    }
};