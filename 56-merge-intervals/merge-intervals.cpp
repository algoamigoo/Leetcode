class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0]) {
                // Overlapping intervals, so merge
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                // No overlap, add the interval
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
