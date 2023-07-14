class Solution {
public:
    unordered_set<int> ele;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;  // if we are at next to leaf node
        if(ele.find(k-root->val)!=ele.end()) return true;  // if we found the required element in set
        ele.insert(root->val); // insert root to set
        return findTarget(root->left,k)|| findTarget(root->right,k); // recursive call for ledt and right sub trees
    }
};