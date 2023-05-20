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
     vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        vector<int>temp;
        if(root==NULL)return vec;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
           
            if(q.front()!=NULL) {
                 TreeNode* k = q.front();
            q.pop();
            temp.push_back(k->val);
            if(k->left)
                q.push(k->left);
            if(k->right)
                q.push(k->right);
            } 
            else {
                vec.push_back(temp);
              q.pop();
            // if(q.front()==NULL) return vec;
                q.push(NULL);
                if(q.front()==NULL) return vec;
                temp.clear();
            }
        }
        return vec;
    }
};