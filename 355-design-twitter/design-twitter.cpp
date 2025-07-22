// tweetid,userid  ------> pair<int,pair<tweetid,userid>>
class Twitter {
public:
    
    vector<pair<int,int>> q; // userID,tweetID
    unordered_map<int, set<int>> following; // changed from vector to unordered_map
    
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        q.push_back({userId, tweetId});
        // Optional: Limit q size to 1000 to prevent unbounded growth
        if (q.size() > 1000) {
            q.erase(q.begin());
        }
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int count = 0;
        // Iterate from most recent tweet backwards
        for (int i = q.size() - 1; i >= 0 && count < 10; i--) {
            int user = q[i].first;
            int tweetId = q[i].second;
            // Optimization: Early exit if user has no followees and tweet isn't theirs
            if (user != userId && following[userId].empty()) continue;
            if (user == userId || following[userId].find(user) != following[userId].end()) {
                ans.push_back(tweetId);
                count++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);  // who he is following
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId); // who he is following
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
