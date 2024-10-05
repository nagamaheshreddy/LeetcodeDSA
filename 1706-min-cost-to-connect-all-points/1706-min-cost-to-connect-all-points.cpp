class Solution {
public:
    int parent[1001];
    int size[1001];

    void make(int v){
        parent[v]=v;
        return;
    }
    int findParent(int v){
        if(parent[v]==v)return v;
        return parent[v]=findParent(parent[v]);
    }

    void Union(int a,int b){
        a=findParent(a);
        b=findParent(b);

        if(a!=b){
            if(size[a]<size[b]){
                parent[a]=b;
                size[b]+=a;
            }else{
                parent[b]=a;
                size[a]+=b;
            }
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        for(int i=0;i<n;i++)make(i);

        vector<pair<int,pair<int,int>>>adj;

        int x1,x2,y1,y2,weight;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                x1=points[i][0];
                y1=points[i][1];
                x2=points[j][0];
                y2=points[j][1];

                weight=abs(x1-x2)+abs(y1-y2);

                adj.push_back({weight,{i,j}});
            }
        }

        sort(adj.begin(),adj.end());

        int u,v,d,a,b,sum=0;
        for(auto &pair:adj){
            d=pair.first;
            u=pair.second.first;
            v=pair.second.second;

            a=findParent(u);
            b=findParent(v);

            if(a!=b){
                sum+=d;
                Union(a,b);
            }
        }

        return sum;    
    }
};