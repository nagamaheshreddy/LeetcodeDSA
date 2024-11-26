class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>topo;

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(adj[i].size()==0)topo.push_back(i);
        }

        return topo.size()==1? topo.front():-1;
    }
};