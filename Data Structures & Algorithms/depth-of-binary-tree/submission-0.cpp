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
    int maxDepth(TreeNode* root) {
        int maxcount=0;
        if(root!=NULL)
        {
            depth(root,maxcount,0);
            return maxcount;
        }
        return 0;
    }

    void depth(TreeNode* root,int &maxcount,int count)
    {
        if(root!=NULL)
        {
            count+=1;
            maxcount=max(count,maxcount);
            depth(root->left,maxcount,count);
            depth(root->right,maxcount,count);
        }

    }
};