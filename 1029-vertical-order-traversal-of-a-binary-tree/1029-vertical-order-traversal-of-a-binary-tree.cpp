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
    
    
   /* void dfs(TreeNode* root,int col){
        if(root==NULL)return ;;
        
        
        mp[col].push_back(root->val);
        dfs(root->left,col-1);
        dfs(root->right,col+1);
    }*/
    
    
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.second<b.second)return true;
        if(a.second==b.second)return a.first<=b.first;
        return false;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //dfs(root,0);
        map<int,vector<pair<int,int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        TreeNode* curr;
        int n,col,row;
        
        while(!q.empty()){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                curr=q.front().first;
                col=q.front().second.first;
                row=q.front().second.second;
                q.pop();
                
                mp[col].push_back({curr->val,row});
                
                if(curr->left)q.push({curr->left,{col-1,row+1}});
                if(curr->right)q.push({curr->right,{col+1,row+1}});
                
            }
        }
        
        
        vector<vector<int>>ans;
        vector<pair<int,int>>temp;
        for(auto pair:mp){
            temp=pair.second;
            sort(temp.begin(),temp.end(),comp);
            vector<int>v;
            
            for(auto pair:temp)v.push_back(pair.first);
            ans.push_back(v);
        }
        
        return ans;
    }
};