


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<double ,vector<int>>>pq;
        int x,y;
        double dist;
       for(auto point:points){
             x=point[0];
             y=point[1];
             dist=sqrt(pow(x,2) + pow(y,2));
             pq.push({dist,{x,y}});
             if(pq.size()>k)pq.pop();
       } 
       vector<vector<int>>ans;
       while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
       }
       return ans;
    }
};