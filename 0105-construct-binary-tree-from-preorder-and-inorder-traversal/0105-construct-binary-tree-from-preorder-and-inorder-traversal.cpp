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
    TreeNode* helper(int &index,int left,int right,vector<int>&preorder,vector<int>&inorder,unordered_map<int,int>&mp){
        if(left>right)return nullptr;
        
        TreeNode* root=new TreeNode(preorder[index]);
        int pos=mp[preorder[index]];

        index++;
        root->left=helper(index,left,pos-1,preorder,inorder,mp);
        root->right=helper(index,pos+1,right,preorder,inorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int index=0;
        return helper(index,0,inorder.size()-1,preorder,inorder,mp);
    }
};