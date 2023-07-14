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
    bool valid(TreeNode*root ,long long int leftrange, long long int rightrange)
    {
        if(!root)return true;
        if(root->val<=leftrange || root->val>=rightrange)return false;
        return valid(root->left,leftrange,root->val ) && valid(root->right,root->val,rightrange);
    }


    bool isValidBST(TreeNode* root) {
        long long int a=-2147483649;;
        long long int b=2147483649;;
        return valid(root,a,b);
    }
};