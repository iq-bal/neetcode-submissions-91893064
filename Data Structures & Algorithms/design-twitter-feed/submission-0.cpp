class Twitter {
public:
    int timestamp = 0;
    priority_queue<vector<int>>posts;
    map<int,vector<int>>following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push(vector<int>{timestamp,userId,tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<vector<int>>temp; 
        vector<int>tweets; 
        int count = 0; 
        while(!posts.empty()){
            auto v = posts.top();
            posts.pop();

            auto& followeeList = following[userId];

            int user = v[1];
            int tweetId = v[2];

            if(userId == user || find(followeeList.begin(), followeeList.end(), user) != followeeList.end())
                tweets.push_back(tweetId);

            temp.push_back(v);

            if(tweets.size() == 10)
                break;
        }
        for(auto& v : temp)
            posts.push(v);
        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto& v = following[followerId];
        v.erase(remove(v.begin(), v.end(), followeeId), v.end());
    }
};
