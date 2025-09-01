class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        int n = classes.size();

        priority_queue<pair<double, pair<int,int>>> pq;

        auto gain = [](int p, int t) {
            return (double)(p+1)/(t+1) - (double)p/t;
        };

        for (int i=0; i<n; i++) {
            int p = classes[i][0], t = classes[i][1];
            pq.push({gain(p,t), {p,t}});
        }

        while (extra--) {
            auto top = pq.top(); pq.pop();
            int p = top.second.first;
            int t = top.second.second;
            p++; t++;
            pq.push({gain(p,t), {p,t}});
        }

        double sum = 0;
        while (!pq.empty()) {
            auto [g, pr] = pq.top(); pq.pop();
            sum += (double)pr.first / pr.second;
        }
        return sum / n;
    }
};
