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
    int dfs(TreeNode* root,int &ans){
        if(root==nullptr)return 0;

        int left=dfs(root->left,ans);
        int right=dfs(root->right,ans);

        ans=max(ans,root->val);
        ans=max(ans,root->val+max(left,right));
        ans=max(ans,root->val+left+right);

        return max(root->val,root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
};