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
    string dfs(TreeNode* root){
        if(root==nullptr)return "()";

        string left=dfs(root->left);
        string right=dfs(root->right);

        return "("+to_string(root->val)+left+right+")";
    }

    bool isSubstr(string a,string b){
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j==b.size();
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr)return true;
        if(root==nullptr)return false;

        string a=dfs(root);
        string b=dfs(subRoot);

        if(a.find(b)!=string::npos)return true;
        return false;
        // return isSubstr(a,b);
        
    }
};