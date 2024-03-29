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
    void solve(TreeNode* root,int target,int sum,vector<int>path,vector<vector<int>>&ans)
    {
       
        if(!root)
        {
            return;
        }
         path.push_back(root->val);
        if(!root->left && !root->right)
        {
            sum+=root->val;
            if(sum==target)
            {
                 
                ans.push_back(path);
                 path.pop_back();
            }
            return;
            
        }
        solve(root->left,target,sum+root->val,path,ans);
        solve(root->right,target,sum+root->val,path,ans);
        path.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>path;
        solve(root,targetSum,0,path,ans);
        return ans;
    }
};