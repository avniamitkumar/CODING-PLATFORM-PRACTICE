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
class NodeValue
{
    public:
    int minval,maxval,maxsize;
    NodeValue(int minval,int maxval,int maxsize)
    {
        this->minval=minval;
        this->maxval=maxval;
        this->maxsize=maxsize;
    }
};



class Solution {
public:
    int ans=INT_MIN;
    NodeValue helper(TreeNode*root)
    {
        if(!root)
        {
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        auto left=helper(root->left);
        auto right=helper(root->right);

        if(left.maxval<root->val && right.minval>root->val )
        {
            ans=max(ans,left.maxsize+right.maxsize+root->val);
            return NodeValue(min(root->val,left.minval),max(right.maxval,root->val),right.maxsize+left.maxsize+root->val);
        }
         ans=max(ans,max(right.maxsize,left.maxsize));
         return NodeValue(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
    }



    int maxSumBST(TreeNode* root) {
        helper(root);
        	return ans<0?0:ans;
    }
};