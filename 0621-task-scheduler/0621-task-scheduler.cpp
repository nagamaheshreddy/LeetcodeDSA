#define ppi pair<int,int>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        for(char ch:tasks){
            mp[ch]++;
        }
        
        for(auto pair:mp){
            pq.push({pair.second,pair.first});
        }
        queue<pair<int,char>>q;
        int time=0;

        while(!pq.empty() || !q.empty()){
            time+=1;

            if(!pq.empty()){
                mp[pq.top().second]--;
                if(mp[pq.top().second]>0){
                    q.push({time+n,pq.top().second});
                }
                pq.pop();
            }

            while(!q.empty() && q.front().first<=time){
                pq.push({mp[q.front().second],q.front().second});
                q.pop();
            }

        }

        return time;
    }
};