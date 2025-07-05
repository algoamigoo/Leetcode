class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> m;
        for (auto it : arr)
            m[it]++;
        int ans = -1;
        for (auto i = m.begin(); i != m.end(); i++) {
            if (i->second == i->first)
                ans = max(ans, i->first);
        }
        return ans;
    }
};