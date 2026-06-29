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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
       if(caller(root,subRoot))
       {return true;}
      
       
       return false;
        


    }
    bool caller(TreeNode* root,TreeNode *subroot)
    {
       if(!subroot)
       {
        return true;
       }
       if(!root)
       {
        return false;
       }
       if(sameTree(root,subroot))
       {
        return true;
       }
       return caller(root->left,subroot) || caller(root->right,subroot);
    }

    bool sameTree(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        if(root1==NULL || root2==NULL)
        {
            return false;
        }
        return root1->val==root2->val && sameTree(root1->left,root2->left) && sameTree(root1->right,root2->right);
    }
};
