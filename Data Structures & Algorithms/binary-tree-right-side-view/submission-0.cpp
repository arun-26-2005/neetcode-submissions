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
        vector<int> result;
        if(!root)
        {
            return result;
        }  
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int last_in_level;
            bool flag=false;
            int size=q.size();
            for(int i=q.size();i>0;i--)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node)
                {
                    last_in_level=node->val;
                    flag=true;
                    q.push(node->left);
                    q.push(node->right);
                }

            }

            if(flag)
            {
                result.push_back(last_in_level);
            }

        }      
        return result;

    }
};
