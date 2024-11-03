
#define ppi pair<int,int>

class Twitter {
public:

    int time;
    unordered_map<int,set<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>follows;

    Twitter() {
        time=0;    
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert({time,tweetId});
        time++;
        follows[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;

        for(int id:follows[userId]){

            for(auto pair:tweets[id]){
                pq.push(pair);
                if(pq.size()>10){
                    pq.pop();
                }
            }
        }

        vector<int>feed;
        while(!pq.empty()){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(),feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */