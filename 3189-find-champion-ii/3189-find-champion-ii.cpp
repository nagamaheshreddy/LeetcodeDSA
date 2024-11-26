class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        int count=0,ans=-1;

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(adj[i].size()==0){
                count++;
                ans=i;
            }
        }

        return count==1? ans:-1;
    }
};