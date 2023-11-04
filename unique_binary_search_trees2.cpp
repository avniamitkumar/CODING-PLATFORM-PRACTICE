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

    vector<TreeNode*> gen(int size,int st,int end)
    {
        if(size==0)
        {
            return {NULL};
        }
        if(size==1)
        {
            TreeNode* temp=new TreeNode(st);
            return {temp};
        }
        vector<TreeNode*>ans;
        for(int i=st;i<=end;i++)
        {
            vector<TreeNode*> left=gen(i-st,st,i-1);
            vector<TreeNode*>right=gen(end-i,i+1,end);
            for(int j=0;j<left.size();j++)
            {
                for(int k=0;k<right.size();k++)
                {
                    TreeNode*temp=new TreeNode(i);
                    temp->left=left[j];
                    temp->right=right[k];
                    ans.push_back(temp);
                }
            }

        }
        return ans;
    }


    vector<TreeNode*> generateTrees(int n) {
        return gen(n,1,n);
    }
};