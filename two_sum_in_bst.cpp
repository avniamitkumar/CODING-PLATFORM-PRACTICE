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
class BSTiterator
{
    public:
    stack<TreeNode*>myleft;
    stack<TreeNode*>myright;
    BSTiterator(TreeNode *root)
    {
        pushAll_l(root);
        pushAll_r(root);
    }
    void pushAll_l(TreeNode* t)
    {
        
        for(;t!=NULL;myleft.push(t),t=t->left);
    }
     void pushAll_r(TreeNode* t)
    {
        
        for(;t!=NULL;myright.push(t),t=t->right);
    }
    int next()
    {
        TreeNode *temp=myleft.top();
        myleft.pop();
        pushAll_l(temp->right);
        return temp->val;
    }
    int prev()
    {
        TreeNode *temp=myright.top();
        myright.pop();
        pushAll_r(temp->left);
        return temp->val;
    }
}
;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator first(root);
        BSTiterator second(root);
        int a=first.next();
        int b=second.prev();
        while(a<b)
        {
            if(a+b<k)
            {
                a=first.next();

            }else if(a+b>k)
            {
                b=second.prev();
            }
            else 
            {
                return true;
            }
        }
        return false;
    }

};