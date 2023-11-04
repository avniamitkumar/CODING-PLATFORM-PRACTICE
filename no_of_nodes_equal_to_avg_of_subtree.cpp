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
   int ans=0;
   int sumsub(TreeNode*root ,int &n)
   {
       if(!root)return 0;
       else
       {
           n++;
       }
       return root->val+sumsub(root->left,n)+sumsub(root->right,n);
   }

   int helper(TreeNode *root)
   {
       int c=0;
       int sum=sumsub(root,c);
       if(sum/c==root->val)return 1;
       return 0;
   }

    int averageOfSubtree(TreeNode* root) {
        if(!root)return 0;
        if(helper(root)==1)
        {
            ans+=1;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return ans;



    }
};