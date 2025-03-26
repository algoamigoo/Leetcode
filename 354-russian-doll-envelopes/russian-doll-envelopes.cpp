class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1]; 
        }
        return a[0] < b[0]; 
    }

    int lengthOfLIS(vector<int>& arr) {
        vector<int> lis;
        for (int x : arr) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) {
                lis.push_back(x);
            } else {
                *it = x;
            }
        }
        return lis.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> heights;
        for (auto &env : envelopes) {
            heights.push_back(env[1]);
        }
        
        return lengthOfLIS(heights);
    }
};
