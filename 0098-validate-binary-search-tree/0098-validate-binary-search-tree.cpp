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
    bool dfs(TreeNode * root,long long  mini,long long maxi){
        if(root==nullptr)return true;

        if(root->val<=mini || root->val>=maxi)return false;

        bool left=dfs(root->left,mini,root->val);
        bool right=dfs(root->right,root->val,maxi);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        long long  mini=LLONG_MIN;
        long long maxi=LLONG_MAX;
        return dfs(root,mini,maxi);
    }
};