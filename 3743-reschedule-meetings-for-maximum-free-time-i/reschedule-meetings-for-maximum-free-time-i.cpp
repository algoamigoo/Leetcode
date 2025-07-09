class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<pair<int, int>> meetings(n);
        for(int i = 0; i < n; i++) {
            meetings[i] = {startTime[i], endTime[i]};
        }
        
        vector<int> gaps;
        if(meetings[0].first > 0) {
            gaps.push_back(meetings[0].first);
        }
        for(int i = 1; i < n; i++) {
            gaps.push_back(meetings[i].first - meetings[i-1].second);
        }
        if(meetings[n-1].second < eventTime) {
            gaps.push_back(eventTime - meetings[n-1].second);
        }
        
        if(k == 0 || gaps.empty()) {
            return gaps.empty() ? 0 : *max_element(gaps.begin(), gaps.end());
        }
        
        int maxGap = *max_element(gaps.begin(), gaps.end());
        
        vector<int> presum(gaps.size() + 1, 0);
        for(int i = 0; i < gaps.size(); i++) {
            presum[i + 1] = presum[i] + gaps[i];
        }
        
        for(int i = min(k + 1, (int)gaps.size()); i < presum.size(); i++) {
            maxGap = max(maxGap, presum[i] - presum[i - min(k + 1, i)]);
        }
        
        return maxGap;
    }
};