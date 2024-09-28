class Solution {
public:
    int parent[1001];
    int size[1001];

    void make(int v){
        parent[v]=v;
        size[v]=1;
    }

    int find(int v){
        if(v==parent[v])return v;
        return parent[v]=find(parent[v]);
    }

    void Union(int a,int b){
        a=find(a);
        b=find(b);

        if(a!=b){
            if(size[a]<size[b]){
                parent[a]=b;
                size[b]+=size[a];
            }else{
                parent[b]=a;
                size[a]+=size[b];
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        for(int i=0;i<n;i++){
            make(i);
        }
        vector<int>ans;

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(find(u)==find(v))ans=edge;
            Union(u,v);
        }
        return ans;

    }
};