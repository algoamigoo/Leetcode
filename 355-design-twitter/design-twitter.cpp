class Twitter {
public:
    // who follows whom
    unordered_map<int, unordered_set<int>> following;

    // userId → list of {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0; // global timestamp counter

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // Use a max-heap to get most recent tweets
        priority_queue<pair<int, pair<int, int>>> pq;

        // Make sure user follows themselves
        following[userId].insert(userId);

        // For all users this user follows, push their most recent tweet (if any)
        for (int followeeId : following[userId]) {
            auto& tw = tweets[followeeId];
            if (!tw.empty()) {
                int idx = tw.size() - 1; // index of most recent tweet
                pq.push({tw[idx].first, {followeeId, idx}});
            }
        }

        vector<int> ans;

        // Fetch top 10 tweets from the heap
        while (!pq.empty() && ans.size() < 10) {
            auto [curTime, p] = pq.top(); pq.pop();
            int uid = p.first;
            int idx = p.second;

            ans.push_back(tweets[uid][idx].second); // tweetId

            // Push the previous tweet from same user, if it exists
            if (idx > 0) {
                pq.push({tweets[uid][idx - 1].first, {uid, idx - 1}});
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};
