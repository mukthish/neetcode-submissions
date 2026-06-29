class Twitter {
    int timeStamp;
    vector<vector<pair<int, int>>> userTweets = vector<vector<pair<int, int>>>(101);
    vector<vector<int>> following = vector<vector<int>>(101, vector<int>(101));
public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 1; i <= 100; i++) {
            if (following[userId][i] == 1 or i == userId) {
                for (auto& t : userTweets[i]) {
                    pq.push(t);
                    if (pq.size() > 10) {
                        pq.pop();
                    }
                }
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId][followeeId] = 0;
    }
};
