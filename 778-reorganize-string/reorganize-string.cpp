class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;
        for (char c : s)
            m[c]++;

        int sum = s.size(), mx = 0;
        for (auto it : m)
        mx = max(mx, it.second);

        if (mx > (sum + 1) / 2)
            return "";

        priority_queue<pair<int, char>> q;
        for (auto it : m)
        q.push({it.second, it.first});

        string ans = "";
        pair<int, char> prev = {0, '#'}; 

        
        while (!q.empty()) {
            auto [freq, ch] = q.top();
            q.pop();

            ans += ch;

            if (prev.first > 0)
            q.push(prev);

            prev = {freq - 1, ch};
        }

        return ans;
    }
};
