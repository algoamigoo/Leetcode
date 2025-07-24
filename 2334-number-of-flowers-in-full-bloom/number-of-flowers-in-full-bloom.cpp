class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        vector<int> starts, ends;
        
        for (auto& f : flowers) {
            starts.push_back(f[0]);
            ends.push_back(f[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        for (int t : people) {
            int bloomed = upper_bound(starts.begin(), starts.end(), t) - starts.begin();
            int died = lower_bound(ends.begin(), ends.end(), t) - ends.begin();
            ans.push_back(bloomed - died);
        }
        
        return ans;
    }
};
