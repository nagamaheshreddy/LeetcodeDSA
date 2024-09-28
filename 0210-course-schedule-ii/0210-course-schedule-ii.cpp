class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<int>adj[n];

        for(auto course:prereq){
            int u=course[0];
            int v=course[1];
            adj[v].push_back(u);
        }
        vector<int>inorder(n,0);
        for(int i=0;i<n;i++){
            for(auto course:adj[i]){
                inorder[course]++;
            }
        }
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto child:adj[node]){
                inorder[child]--;
                if(inorder[child]==0)q.push(child);
            }
        }
        if(topo.size()==n)return topo;
        return {};
    }
};