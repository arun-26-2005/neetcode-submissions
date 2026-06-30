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
    int target=0;
    int kthSmallest(TreeNode* root, int k) {
       
        inorder(root,k);
        return target;
       
    }
    void inorder(TreeNode* root,int &k)
    {
        if(root==NULL)
        {
            return;
        }
            inorder(root->left,k);
            k--;
            if(k==0)
            {
                target=root->val;
                return ;
            }
            inorder(root->right,k);
        }
       
    
};