class Twitter {
public:
   
    int time = 0;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
       follows[userId].insert(userId);
       tweets[userId].push_back({time++, tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
       priority_queue<pair<int, int>> pq;

       for(auto f : follows[userId]){
        for(auto &t : tweets[f]){
            pq.push(t);
        }
       }

       vector<int> res;

       while(!pq.empty() && res.size() < 10){
        res.push_back(pq.top().second);
        pq.pop();
       }

       return res;
    }
    
    void follow(int followerId, int followeeId) {
       follows[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
       if(followerId != followeeId)
        follows[followerId].erase(followeeId);
    }
};

