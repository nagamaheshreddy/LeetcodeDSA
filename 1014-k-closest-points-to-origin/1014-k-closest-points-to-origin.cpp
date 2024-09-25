class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<double ,pair<int,int>>>pq;
        int x,y;
        double dist;
       for(auto point:points){
             x=point[0];
             y=point[1];
             dist=sqrt(pow(x,2) + pow(y,2));
             cout<<dist<<" , ";
            pq.push({dist,{x,y}});
            if(pq.size()>k)pq.pop();
       } 
       vector<vector<int>>ans;
       vector<int>temp;
       while(!pq.empty()){
        x= pq.top().second.first;
        y=pq.top().second.second;
        temp={x,y};
        ans.push_back(temp);
        temp.clear();
        pq.pop();
       }
       return ans;
    }
};