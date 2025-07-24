class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int, int>> events, pre;
        int n = flowers.size();

        // Create start and end+1 events
        for (auto& f : flowers) {
            events.push_back({f[0], 1});      // flower starts
            events.push_back({f[1] + 1, -1}); // flower ends after f[1]
        }

        // Sort events by time
        sort(events.begin(), events.end());

        // Build prefix sums of active flowers
        int bloom = 0;
        for (auto& e : events) {
            bloom += e.second;
            pre.push_back({e.first, bloom});
        }

        // Answer each query using upper_bound
        vector<int> ans;
        for (int t : people) {
            auto it = upper_bound(pre.begin(), pre.end(), make_pair(t, INT_MAX));
            if (it == pre.begin()) ans.push_back(0);
            else ans.push_back((--it)->second);
        }

        return ans;
    }
};
