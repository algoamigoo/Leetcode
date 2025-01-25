class Solution {
public:
    vector<int> parent;
    vector<int> rank;

int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
}

void Union(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
}
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        parent[i] = i;  
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) 
        v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        for (int i = 0; i < n - 1; i++) {
            if (v[i+1].first - v[i].first <= limit) {
                Union(v[i].second, v[i + 1].second);
            }
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) 
        groups[find(i)].push_back(i);

        vector<int> result(n);
        for (auto& [_, indices] : groups) {
            vector<int> values;
            for (int idx : indices) values.push_back(nums[idx]);
            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());
            for (int i = 0; i < indices.size(); i++) result[indices[i]] = values[i];
        }

        return result;

    }
};