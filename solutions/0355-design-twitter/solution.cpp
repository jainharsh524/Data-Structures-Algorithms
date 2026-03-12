class Twitter {
private:
    unordered_map<int, unordered_set<int>> followReq;
    unordered_map<int, vector<pair<int,int>>> userTweets;
    int timer;

    void insertInHeap (int user, priority_queue<pair< int, pair<int,int>> > &pq) {
        vector<pair<int,int>> tweets = userTweets[user];
        if (tweets.empty()) return;
        int timer = tweets.back().first;
        pq.push({timer, {tweets.size() - 1, user}});
    }

public:
    Twitter() { timer = 0; }
    
    void postTweet(int userId, int tweetId) {
        timer++;
        userTweets[userId].push_back({timer, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair< int, pair<int,int>> > pq; // {timer, {index, userId}}
        insertInHeap(userId, pq);
        for (int follower: followReq[userId]) {
            insertInHeap(follower, pq);
        }
        int counter = 0;
        vector<int> ans;
        while (!pq.empty() && counter < 10) {
            auto top = pq.top(); pq.pop();
            int idx = top.second.first;
            int user = top.second.second;
            vector<pair<int,int>> tweetList = userTweets[user];
            pair<int,int> curTweet = tweetList[idx];
            int tweetId = curTweet.second;
            ans.push_back(tweetId);

            // next element calculation
            idx--;
            if (idx>= 0) {
                pair<int,int> nxtTweet = tweetList[idx];
                int nextTimer = nxtTweet.first;
                pq.push({nextTimer, {idx, user}});
            }
            counter++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followReq[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followReq[followerId].find(followeeId) == followReq[followerId].end()) return;
        followReq[followerId].erase(followeeId);
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
