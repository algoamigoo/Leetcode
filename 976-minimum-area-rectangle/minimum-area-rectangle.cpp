class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> m;
        for (auto& point : points)
            m[point[0]].insert(point[1]);
        
        int min_area = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                if (x1 != x2 && y1 != y2)
                    if (m[x1].count(y2) && m[x2].count(y1))
                        min_area = min(min_area, abs(x1 - x2) * abs(y1 - y2));
            }
        }
        return min_area != INT_MAX ? min_area : 0;
    }
};