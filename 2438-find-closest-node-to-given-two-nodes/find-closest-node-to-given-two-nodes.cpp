class Solution {
public:
    void walk(vector<int>& edges, int start, vector<int>& dist) {
        int d = 0;
        int curr = start;
        while (curr != -1 && dist[curr] == -1) {
            dist[curr] = d++;
            curr = edges[curr];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1(n, -1), d2(n, -1);
        
        walk(edges, node1, d1);
        walk(edges, node2, d2);

        int ans = -1;
        int best = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (d1[i] != -1 && d2[i] != -1) {
                int mx = max(d1[i], d2[i]);
                if (mx < best) {
                    best = mx;
                    ans = i;
                }
            }
        }

        return ans;
    }
};
